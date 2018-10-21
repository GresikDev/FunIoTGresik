#include <ESP8266WiFi.h>            
#include <ESP8266WebServer.h>
#include <FastLED.h>

#define LED_PIN     D4
#define NUM_LEDS    5
CRGB leds[NUM_LEDS];

ESP8266WebServer server(80);   //Web server object. Will be listening in port 80 (default for HTTP)

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(115200);
  WiFi.begin("SISI-CORP", "soetomo29"); //Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) { //Wait for connection
    delay(500);
    Serial.println("Waiting to connect…");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP to access the server
  server.on("/genericArgs", handleGenericArgs); //Associate the handler function to the path
  server.begin();                                       //Start the server
  Serial.println("Server listening");   
}

void loop() {
  server.handleClient();    //Handling of incoming requests
}

void handleGenericArgs() { //Handler
  nyalakan(server.arg(0).toInt(),server.arg(1).toInt(),server.arg(2).toInt());
}

void nyalakan(int R, int G, int B){
  int i=0;
  
  while(i<NUM_LEDS){
    leds[i] = CRGB(R, G, B);
    i++;
  }
  FastLED.show();
}
