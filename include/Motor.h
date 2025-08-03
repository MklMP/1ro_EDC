#ifndef MOTOR_H
#define MOTOR_H

#include "header.h"

class Motor {
protected:
    string codigo;
    string fechaSalida;
    string especialista;
    int vecesReensamblado;

public:
    Motor(){};
    Motor(string codigo, string fechaSalida, string especialista, int vecesReensamblado);
    virtual ~Motor(){}
    
    virtual string GetTipoMotor() const = 0;
    virtual double CalcularCosto() const = 0;
    void MostrarFichaTecnica() const;
    virtual void CaracteristicasPropias() const = 0;

    string GetCodigo() const;
    string GetFechaSalida();
    string GetEspecialista();
    int GetVecesReensamblado();
};

#endif
