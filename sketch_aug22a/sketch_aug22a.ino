#include<ESP8266WiFi.h>
#include<ArduinoOTA.h>
const char* name=".x";
const char* pass="kashyap1";
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(name,pass);
  while (WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\n IP:%s\n",WiFi.localIP().toString().c_str());
  ArduinoOTA.setHostname("esp8266-ota");
  ArduinoOTA.onStart([](){
  Serial.println("OTA START\n");
});
ArduinoOTA.onEnd([](){
  Serial.println("OTA end");
});
ArduinoOTA.onError([](ota_error_t e){
  Serial.printf("OTA error %u",e);

});
ArduinoOTA.begin();
Serial.println("OTA ready.In IDE->port->esp8266-ota");
}
void loop(){
  ArduinoOTA.handle();
}