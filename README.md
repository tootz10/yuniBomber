# YuniBomber

YuniBomber contain two files, some server code and an Arduino sketch (Yun). 
Putting the two files to use, will give you a nodejs-server and a Arduino-Yun-Client.

The aim of the project, is to communicate between two Arduino Yun, working as clients, over a nodejs-server. 
The code in this example will be used for a YuniBomber game, where to robots, build wih Arduino Yun's, will try to pass on a timed bomb in a known and controlled invironment. Further description will be updated in the wiki pages of this project later on.

At the moment the rep is still under development. The project status looks like this:

  1. Create Server                                Done
  2. Create Client                                Done
  3. Connect Client to Server                     Done
  4. Recieve Server-message on Client             Done
  5. Change LED pin 13 on Client from Server      Next

To see the current code in function, go to:
http://yunobomber-cuebo.rhcloud.com/

You will see a 'Hello World' message.

Add one of the two extentions to the url(http://yunobomber-cuebo.rhcloud.com/), to change the server message:

 "http://yunobomber-cuebo.rhcloud.com"                          -> Will console.log "Hello World"
 "http://yunobomber-cuebo.rhcloud.com/arduino/digital/13/1"    -> Will console.log "Led 13 is on"
 "http://yunobomber-cuebo.rhcloud.com/arduino/digital/13/0"    -> Will console.log "Led 13 is off"

