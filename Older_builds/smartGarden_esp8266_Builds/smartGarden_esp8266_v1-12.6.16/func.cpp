// This file DEFINES the global functions
#include <dummy.h>
#include <ESP8266WiFi.h>
#include "Arduino.h"
#include "var.hpp"
#include "func.hpp"
WiFiServer server(80);

void initPorts(void)
{
  
}

void connectToWiFi(void)
{
    if(WiFi.status() != WL_CONNECTED) // Wait for ESP8266 to connect to WiFi
    {
    delay(500);
    WiFi.begin(ssid, password); // Connect to WiFi
    delay(2000);
    Serial.write(1);  // Send info to Arduino that WiFi is connected
    } 
    else Serial.write(0);

    }
    else connectToWiFi();
    delay(1000);
}

void startServer(void)
{
  server.begin();
  Serial.println("Server started");
}

void printIP(void)
{
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void getRequest(void)
{
    // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
  return;
  }
    // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
  delay(1);
  }
 
    // Read the first line of the request
  request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
}

void matchRequest(void)
{
  if (request.indexOf("/STATE=ON") != -1)  {
    state = 1;
  }
  if (request.indexOf("/STATE=OFF") != -1)  {
    state = 2;
  }
}

void returnResponse(void)
{
  WiFiClient client = server.available();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<br><br>");
  client.println("<a href=\"/STATE=ON\"\"><button>Turn irrigation ON</button></a>");
  client.println("<a href=\"/STATE=OFF\"\"><button>Turn irrigation OFF </button></a><br>");

  switch(state)
  {
    case 1: client.print("ON chosen"); break;
    case 2: client.print("OFF chosen"); break;
  }
  
  client.println("</html>");

}

void blinkLED(int pin, int freq)
{
  digitalWrite(pin, HIGH);
  delay(freq);
  digitalWrite(pin, LOW);
  delay(freq);
}
