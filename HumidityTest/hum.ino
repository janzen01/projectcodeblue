#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(115200);
}

loop()
{
    Serial.print("Vlhkost je ");
    Serial.println(dht);
    Serial.println("%");
delay(10000);
}