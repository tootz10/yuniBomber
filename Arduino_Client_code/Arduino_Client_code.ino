/*
 Possible commands created in this shetch:
 * "/arduino/digital/13/1"   -> digitalWrite(13, HIGH)
 * "/arduino/digital/13/0"   -> digitalWrite(13, LOW)

 This example code is part of the public domain
 http://arduino.cc/en/Tutorial/Bridge
 */
#include <Bridge.h>
#include <YunClient.h>

void setup() {
  // Bridge startup
  Bridge.begin();

  Serial.begin(9600);
  
  // Get clients coming from server
  YunClient client = client.connect("localhost:8001/arduino/digital/13/1", 8001);
  //client.connect("localhost:8001", 8001);
  
  while (!Serial); // wait for a serial connection
}

void loop() {
  YunClient client;
  //client.get("http://localhost:8001/arduino/digital/1");
 
 char c = client.connected();  //  Test connection
 Serial.println(c);            //  Print connection
 
  delay(50); // Poll every 50ms
}

void process(YunClient client) {
  // read the command
  String command = client.readStringUntil('/');

  // is "digital" command?
  if (command == "digital") {
    digitalCommand(client);
  }
}

void digitalCommand(YunClient client) {
  int pin, value;

  // Read pin number
  pin = client.parseInt();

  // If the next character is a '/' it means we have an URL
  // with a value like: "/digital/13/1"
  if (client.read() == '/') {
    value = client.parseInt();
    digitalWrite(pin, value);
  }
  else {
    Serial.println('Error: Could not read url!');
  }
}





