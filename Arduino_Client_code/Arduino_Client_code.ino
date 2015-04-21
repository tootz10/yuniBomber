/*
 Possible commands created in this shetch:
 * "http://yunobomber-cuebo.rhcloud.com"                         -> Serial Monitor "Hello World"
 * "http://yunobomber-cuebo.rhcloud.com/blink"                   -> Serial Monitor "1" Makes LED pin 13 blink on/off every second
 */
 
#include <Bridge.h>   
#include <HttpClient.h>
HttpClient client;

void setup() {
  Bridge.begin();                                              // Bridge startup
  Serial.begin(115200);
  while (!Serial);                                             // wait for a serial connection
  pinMode(13, OUTPUT);                                         // initialize digital pin 13 as an output.
}

void loop() {
  client.get("http://yunibomber-cuebo.rhcloud.com/blink");    // Make a HTTP request:
 
  while (client.available()) {                                // Read message from server
    int val = client.read();                                  // Val is a char and 1 is = 49
    int newVal = val - 48;                                    // So 49 - 48 is = 1
    if (newVal == 1){
      digitalWrite(13, HIGH);                                 // turn the LED on (HIGH is the voltage level)
    }
  } 
}
