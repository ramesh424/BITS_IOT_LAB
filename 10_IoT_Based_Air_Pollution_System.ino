#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLn-hO4-Tr"
#define BLYNK_DEVICE_NAME "airquality"
//#define BLYNK_AUTH_TOKEN "KS5ttFqRkMRqnyGza85iU6dInwvjnv4U"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "KS5ttFqRkMRqnyGza85iU6dInwvjnv4U";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VNR_001";
char pass[] = "vnr@0001";

#define MQ2 34
#define GREEN 16
#define RED 17
int sensorValue = 0;
boolean state = false;

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(MQ2, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  timer.setInterval(1000L, sendUptime);
}

void sendUptime()
{
  
  sensorValue = analogRead(MQ2);
  Blynk.virtualWrite(V0, sensorValue);
  Serial.println(sensorValue);

  if (sensorValue > 600)
  {
    Blynk.notify("Gas Detected!");
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }

  else
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
}

void loop()
{
  Blynk.run();
  timer.run();
}
