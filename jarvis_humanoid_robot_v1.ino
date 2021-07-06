//Coded by Robotic Thamizha YouTube Channel 
#include <Servo.h> //define servo library

String voice;


const int LMF = A0;//define left motor forward pin(in 1) in motordrive
const int LMB = A1;//define left motor backward pin(in 2) in motordrive
const int RMF = A2;//define right motor forward pin(in 3) in motordrive
const int RMB = A3;//define right motor backward pin(in 4) in motordrive

Servo myrh;
Servo mylh;
Servo myhead;


void setup()
{
  Serial.print(9600);//Start Serial communication
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  myrh.attach(8);//define servo motor pin
  mylh.attach(9);//define servo motor pin
  myhead.attach(10);//define servo motor pin
  myrh.write(90);//define servo motor postion  
  mylh.write(90);//define servo motor position
  myhead.write(90);//define servo motor position
  
}

void loop()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(100);
  
  while (Serial.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0) {
   
   if (voice == "Jarvis move forward"){
     forward_robot();
    }
   if (voice == "jarvis move forward"){
     forward_robot();
    }
    if (voice == "move forward"){
     forward_robot();
    }
    if (voice == "Jarvis move back"){
     back_robot();
    }
    if (voice == "jarvis move back"){
     back_robot();
    }
    if (voice == "move back"){
     back_robot();
    }
    if (voice == "Jarvis turn right"){
     right_robot();
    }
    if (voice == "jarvis turn right"){
     right_robot();
    }
    if (voice == "turn right"){
     right_robot();
    }
     if (voice == "Jarvis turn left"){
     left_robot();
    }
     if (voice == "jarvis turn left"){
     left_robot();
    }
    if (voice == "turn left"){
     left_robot();
    }
     if (voice == "Jarvis rotate your head"){
     rotateh_robot();
    }
     if (voice == "jarvis rotate your head"){
     rotateh_robot();
    }
     if (voice == "rotate your head"){
     rotateh_robot();
    }
    if (voice == "Jarvis attack"){
     attack_robot();
    }
    if (voice == "jarvis attack"){
     attack_robot();
    }
    if (voice == "attack"){
     attack_robot();
    }
    if (voice == "Jarvis right hand up"){
     rh_up();
    }
    if (voice == "jarvis right hand up"){
     rh_up();
    }
    if (voice == "right hand up"){
     rh_up();
    }
    if (voice == "Jarvis right hand down"){
     rh_down();
    }
    if (voice == "jarvis right hand down"){
     rh_down();
    }
    if (voice == "right hand down"){
     rh_down();
    }
    if (voice == "Jarvis left hand up"){
     lh_up();
    }
    if (voice == "jarvis left hand up"){
     lh_up();
    }
    if (voice == "left hand up"){
     lh_up();
    }
    if (voice == "Jarvis left hand down"){
     lh_down();
    }
    if (voice == "jarvis left hand down"){
     lh_down();
    }
    if (voice == "left hand down"){
     lh_down();
    }
    if (voice == "Jarvis say hello"){
     hello_robot();
    }
    if (voice == "jarvis say hello"){
     hello_robot();
    }
    if (voice == "say hello"){
     hello_robot();
    }
    voice = "";
   }
}

void forward_robot()
{
  digitalWrite(LMF, HIGH);   
    digitalWrite(RMF, HIGH);  
                                             
    digitalWrite(LMB, LOW);   
    digitalWrite(RMB, LOW);  
                                            
     delay(3000);                         
                                             
     digitalWrite(LMF, LOW);    
    digitalWrite(RMF, LOW);   
  
     digitalWrite(LMB, LOW);
     digitalWrite(RMB, LOW);
}

void back_robot()
{
  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, HIGH);
  
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);

  delay(3000);

  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW); 
}

void right_robot()
{
  digitalWrite(LMB, LOW);
  digitalWrite(RMF, LOW);
  
  delay(1500);
  
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
 
   digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void left_robot()
{
  digitalWrite(LMB, HIGH);
  digitalWrite(RMF, HIGH);
  
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);

  delay(1500);
  
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);

   digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void rotateh_robot()
{
  myhead.write(180);
  delay(500);
  myhead.write(0);
  delay(500);
  myhead.write(90);
  delay(500);
}
void attack_robot()
{
  mylh.write(0); digitalWrite(2, HIGH);
  delay(5000);   delay(100);
  mylh.write(90);digitalWrite(2, LOW);
  delay(500);    delay(100);
  
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
}
void rh_up()
{
  myrh.write(180);
  delay(500);
}

void rh_down()
{
  myrh.write(90);
  delay(500);
}

void lh_up()
{
  mylh.write(0);
  delay(500);
}

void lh_down()
{
  mylh.write(90);
  delay(500);
}

void hello_robot()
{
  myrh.write(180);
  delay(5000);
  myrh.write(90);
  delay(500);
}
