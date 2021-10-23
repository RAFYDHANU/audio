


#include <DHT.h>
#include <ESP8266WiFi.h> // file untuk modul wifi
#include<BlynkSimpleEsp8266.h> // file untuk bliynk

char auth[] = "BBFF-iTeLbEYq3XqzQlK4yeoab3OojzKD5x"; // token yang dikirm ke email mu masing"
char ssid[] = "IDN_Boarding_School";
char pass[] = ""; 

#define DHTPIN 14
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
 float h = dht.readHumidity();
 float t = dht.readTemperature();

 if (isnan(h) || isnan(t)) { //mengecek kondisi apabila suhu dan kelembapan tidak ada 
  Serial.println("Failed to read temp and humadity");
  return;
 }

 Blynk.virtualWrite(V1, t); //setting virtual suhu di Bliynk
 Blynk.virtualWrite(V2, h); //setting kelembapan di Blynk

}

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin(); //sensor mulai membaca suhu dan kelembapan
  timer.setInterval(1000, sendSensor); //waktu untuk mengirimkan data setiap 1 detik sekali

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
  

}
