```cpp
#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

// -------------------- PINS --------------------
#define DHTPIN 4
#define DHTTYPE DHT11
#define LEDPIN 2

// -------------------- WIFI --------------------
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// -------------------- OBJECTS --------------------
DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

// -------------------- WEB PAGE --------------------
void handleRoot() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Debug output to Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temp);

  Serial.print("Humidity: ");
  Serial.println(hum);

  String page = "<html><head>";
  page += "<title>ESP32 Smart Room Control</title>";

  // Simple page styling
  page += "<style>";
  page += "body {";
  page += "font-family: Arial;";
  page += "text-align: center;";
  page += "background-color: #f2f2f2;";
  page += "}";

  page += ".container {";
  page += "background: white;";
  page += "width: 350px;";
  page += "margin: 50px auto;";
  page += "padding: 20px;";
  page += "border-radius: 10px;";
  page += "box-shadow: 0 0 10px rgba(0,0,0,0.2);";
  page += "}";

  page += "button {";
  page += "padding: 15px 25px;";
  page += "font-size: 18px;";
  page += "margin: 10px;";
  page += "border: none;";
  page += "border-radius: 8px;";
  page += "cursor: pointer;";
  page += "}";

  page += ".on { background-color: green; color: white; }";
  page += ".off { background-color: red; color: white; }";

  page += "</style></head><body>";

  page += "<div class='container'>";
  page += "<h1>ESP32 Smart Room Control</h1>";

  // Sensor readings
  if (isnan(temp) || isnan(hum)) {
    page += "<p><b>DHT11 sensor reading failed.</b></p>";
    page += "<p>Check DATA, VCC, and GND wires.</p>";
  } else {
    page += "<p><b>Temperature:</b> ";
    page += String(temp);
    page += " C</p>";

    page += "<p><b>Humidity:</b> ";
    page += String(hum);
    page += " %</p>";
  }

  // LED Buttons
  page += "<a href='/ledon'><button class='on'>LED ON</button></a>";
  page += "<a href='/ledoff'><button class='off'>LED OFF</button></a>";

  page += "</div></body></html>";

  server.send(200, "text/html", page);
}

// -------------------- LED ON --------------------
void ledOn() {
  digitalWrite(LEDPIN, HIGH);

  server.sendHeader("Location", "/");
  server.send(303);
}

// -------------------- LED OFF --------------------
void ledOff() {
  digitalWrite(LEDPIN, LOW);

  server.sendHeader("Location", "/");
  server.send(303);
}

// -------------------- SETUP --------------------
void setup() {

  Serial.begin(115200);

  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);

  Serial.println("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected!");
  Serial.println(WiFi.localIP());

  // Web routes
  server.on("/", handleRoot);
  server.on("/ledon", ledOn);
  server.on("/ledoff", ledOff);

  // Start server
  server.begin();
}

// -------------------- LOOP --------------------
void loop() {
  server.handleClient();
}
```


void loop() {
  server.handleClient();
}
