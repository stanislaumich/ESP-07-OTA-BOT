//#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include "FS.h"
#include <EEPROM.h>
#define myWeb
#ifndef common
 #include "common.h"
 #endif 
#ifndef myWiFi
 #include "myWiFi.h"
 #endif
#ifndef myTime
 #include "myTime.h"
 #endif
#ifndef mySSDP
  #include"mySSDP.h"
 #endif 
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
File fsUploadFile;
String XML;

void Log(String s){
  Serial.println(s);
 }

void MyWebinit(void){
  SPIFFS.begin();
  httpUpdater.setup(&httpServer);
    httpServer.on("/description.xml", HTTP_GET, []() {
    SSDP.schema(httpServer.client());
  });

  ////////////////////////////////////////////
  httpServer.onNotFound([]() { });


  httpServer.begin();
 
  Serial.print("HTTPUpdateServer ready! Open http://192.168.0.234/update in your browser\n");
 }