#include <MPU6050.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

DFRobotDFPlayerMini player;
void printDetail(uint8_t type, int value);

void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sign Language to");
  lcd.setCursor(0, 1);
  lcd.print("Speech Convert");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
  softwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println();
  lcd.print(F("Initializing DFPlayer..."));

  //Use softwareSerial to communicate with MP3
  if (!player.begin(softwareSerial)) {
    Serial.println("OK");    
    lcd.clear();    
    lcd.print(F("Unable to begin:"));
    delay(1000);
    lcd.clear(); 
    lcd.setCursor(0, 0);       
    lcd.print(F("1.Please recheck"));
    lcd.setCursor(0, 1);
    lcd.print(F("the connection!"));    
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);       
    lcd.print(F("2.Please insert "));
    lcd.setCursor(0, 1);
    lcd.print(F("the SD card!"));     
    delay(1000);    
    //while (true);
    player.volume(30);
  }
  lcd.clear();
  lcd.print(F("DFPlayer Mini online."));
  lcd.clear();  
  

}

void loop()
{
  int f = analogRead(A0);
  //Serial.println(f);
  int g =analogRead(A1);
  Serial.println(g);
 /*if ((f > 200) && (f<245))                       //No Bend; 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 1");
    lcd.setCursor(0, 1);
    lcd.print("I need help");
    player.play(1);
    delay(5000);
  }*/
  if ((f < 180) && (f >150))   //Small Bend; 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 1");
    lcd.setCursor(0, 1);
    lcd.print("Feeling hungry");
    player.play(3);
    delay(5000);
  }
  else if ((f <=145) && (f >120))   //Small Bend; 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 2");
    lcd.setCursor(0, 1);
    lcd.print("Give me medicine");
    player.play(2);
    delay(5000);
   
  }
  else if ((f <= 118) && (f >=85))                             // Larger Bend; 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 3"); 
    lcd.setCursor(0, 1);     
    lcd.print("I want to sleep");
    player.play(4);
    delay(5000);
  }
  /*else if((g>=44)&&(g<=46))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 4"); 
    lcd.setCursor(0, 1);     
    lcd.print("I want to play");
    player.play(5);
    delay(5000);
    
  }*/
  else if((g>=42)&&(g<=44))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 5"); 
    lcd.setCursor(0, 1);     
    lcd.print("How are you?");
    player.play(6);
    delay(5000);
  }
  else if((g>35)&&(g<=40))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 6"); 
    lcd.setCursor(0, 1);     
    lcd.print("Shall we go out?");
    player.play(7);
    delay(5000);
  }
  else if((g<35)&&(g<=40))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action 7"); 
    lcd.setCursor(0, 1);     
    lcd.print("I feel sick");
    player.play(8);
    delay(5000);
  }
    
  delay(50);
}
