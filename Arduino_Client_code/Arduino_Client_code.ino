/*
 Possible commands created in this shetch:
 * "http://yunobomber-cuebo.rhcloud.com"                         -> Serial Monitor "Hello World"
 * "http://yunobomber-cuebo.rhcloud.com/arduino/digital/13/1"    -> Serial Monitor "Led 13 is on"  &  digitalWrite(13, HIGH)
 * "http://yunobomber-cuebo.rhcloud.com//arduino/digital/13/0"   -> Serial Monitor "Led 13 is off" &  digitalWrite(13, LOW)
 */
 
#include <Bridge.h>   
#include <HttpClient.h>

HttpClient client;

void setup() {
  Bridge.begin();                                                          // Bridge startup

  Serial.begin(9600);
  while (!Serial);                                                         // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  client.get("http://yunobomber-cuebo.rhcloud.com");       // Insert alternative url for other commands - See explanation at top
 
  while (client.available()) {                             // Read message from server
    char c = client.read();
    Serial.print(c);
  }
  Serial.flush();
  delay(5000);
}

void process(HttpClient client) {
  String command = client.readStringUntil('/');

  if (command == "digital") {
    digitalCommand(client);
  }
}

void digitalCommand(HttpClient client) {
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
