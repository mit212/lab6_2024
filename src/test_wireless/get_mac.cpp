#include <WiFi.h>
 
// https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/

void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  
}
 
void loop(){
  
  Serial.println(WiFi.macAddress());
  delay(250);
}