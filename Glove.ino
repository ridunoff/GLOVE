#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

// Adjust these values for the RGB Backlight
// R=0 G=0 B=0 is off
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// Only pins 2 and 3 work with attachInterrupt
const int touchPin=2;
const int buttonPin=3;

// Glove starts at page 0 and on
int counter = -1;
boolean isOn = true;


void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    // set the backlight color
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a welcome message to the LCD.
    lcd.print("Welcome to GLOVE");
    
    // set up button and touch sensor
    pinMode(touchPin, INPUT);
    pinMode(buttonPin, INPUT);


    Serial.begin(9600); //Initialize the serial monitor

    // attach interrupts for both inputs
    attachInterrupt(digitalPinToInterrupt(touchPin), touch, RISING);
    attachInterrupt(digitalPinToInterrupt(buttonPin), power, RISING);
}

void loop() 
{

   // Power Status
  
   if(isOn){ // turns screen on
    lcd.display();
    lcd.setRGB(colorR, colorG, colorB);
   }
   else { // turns screen off
    lcd.noDisplay();
    lcd.setRGB(0, 0, 0);
   }


   // Touch Pad Control

   // resets the page counter to 0 on the last page
   if(counter > 3){
    counter = 0;
   }

   // changes the page only when the button is currently being pressed
   int touchRead = digitalRead(touchPin);
   if(touchRead == 1){
     changeDisplay(counter);
   }
   Serial.println(counter);
}


void power(){
  int firstReading = digitalRead(buttonPin); //reads 1st state of the button
  delayMicroseconds(100); //Waits .1 seconds
  int secondReading = digitalRead(buttonPin); //reads 2nd state of the button
  
  if (firstReading == secondReading){
    //If the button is pressed for both readings, the power state toggels to off
    isOn = !isOn;
  }
}


void touch(){
  int firstReading = digitalRead(touchPin); //reads 1st state of touch pad
  delayMicroseconds(100); //Waits .1 seconds
  int secondReading = digitalRead(touchPin); //reads 2nd state of touch pad
  
  if (firstReading == secondReading){
    //If the touch pad is pressed for both readings, the page counter increments by 1 
    counter += 1;
  }
}


void changeDisplay(int pageNumber){
  // resets screen
  lcd.clear();

  // Time and Date page
  if (pageNumber == 0){
    lcd.print("Time: 12:30:32");
    lcd.setCursor(0, 1);
    lcd.print("Sun 12/22/2019");
    
  }

  // Weather page
  else if (pageNumber == 1){
    lcd.print("Weather: Rainy");
    lcd.setCursor(0, 1);
    //lcd.print(F(" \xDF""C. Humidity: "));
    lcd.print("Temp:    45");
    lcd.print("\xDF");
    lcd.print("F");
  }

  // Notification Page
  else if (pageNumber == 2){
    lcd.print("2 New");
    lcd.setCursor(0, 1);
    lcd.print("Notifications");
  }

  // Calender Page
  else{
    lcd.print("Next Event:");
    lcd.setCursor(0, 1);
    lcd.print("9:30AM Coffee");
  }

  // Screen refresh rate
  delay(500);
}
