#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLIbohFnkf"
#define BLYNK_DEVICE_NAME "moisture"
#define BLYNK_AUTH_TOKEN "yQyOTvqhLVdNf6KtAvGpNmfb7jGIwTk4"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yQyOTvqhLVdNf6KtAvGpNmfb7jGIwTk4";//Paste auth token you copied

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VNR_001";///Enter your wifi name
char pass[] = "vnr@0001";// Enter wifi password


BlynkTimer timer;
int moistpin=34;
BLYNK_WRITE(V1)
{

if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(13,HIGH);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(13,LOW);  // Set digital pin 2 LOW    
  }
 
  }
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
 
  int moistvalue = analogRead(moistpin);

  // You can send any value at any time.

    Blynk.virtualWrite(V0, moistvalue); // select your virtual pins accordingly
  
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(13,OUTPUT);
//delay(1000);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080)
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
