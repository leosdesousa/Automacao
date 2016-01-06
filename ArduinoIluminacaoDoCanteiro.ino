//Programa : ILuminacao e irrigacao frente casa 04/01/2016;
//Autor : Leonardo Silva de Sousa
// IFPB-CG
//email: leosdesousa@gmail.com
//Carrega a biblioteca do RTC DS1307

#include <DS1307.h>

DS1307 rtc(A4, A5);

//porta digitais que são usadas pra acionar os modulo relé, no pino 7 e 8, que são responsáveis pra acionar a luz e a bomba de água respectivamente;
int luz=7;
int agua=8;

//string que guarda o horário a partir do modulo relógio DS1307 pela função rtc.getTimeStr() que retorna o horário no formato " hora:minuto:segundos";
int horario=0;
//String que guarda o dia pelo modulo  relógio DS1307 pela função pela função rtc.getDOWStr(FORMAT_SHORT); 
String dia;

//HORÁRIOS já definidos pra o acionamento;
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
 
   //variável vai receber a chamada de uma função que passa uma string com o horário atual, a string no caso esta sendo retornada pela função rtc.getTimeSrt();
    horario=converte(rtc.getTimeStr());
    //variável dia recebendo o dia da semana
    dia=rtc.getDOWStr(FORMAT_SHORT);
    
    //imprimindo o horario atual na serial
    Serial.println(rtc.getTimeStr());

//testa se o horário atual esta dentro do intervalo para ser acionado a fita de leds

  if(horario>=converte(horario_ligar_luz)&&horario<=converte(horario_desligar_luz)){
      digitalWrite(luz,LOW); 
      Serial.println("Pode ligar a luz");
  }else{
      digitalWrite(luz,HIGH);
       Serial.println("Pode DELIGAR a luz");
  }
 
 //testa o dia da semana pra ligar a bomba de água, como atualmente estamos passando por um racionamento a água sera apenas ligada em quatro dias da semana;   
   if(dia.equals("Wednesday")||dia.equals("Thursday")||dia.equals("Friday")||dia.equals("Saturday")){ 
     //assim como o horário da iluminação o horário da irrigação eh testado 
      if(horario>=converte(horario_ligar_agua)&&horario<=converte(horario_desligar_agua)){
          digitalWrite(agua,LOW);
          Serial.println("ligando agua");
      }else{
   
          digitalWrite(agua,HIGH);
          Serial.println("desligando agua");
      }
   }
  delay(1000);
}
//funcao que recebe uma string no formato "hora:minuto:segundos" 
  int converte(String hora){
    //utilizando substring() e o toInt() podemos separar a string por campos e pegar apenas os valores e converter para uma variável inteira
    //com isso podemos converter para minutos e comprar se estão no intervalo para o acionamento...
    
  int Hora=hora.substring(0,2).toInt(); 
  int minuto=hora.substring(3,5).toInt();
  int segundos=hora.substring(6,8).toInt();
  if(Hora==00){
    Hora=24;
  }

return (Hora*60)+minuto; //converte hora para minutos e soma com os minutos;
}
