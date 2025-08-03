#ifndef MOTOR_TRABAJO_H
#define MOTOR_TRABAJO_H

#include "header.h"
#include "Motor.h"

class MotorTrabajo : public Motor {
private:
    bool esArtesanal;

public:
    MotorTrabajo(string codigo, string fechaSalida, string especialista, int vecesReensamblado,
              bool esArtesanal);
    
    double CalcularCosto() const override;
    void CaracteristicasPropias() const override;
    string GetTipoMotor() const override;
    bool GetEsArtesanal();
    void SetEsArtesanal(bool ban);
};

#endif
