#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

// Pin setup
#define DHTPIN 4
#define DHTTYPE DHT11
#define LEDPIN 2

// Replace these with your Wi-Fi name and password
const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

// Create sensor and server objects
DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

// This function creates the main web page
void handleRoot() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  String page = "<!DOCTYPE html>";
  page += "<html>";
  page += "<head>";
  page += "<title>ESP32 Smart Room Control</title>";
  page += "<style>";
  page += "body { font-family: Arial; text-align: center; background-color: #f2f2f2; }";
  page += ".box { background: white; padding: 20px; margin: 40px auto; width: 320px; border-radius: 10px; }";
  page += "button { padding: 12px 20px; margin: 10px; font-size: 16px; cursor: pointer; }";
  page += "</style>";
  page += "</head>";
  page += "<body>";
  page += "<div class='box'>";
  page += "<h1>Smart Room Control</h1>";

  if (isnan(temperature) || isnan(humidity)) {
    page += "<p>Sensor reading failed. Please check the wiring.</p>";
  } else {
    page += "<p>Temperature: " + String(temperature) + " &deg;C</p>";
    page += "<p>Humidity: " + String(humidity) + " %</p>";
  }

  page += "<a href='/ledon'><button>Turn LED On</button></a>";
  page += "<a href='/ledoff'><button>Turn LED Off</button></a>";

  page += "<p>This LED represents a device such as a light or fan.</p>";
  page += "</div>";
  page += "</body>";
  page += "</html>";

  server.send(200, "text/html", page);
}

// Turns LED on
void handleLedOn() {
  digitalWrite(LEDPIN, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

// Turns LED off
void handleLedOff() {
  digitalWrite(LEDPIN, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  dht.begin();

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Still connecting...");
  }

  Serial.println("Wi-Fi connected.");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/ledon", handleLedOn);
  server.on("/ledoff", handleLedOff);

  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();
}
