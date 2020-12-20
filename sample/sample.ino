#include <SPI.h>

#ifdef WIOTERMINAL
#include <rpcWiFi.h>
#else
#include <WiFi.h>
#endif

#include <WiFiClient.h>
#include <WebServer.h>
#include <WiFiAP.h>

#define DBG_OUTPUT_PORT Serial

const char* ssid = "inajob-web-test";
const char* password = "mypassword";
const char* host = "esp32sd";

WebServer server(80);


void returnOK() {
  server.send(200, "text/plain", "");
}

void returnFail(String msg) {
  server.send(500, "text/plain", msg + "\r\n");
}

void printHello() {
  server.send(200, "text/json", "Hello World!");
}
void printHelloMany() {
  server.setContentLength(CONTENT_LENGTH_UNKNOWN);
  server.send(200, "text/json", "");
  for(int i = 0; i < 100; i ++){
    server.sendContent("Hello World!");
  }
  server.sendContent("");
  server.client().stop();
}

void setup(void) {
  DBG_OUTPUT_PORT.begin(115200);
  while(!Serial); // Wait for Serial to be ready
  DBG_OUTPUT_PORT.print("\n");

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  DBG_OUTPUT_PORT.print("AP IP address: ");
  DBG_OUTPUT_PORT.println(myIP);
 
  DBG_OUTPUT_PORT.print("Connecting to ");
  DBG_OUTPUT_PORT.println(ssid);

  server.on("/hello", HTTP_GET, printHello);
  server.on("/hello-many", HTTP_GET, printHelloMany);

  server.begin();
  DBG_OUTPUT_PORT.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}

