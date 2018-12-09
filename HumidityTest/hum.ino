#include <dht.h>
#include <DateTime.h>
#include <DateTimeStrings.h>

#define TIME_MSG_LEN  11   // time sync to PC is HEADER and unix time_t as ten ascii digits
#define TIME_HEADER  255

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

    getPCtime();

    if(dht < 40)
    Serial.println("Zavlazovani zap");
    Serial.println("");

    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.

void getPCtime() {
  // if time available from serial port, sync the DateTime library
  while(Serial.available() >=  TIME_MSG_LEN ){  // time message
    if( Serial.read() == TIME_HEADER ) {        
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++){   
        char c= Serial.read();          
        if( c >= '0' && c <= '9')   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number            
      }    
}
