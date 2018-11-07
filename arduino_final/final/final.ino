//DHT includes
#include "DHT.h"
#define DHTPIN 4     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

// mp3 inclu11des
#include <SPI.h>
#include <SdFat.h>
#include <FreeStack.h> 
#include <SFEMP3Shield.h>

SFEMP3Shield MP3player;
byte result;
SdFat sd;

float temp,humi;

int laserPin = 8;
int laserPin2 = 9;
int sensorPin = 2; //define analog pin 2
int sensorPin2 = 3; //define analog pin 3
int value = 0; 
int value2 = 0;
int i = 0;
int analoog = A5; // define the flame sensor interface

float sensor; //read analoog value

//char toSend;
void setup()
{ 
   analogReference(INTERNAL);
   Serial.begin(9600);
   dht.begin();
   pinMode (laserPin, OUTPUT); // define the digital output interface 13 feet
   pinMode (laserPin2, OUTPUT);

   pinMode (analoog, INPUT) ;// output interface defines the flame sensor


   if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) sd.initErrorHalt();
  
   result = MP3player.begin();
   MP3player.setVolume(10000,10000);
   delay(500);
}

void loop(){ 

   int err;
   float temp = dht.readTemperature();
   float humi = dht.readHumidity();
  
    //화단 보호 
   
   value2 = analogRead(sensorPin2);  // Turn Laser On
   digitalWrite (laserPin2, HIGH);
   sensor = analogRead(analoog);

   // Check if any reads failed and exit early (to try again).
   if (isnan(humi) || isnan(temp)) {
     Serial.println("Failed to read from DHT sensor!");
     return;
   }

   Serial.print("Humidity: ");
   Serial.print(humi);
   Serial.print(" %\t");
   Serial.print("Temperature: ");
   Serial.print(temp);
   Serial.print(" C ");
   Serial.println(" ");
   Serial.print("   ");
   Serial.print("조도 센서 수치 : ");
   Serial.println(value2, DEC);
   decide(temp, humi);
 
  
   Serial.print("   flame :");
   Serial.println(sensor);  // display tempature
   delay(1000);
}


void decide(float t_read, float h_read)
  {
    if(h_read>=95){
      MP3Play(4);
      Serial.println("트랙4 재생중");
    }
    else if(t_read>=28.2 && h_read>=51.55){
      MP3Play(3);
      Serial.println("트랙3 재생중");
    }
    else if(t_read>14.8 && t_read<24.8 && h_read<51.5){
      MP3Play(2);
      Serial.println("트랙2 재생중");
    }
    else if(t_read>12.9 && t_read<22.9 && h_read>=51.5){
      MP3Play(5);
      Serial.println("트랙5 재생중");
    }
    else if(t_read>=-6.1 && t_read<5.9 && h_read>=54.75){
      MP3Play(6);
      Serial.println("트랙6 재생중");
    }
    else if(t_read<=-4.1 && h_read<54.75){
      MP3Play(7);
      Serial.println("트랙7 재생중");
    }
    else{
      MP3Play(9); Serial.println("트랙9 재생중");
      MP3Play(3); Serial.println("트랙3 재생중");
    }
  }


void MP3Play(int trackNumber){
    MP3player.playTrack(trackNumber);

    //화단 침입 방지 
    if(value2 > 500){
      MP3player.stopTrack();
      MP3player.playTrack(0);  //화단 침입 sount playing
      Serial.println("   ********화단 침입 발생********");
      delay(3000);    
    }

    //화재 발생 대피 방송
    if(sensor > 10000){
      MP3player.stopTrack();
      MP3player.playTrack(1);
      Serial.print("********공원 내 화재 발생********");
      delay(5000);
   }
  
}
