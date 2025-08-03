#ifndef MOTOR_FUERZA_H
#define MOTOR_FUERZA_H

#include "header.h"


class MotorFuerza : public Motor {
private:
    int cantCaballosFuerza;

public:
    MotorFuerza(string codigo, string fechaSalida, string especialista, int vecesReensamblado,
                int cantCaballosFuerza);
    MotorFuerza(){};
    
    
    double CalcularCosto() const override;
    void CaracteristicasPropias() const override;
    string GetTipoMotor() const override;
    int GetCantCaballosFuerza();
    
};

#endif
