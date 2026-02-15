#define BLYNK_TEMPLATE_ID "TMPL6sNOaNxj4"
#define BLYNK_TEMPLATE_NAME "Distance and ph"
#define BLYNK_AUTH_TOKEN "7PU7e_Sk1bqNABjuW8VgENDVg3uBzyWL"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>


char auth[] = "7PU7e_Sk1bqNABjuW8VgENDVg3uBzyWL";


char ssid[] = "Sadat 2.4 GHz";
char pass[] = "sadatrah";


BlynkTimer timer;




#define soil A0
#define buzzer 13     //D7




void soilMoistureSensor() {
  int value = analogRead(soil);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V1, value);
  
  Serial.print("S:");
  Serial.print(value);
  Serial.println(" ");

}

BLYNK_WRITE(V2)
{
  int pin=param.asInt();
  digitalWrite(buzzer,pin);
  }




void setup()
{   
  
  Serial.begin(115200);
  

  Blynk.begin(auth, ssid, pass);

   timer.setInterval(100L, soilMoistureSensor);

  pinMode(buzzer, OUTPUT);
 
 
  }

void loop() {

  Blynk.run();
  timer.run();
 }

