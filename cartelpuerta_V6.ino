
#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include <SoftwareSerial.h>
#include "SystemFont5x7.h"
#include "Arial_Black_16_ISO_8859_1.h"

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 3// Cantidad de display instalados
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
#define st50 50
SoftwareSerial mySerial (2, 3);
typedef char stc[st50];
stc texto;
#define Pi0 4
stc MS1="ESCUELA TECNICA 21 DE 10";
stc MS2="Mantener la Puerta Cerrada";
stc MS3="ANIVERSARIO 80 - 2025";
int cont=0;

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}
void dBit(int puerto, int valor){
          if(valor==1){digitalWrite(puerto,HIGH);}
          else{digitalWrite(puerto,LOW);}
      }
void puerta_open(){dBit(Pi0,0);
                  // dBit(Pi1,0);
                   }  
void puerta_close(){
                    dBit(Pi0,1);
                   // dBit(Pi1,1);
                    }       
void setup(void)
{
 pinMode(Pi0,OUTPUT); 
   //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
   Timer1.initialize( 3000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  Serial.begin(9600);
   mySerial.begin(9600);
  
}


class Tiempo{
  private:
  long t1,t2;
  bool estado;
  long offset;
  bool clave;
  public:
  Tiempo(int dato){ t1=millis();offset=dato;t2=t1+offset; estado=false;clave=true;}
  void start(){estado=false;t1=millis();t2=t1+offset;clave=true;} 
  bool runn(){ if(clave){// metodo de un paso 
               t1=millis(); 
               if(t2<t1){ 
                         estado=true; 
                         //Serial.println("Cambio de estado");
                         } 
                         return estado;
              }
              }
  bool play(){ if(clave){// metodo repetidor ciclico 
               t1=millis(); 
               if(t2<t1){ 
                         estado=true; 
                         t2=t1+offset;
                         //Serial.println("Cambio de estado");
                         } 
                else{estado=false;}         
                         return estado;
              }
              }            
  void stp(){clave=false;}            
  };

void loop(void)
{  bool clave=false;
   int contador=0;
   stc msj;
   Tiempo t1(30);
   Tiempo t2(20000);
   Tiempo t3(10000);
   dmd.clearScreen( true );
   dmd.selectFont(Arial_Black_16_ISO_8859_1);
   // Français, Österreich, Magyarország
   
   dmd.drawMarquee(texto,strlen(texto),(32*DISPLAYS_ACROSS)-1,0);
   t1.start();  
   t2.start(); 
   Serial.println("Cartel en Linea ");
   while(1){  
         if(t3.runn()){ puerta_open();}
         else{puerta_close();}
        //**************************cada 30mseg actualiza estado del cartel
        if(t1.runn()){ dmd.stepMarquee(-1,0);  t1.start();}
       //***************************Atiende la entrada de informacion************
        if(Serial.available()>0){ int y; char key=Serial.read();Serial.print(key);t1.stp();t2.stp();y=key; t3.start();
            if(y>0){strcpy(texto,"Tarjeta OK Empuje la Puerta"); dmd.clearScreen( true );dmd.drawMarquee(texto,strlen(texto),(32*DISPLAYS_ACROSS)-1,0);t1.start(); t2.start();}
        }
        //**********************Msj de informacion
        if(t2.play()){
            contador++;
            switch(contador){
              case 1: strcpy(texto,MS1);Serial.println("msj1");break;
              case 2: strcpy(texto,MS2);Serial.println("msj2");break;
              case 3: strcpy(texto,MS3);Serial.println("msj3");break;
              case 4: contador=0;break;
              
              }
           dmd.clearScreen( true );
         // dmd.selectFont(Arial_Black_16_ISO_8859_1);
          dmd.drawMarquee(texto,strlen(texto),(32*DISPLAYS_ACROSS)-1,0);   
           t2.start(); 
        }
        //******************SERIAL VIRTUAL
        if(mySerial.available() > 0){ int y;char key=mySerial.read();Serial.print(key);t1.stp();t2.stp();y=key; t3.start();
            if(y>0){ strcpy(texto," Tarjeta OK Tire de la Puerta"); dmd.clearScreen( true );dmd.drawMarquee(texto,strlen(texto),(32*DISPLAYS_ACROSS)-1,0); t1.start();  t2.start();}
            }
           
   }}
