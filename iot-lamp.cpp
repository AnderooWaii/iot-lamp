/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/0fa0ce01-f6c5-47b6-bb3c-ebe45e82c0f9 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int echo;
  int trigger;
  bool ledLamp;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <WiFi.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <Ultrasonic.h>


Ultrasonic ultrasonic(26, 25); // Menghubungkan pin Trigger ke GPIO 13 dan Echo ke GPIO 12
int ledPin = 18; // Menghubungkan pin LED ke GPIO 5

void initProperties() {
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  ArduinoCloud.addProperty(ultrasonic.distanceRead(), READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(digitalRead(ledPin), WRITE);
}


void setup() {
  pinMode(ledPin, OUTPUT);

  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
 ArduinoCloud.update();

  int distance = ultrasonic.distanceRead();
  ArduinoCloud.updateProperty(ultrasonic.distanceRead(), distance);

  if (distance <= 150) {
    digitalWrite(ledPin, HIGH);
    ArduinoCloud.updateProperty(digitalRead(ledPin), HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    ArduinoCloud.updateProperty(digitalRead(ledPin), LOW);
  }
  
}


/*
  Since LedLamp is READ_WRITE variable, onLedLampChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedLampChange()  {
  // Add your code here to act upon LedLamp change
  if ledLamp = 1{
    digitalWrite(ledPin, HIGH);
  }else{
    digitallWrite(ledPin, LOW);
  }
}

/*
  Since Echo is READ_WRITE variable, onEchoChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onEchoChange()  {
  // Add your code here to act upon Echo change
}

/*
  Since Trigger is READ_WRITE variable, onTriggerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTriggerChange()  {
  // Add your code here to act upon Trigger change
}



