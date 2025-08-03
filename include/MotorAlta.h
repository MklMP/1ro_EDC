#ifndef MOTOR_ALTA_H
#define MOTOR_ALTA_H

#include "header.h"
#include "Motor.h"

class MotorAlta : public Motor {
private:
    double maxRevoluciones;
    double consumo;

public:
    MotorAlta(string codigo, string fechaSalida, string especialista, int vecesReensamblado,
              double maxRevoluciones, double consumo);
    
    double CalcularCosto() const override;
    
    double GetMaxRevoluciones();
    double GetConsumo();
    string GetTipoMotor() const override; 
    void CaracteristicasPropias() const override;
};

#endif
