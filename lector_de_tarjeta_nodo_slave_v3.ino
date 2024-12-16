// Código de prueba próximamente  
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_PN532.h>
#include "Tarjeta.h"
#define PN532_IRQ (2)//adaptacion para node 2  arduino 2
#define PN532_RESET (0)//adaptacion para node 0  arduino 3

// Interfaz de comunicación por I2C
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);
Tarjeta t1;
 int MDO=14;
 int pinLR=12;
 int pinLG=13;
 int pinLB=15;
 bool enviar=false;
void dBit(int puerto, int valor){
          if(valor==1){digitalWrite(puerto,HIGH);}
          else{digitalWrite(puerto,LOW);}
      }
void color(int valor){
      switch(valor){
                     case 0: dBit(pinLR,0);dBit(pinLG,0);dBit(pinLB,0);break;
                     case 1: dBit(pinLR,0);dBit(pinLG,0);dBit(pinLB,1);break;
                     case 2: dBit(pinLR,0);dBit(pinLG,1);dBit(pinLB,0);break;
                     case 3: dBit(pinLR,0);dBit(pinLG,1);dBit(pinLB,1);break;
                     case 4: dBit(pinLR,1);dBit(pinLG,0);dBit(pinLB,0);break;
                     case 5: dBit(pinLR,1);dBit(pinLG,0);dBit(pinLB,1);break;
                     case 6: dBit(pinLR,1);dBit(pinLG,1);dBit(pinLB,0);break;     
                     case 7: dBit(pinLR,1);dBit(pinLG,1);dBit(pinLB,1);break;          
        }
      }        
void setup(void) {
 pinMode(MDO,OUTPUT);
 pinMode(pinLR,OUTPUT);
 pinMode(pinLG,OUTPUT);
 pinMode(pinLB,OUTPUT);
 dBit(MDO,1);
 Serial.begin(9600);
 nfc.begin();
 uint32_t versiondata = nfc.getFirmwareVersion();
 delay(1000);
 if (! versiondata) {color(1);Serial.print("PN53x no encontrado");color(0); }
 dBit(MDO,0); 
 Serial.print("Encontró el chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
 Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
 Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
 nfc.setPassiveActivationRetries(0xFF);
 nfc.SAMConfig();
 Serial.println("Esperando tarjeta ISO14443A"); 
 dBit(MDO,1); 
}

// Funcion auxiliar para mostrar el buffer
void printArray(byte *buffer, byte bufferSize) {
   for (byte i = 0; i < bufferSize; i++) {
      Serial.print(buffer[i] < 0x10 ? " 0" : " ");
     // Serial.print(buffer[i], HEX);
      Serial.print(buffer[i]);
   }
} 

void loop(void) {
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;
  
   color(1);
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
    if (success) { 
       t1.validar(uid); 
       color(t1.getPuerta()==true? 4 : 2); 
       if(t1.getPuerta() ){ //t1.getPuerta()
                  Serial.println(t1.getPuerta());
                // Serial.print(" T =");delay(100);
               // Serial.println(t1.validar(uid));delay(1000);
       }
       delay(3000);
    }
    
}
