#include <dht.h>

dht DHT;
 
#define DHT11_PIN 7

int ledPin = 8;
int ledPin2 = 10;
//int motorPin = 3;

void setup(){
 
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

/*
    pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
*/
  

}//end "setup()"
 
void loop(){
  //Start of Program 
 
    
    int dht = DHT.read11(DHT11_PIN);
    int vlhko = DHT.humidity;
    Serial.print("Humidity = ");
    Serial.print(DHT.humidity);
    Serial.println("%");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("°C");
/*
  pinMode(LED_N_SIDE, OUTPUT);
  pinMode(LED_P_SIDE, OUTPUT);
  digitalWrite(LED_N_SIDE, HIGH);
  digitalWrite(LED_P_SIDE, LOW);
*/
    if(vlhko < 33)
    {Serial.println("Irrigation ON");
    digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, LOW);


/*MOTOREK
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
*/
      
      
    }

    else if(vlhko >= 33)
    {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    Serial.println("Irrigation OFF");
 
}
    Serial.println("");

    
    delay(5000);//Wait 5 seconds before accessing sensor again.
}
  //Fastest should be once every two seconds.


