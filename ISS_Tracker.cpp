#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <WiFiClient.h>

float mylat = 13.018809646882627;
float mylon = 77.60551520812069;
float isslat, isslon;
int distance;
String payload;


const String iss = "http://api.open-notify.org/iss-now.json";


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

WiFiClient wifiClient;

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
}

void loop()
{
  getJson(iss);
  decodeLocJson();
  getDistance();
  issLocOLEDDisplay();
  issLocSerialDisplay();
  Serial.println("------------------------------------------------");
  delay(5000);
}

void issLocOLEDDisplay()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ISS is now at: ");
  char temp[15];
  sprintf(temp, "%d.%02d,%d.%02d", (int)isslat, abs((int)(isslat * 100) % 100), (int)isslon, abs((int)(isslon * 100) % 100));
  display.println(temp);
  char temp1[30];
  sprintf(temp1, "ISS is %d miles", distance);
  display.println(temp1);
  display.println("from you.");
  display.display();
}

void issLocSerialDisplay()
{
  Serial.print("ISS is currently at ");
  Serial.print(isslat, 4);
  Serial.print(",");
  Serial.println(isslon, 4);
  Serial.println("Your Current Latitude and Longitude is: ");
  Serial.println("13.018809646882627, 77.60551520812069");
  Serial.print("The ISS is about ");
  Serial.print(distance);
  Serial.println(" miles from you");
}

void getJson(String url)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(wifiClient, url);
    int httpCode = http.GET();
    if (httpCode > 0)
    {
      payload = http.getString();
    }
    http.end();
  }
}

void decodeLocJson()
{
  DynamicJsonDocument jsonBuffer(512);
  deserializeJson(jsonBuffer, payload);
  JsonObject root = jsonBuffer.as<JsonObject>();
  isslat = root["iss_position"]["latitude"];
  isslon = root["iss_position"]["longitude"];
}

void getDistance()
{
  float theta, dist, miles;
  theta = mylon - isslon;
  dist = sin(deg2rad(mylat)) * sin(deg2rad(isslat)) + cos(deg2rad(mylat)) * cos(deg2rad(isslat)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  miles = dist * 60 * 1.1515;
  distance = miles;
}

float deg2rad(float n)
{
  float radian = (n * 71) / 4068;
  return radian;
}

float rad2deg(float n)
{
  float degree = (n * 4068) / 71;
  return degree;
}
