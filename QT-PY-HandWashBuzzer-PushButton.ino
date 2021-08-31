#include "pitches.h"
#include "playGroundMelody.h"
const int buzzer = 5; //buzzer to arduino pin 9
const int redLED = 2;
const int greenLED = 3;
const int secToWash = 5;

void setup(){

  pinMode(buzzer, OUTPUT); // Set buzzer - pin A3 as an output
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);  
  // Turn on Red LED
  //digitalWrite(redLED,HIGH);
  //tone(buzzer, 1000); // Send 1KHz sound signal...
  //Serial.println("Buz ON");
  //delay(500);        // ...for 1/2 sec
  //noTone(buzzer);     // Stop sound...
 
  digitalWrite(greenLED,LOW);

  Serial.println("redLED HIGH");
  countDown();
 // Serial.println("Buz ON");
 // tone(buzzer, 1000); // Send 1KHz sound signal...
  digitalWrite(redLED,LOW);
 // Serial.println("redLED LOW");
  digitalWrite(greenLED,HIGH);
 // delay(2000);        // ...for 2 sec
  //Serial.println("Buz OFf");
 // noTone(buzzer);     // Stop sound...
 // Serial.println("greenLED HIGH");


      int tempo = 120;  
      int notes = sizeof(melody) / sizeof(melody[0]) / 2; 
      int wholenote = (60000 * 4) / tempo;
      int divider = 0, noteDuration = 0;
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) 
      {
         divider = melody[thisNote + 1];
        if (divider > 0) 
        {
          noteDuration = (wholenote) / divider;
        } 
        else if (divider < 0) 
        {
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

      tone(buzzer, melody[thisNote], noteDuration * 0.9);
      delay(noteDuration);
      noTone(buzzer);
     }
 
}

void loop()
{
  
  delay(150);  
  
}

//********************
void countDown()
{
 for(int j = 0; j < secToWash; j++)
 {
    tone(buzzer, 500);
    digitalWrite(redLED,HIGH); 
    delay(400);
    digitalWrite(redLED,LOW);
    noTone(buzzer);
    delay(385);
 }

  digitalWrite(greenLED,HIGH);
}
