//Programa : ILuminacao e irrigacao frente casa 04/01/2016;
//Autor : Leonardo Silva
//Carrega a biblioteca do RTC DS1307

#include <DS1307.h>

DS1307 rtc(A4, A5);

//porta digitais que sao usadas pra acionar os modulo rele, no pino 7 e 8, que sao responsaveis pra acionar a luz e a bomba de agua respectivamente;
int luz=7;
int agua=8;

//string que guarda o horario a partir do modulo relogio DS1307 pela funcao rtc.getTimeStr() que retorna o horario no formato " dia:mes:ano ";
int horario=0;
//String que guarda o dia pelo modulo  relogio DS1307 pela funcao pela funcao rtc.getDOWStr(FORMAT_SHORT); 
String dia;

//HORARIOS ja definidos pra o acionamento;
String horario_ligar_luz="18:00:00";
String horario_desligar_luz="00:00:00";
String horario_ligar_agua="17:30:00";
String horario_desligar_agua="17:35:00";

void setup()
{
  //Aciona o relogio
    rtc.halt(false);
    
    //As linhas abaixo setam a data e hora do modulo
    //e podem ser comentada apos a primeira utilizacao  
    
    /*
   
    rtc.setDOW(TUESDAY);      //Define o dia da semana
    rtc.setTime(18,18,00);     //Define o horario
    rtc.setDate(5, 1, 2016);   //Define o dia, mes e ano
    */
  
  //Definicoes do pino SQW/Out
  
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
  
  //define os pinos dos reles
    pinMode(luz,OUTPUT);  
    pinMode(agua,OUTPUT);

//seta os pinos no valor alto;

  digitalWrite(luz,HIGH);
  digitalWrite(agua,HIGH);
  
  Serial.begin(9600);
}
 
void loop()
{
 //horario=converte("17:36:00");
 
    horario=converte(rtc.getTimeStr());
    dia=rtc.getDOWStr(FORMAT_SHORT);
    //dia="Thursday";
   /*Serial.println(horario);
   Serial.println(converte(horario_ligar_luz));
   Serial.println(converte(horario_desligar_luz));*/
   Serial.println(rtc.getTimeStr());

  
  
  
  if(horario>=converte(horario_ligar_luz)&&horario<=converte(horario_desligar_luz)){
      digitalWrite(luz,LOW);
      Serial.println("Pode ligar a luz");
  }else{
      digitalWrite(luz,HIGH);
       Serial.println("Pode DELIGAR a luz");
  }
    
   if(dia.equals("Wednesday")||dia.equals("Thursday")||dia.equals("Friday")||dia.equals("Saturday")){ 
      if(horario>=converte(horario_ligar_agua)&&horario<=converte(horario_desligar_agua)){
          digitalWrite(agua,LOW);
          Serial.println("ligarndo agua");
      }else{
         //if(hora_atual.equals(horario_desligar_agua))
          digitalWrite(agua,HIGH);
          Serial.println("Deslgarndo agua");
      }
   }
  delay(1000);
}

  int converte(String hora){
  int Hora=hora.substring(0,2).toInt();
  int minuto=hora.substring(3,5).toInt();
  int segundos=hora.substring(6,8).toInt();
  if(Hora==00){
    Hora=24;
  }

return (Hora*60)+minuto;
}
