#include <dht.h>

dht DHT;
 
#define DHT11_PIN 7

void setup(){
 
  Serial.begin(115200);
  
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    
    int dht = DHT.read11(DHT11_PIN);
    
    Serial.print("Humidity = ");
    Serial.print(DHT.humidity);
    Serial.println("%");




    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}