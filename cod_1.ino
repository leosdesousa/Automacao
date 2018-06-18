


const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;  
const int buttonPin3 = 7;     // the number of the pushbutton pin
const int buttonPin4 = 6;  
const int ledPin =  13;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;

int IN1 = 4;
int IN2 = 5;

void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  
  pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);  
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);//2
  
  buttonState2 = digitalRead(buttonPin2);//3
  
  buttonState3 = digitalRead(buttonPin3);//7
  buttonState4 = digitalRead(buttonPin4);//6
// 
  //FIM DE CURSO
  if(buttonState!=1&&buttonState3!=1)
  {
 // Serial.println("ligdos");
  }
  else{

  //abrir 
  
  //fim de curso verde =3,chave =2
  if (buttonState2 == 0) {  
     digitalWrite(ledPin, 1 ); 
     //Serial.println("ligou");
      if (buttonState == 1) {     
      // turn LED on:    
     digitalWrite(ledPin, 0);
      } 
        else {
        // turn LED off:
        Serial.println("abrir");
          digitalWrite(ledPin,  1);  
       digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      delay(100);
       digitalWrite(IN1, 0);
      digitalWrite(IN2, 0  );
      }  
  } 
  else {
         digitalWrite(ledPin, 0);
       //Serial.println("deligado"); 
  }
  
  //-----------------------------------------
  // fim de curso =6, chave =7
   if (buttonState4 == 0) {  
    //digitalWrite(ledPin, 1 );
      if (buttonState3 == 1) {       
        digitalWrite(ledPin, 0);
      } 
      else {
        Serial.println("fechar");
          // turn LED off:
          digitalWrite(ledPin,  1);  
         digitalWrite(IN1, 0);
          digitalWrite(IN2, 1);
          delay(100);
          digitalWrite(IN1, 0);
          digitalWrite(IN2, 0  );
      } 
  } 
  else {
         digitalWrite(ledPin, 0 );  
  }
  
  
           //  delay(100);
           //  buttonState4 = digitalRead(buttonPin4);
             Serial.println(buttonState2 );
           //  delay(100);
             
  }
 /* digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
 delay(2000);
 
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 delay(2000);*/
}
