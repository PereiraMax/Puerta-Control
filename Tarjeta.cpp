#include <arduino.h>
#include "tarjeta.h"
/************************************************************************************************************/

Tarjeta::Tarjeta(){
    this->msj=true;
    this->puerta=false;
    if(this->msj){
    Serial.println("Sistema de Tarjetas");}
    }
int Tarjeta::validar(uint8_t valor[8]){
  int cont=0;
   if(valor[0]==35 &&  valor[1]==225 && valor[2]==35 && valor[3]==28){this->puerta=true; return 1;}
   if(valor[0]==03 &&  valor[1]==204 && valor[2]==121 && valor[3]==250){this->puerta=true; return 2;}
   if(valor[0]==03 &&  valor[1]==161 && valor[2]==145 && valor[3]==250){this->puerta=true; return 3;}
   
   if(valor[0]==35 &&  valor[1]==208 && valor[2]==133 && valor[3]==250){this->puerta=true; return 4;}
   if(valor[0]==243 &&  valor[1]==00 && valor[2]==145 && valor[3]==250){this->puerta=true; return 5;}
   if(valor[0]==115 &&  valor[1]==179 && valor[2]==115 && valor[3]==250){this->puerta=true; return 6;}

   if(valor[0]==163 &&  valor[1]==232 && valor[2]==130 && valor[3]==250){this->puerta=true; return 7;}
   if(valor[0]==131 &&  valor[1]==59 && valor[2]==136 && valor[3]==250){this->puerta=true;return 8;}
   if(valor[0]==179 &&  valor[1]==13 && valor[2]==144 && valor[3]==250){this->puerta=true; return 9;}
   if(valor[0]==243 &&  valor[1]==107 && valor[2]==133 && valor[3]==250){this->puerta=true; return 10;}
   //--------------------------------------------------------------------------------------------------------------
   if(valor[0]==131 &&  valor[1]==66 && valor[2]==135 && valor[3]==250){this->puerta=true; return 11;}
   if(valor[0]==51 &&  valor[1]==239 && valor[2]==38 && valor[3]==247){this->puerta=true; return 12;}
   if(valor[0]==51 &&  valor[1]==159 && valor[2]==124 && valor[3]==250){this->puerta=true; return 13;}
   
   if(valor[0]==35 &&  valor[1]==128 && valor[2]==62 && valor[3]==250){this->puerta=true; return 14;}
   if(valor[0]==35 &&  valor[1]==60 && valor[2]==119 && valor[3]==250){this->puerta=true; return 15;}
   if(valor[0]==51 &&  valor[1]==204 && valor[2]==66 && valor[3]==247){this->puerta=true; return 16;}

   if(valor[0]==163 &&  valor[1]==178 && valor[2]==120 && valor[3]==250){this->puerta=true; return 17;}
   if(valor[0]==211 &&  valor[1]==27 && valor[2]==115 && valor[3]==250){this->puerta=true; return 18;}
   if(valor[0]==115 &&  valor[1]==215 && valor[2]==116 && valor[3]==250){this->puerta=true; return 19;}
   if(valor[0]==03 &&  valor[1]==71 && valor[2]==117 && valor[3]==250){this->puerta=true; return 20;}
   //----------------------------------------------------------------------------------------------------------------
   if(valor[0]==243 &&  valor[1]==64 && valor[2]==119 && valor[3]==250){this->puerta=true; return 21;}
   if(valor[0]==51 &&  valor[1]==219 && valor[2]==125 && valor[3]==250){this->puerta=true; return 22;}
   if(valor[0]==147 &&  valor[1]==247 && valor[2]==114 && valor[3]==250){this->puerta=true; return 23;}
   
   if(valor[0]==163 &&  valor[1]==108 && valor[2]==95 && valor[3]==250){this->puerta=true; return 24;}
   if(valor[0]==35 &&  valor[1]==181 && valor[2]==120 && valor[3]==250){this->puerta=true; return 25;}
   if(valor[0]==147 &&  valor[1]==99 && valor[2]==127 && valor[3]==250){this->puerta=true; return 26;}

   if(valor[0]==51 &&  valor[1]==177 && valor[2]==112 && valor[3]==250){this->puerta=true; return 27;}
   if(valor[0]==227 &&  valor[1]==207 && valor[2]==49 && valor[3]==250){this->puerta=true; return 28;}
   if(valor[0]==51 &&  valor[1]==162 && valor[2]==124 && valor[3]==250){this->puerta=true; return 29;}
   if(valor[0]==3 &&  valor[1]==237 && valor[2]==55 && valor[3]==247){ this->puerta=true;return 30;}
   //----------------------------------------------------------------------------------------------------------------
   if(valor[0]==51 &&  valor[1]==169 && valor[2]==133 && valor[3]==250){this->puerta=true; return 31;}
   if(valor[0]==82 &&  valor[1]==42  && valor[2]==48 && valor[3]==250){ this->puerta=true; return 32;}
   if(valor[0]==3 &&  valor[1]==131 && valor[2]==80 && valor[3]==250){ this->puerta=true;return 33;}
   
   if(valor[0]==211  &&  valor[1]==205 && valor[2]==67 && valor[3]==247){this->puerta=true; return 34;}
   if(valor[0]==195 &&  valor[1]==143 && valor[2]==81 && valor[3]==250){ this->puerta=true; return 35;}
   if(valor[0]==83 &&  valor[1]==99 && valor[2]==86 && valor[3]==250){   this->puerta=true;return 36;}

   if(valor[0]==35 &&  valor[1]==42 && valor[2]==38 && valor[3]==247){  this->puerta=true; return 37;}
   if(valor[0]==35 &&  valor[1]==61 && valor[2]==38 && valor[3]==247){  this->puerta=true; return 38;}
   if(valor[0]==227 &&  valor[1]==78 && valor[2]==126 && valor[3]==250){this->puerta=true; return 39;}
   if(valor[0]==163 &&  valor[1]==51 && valor[2]==121 && valor[3]==250){this->puerta=true; return 40;}
   //----------------------------------------------------------------------------------------------------------------
   if(valor[0]==211 &&  valor[1]==159 && valor[2]==131 && valor[3]==250){this->puerta=true; return 41;}
   if(valor[0]==211 &&  valor[1]==32  && valor[2]==144 && valor[3]==250){this->puerta=true; return 42;}
   if(valor[0]==227 &&  valor[1]==32 && valor[2]==117 && valor[3]==250){ this->puerta=true; return 43;}
   
   if(valor[0]==243  &&  valor[1]==154 && valor[2]==80 && valor[3]==250){this->puerta=true; return 44;}
   if(valor[0]==147 &&  valor[1]==203 && valor[2]==122 && valor[3]==250){this->puerta=true; return 45;}
   if(valor[0]==83 &&  valor[1]==106 && valor[2]==95 && valor[3]==250){  this->puerta=true; return 46;}

   if(valor[0]==131&&  valor[1]==170 && valor[2]==115 && valor[3]==250){ this->puerta=true; return 47;}
   if(valor[0]==51 &&  valor[1]==49 && valor[2]==135 && valor[3]==250){  this->puerta=true; return 48;}
   if(valor[0]==195 &&  valor[1]==99 && valor[2]==38 && valor[3]==247){  this->puerta=true; return 49;}
   if(valor[0]==83 &&  valor[1]==179 && valor[2]==144 && valor[3]==250){ this->puerta=true; return 50;}
   if(valor[0]==131 &&  valor[1]==145 && valor[2]==107 && valor[3]==250){this->puerta=true; return 51;}
   //-----------------------------------------------------------------------Tarjetas-----------------------------------
   if(valor[0]==83 &&  valor[1]==203 && valor[2]==32 && valor[3]==148){ this->puerta=true; return 52;}
   if(valor[0]==195 &&  valor[1]==238  && valor[2]==166 && valor[3]==18){this->puerta=true; return 53;}
    if(valor[0]==211 &&  valor[1]==191  && valor[2]==81 && valor[3]==28){this->puerta=true; return 54;}
   this->puerta=false;
   return 0;
  }    
  bool Tarjeta::getPuerta(){return this->puerta;}
/*************************************************************************************************************/  
