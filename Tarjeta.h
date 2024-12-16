#include <arduino.h>
#ifndef Tarjeta_h
#define Tarjeta_h
class Tarjeta{
  private:
  uint8_t date[7];
  bool puerta;
  int msj;
  public:
  Tarjeta();
  int validar(uint8_t valor[8]);    
  bool getPuerta();
};
#endif
