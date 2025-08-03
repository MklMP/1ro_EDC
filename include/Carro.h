#ifndef CARRO_H
#define CARRO_H

#include "header.h"
#include "Motor.h"

class Carro {
protected:
    string modelo;
    int plazas;
    double velocidad;
    string fechaSalida;
    Motor* motor;
    int idCarro;
    static int contCarros;

public:
    Carro(string modelo, int idCarro, int plazas, double velocidad, string fechaSalida, Motor* motor);
    virtual ~Carro() {}
    
    virtual void CaracteristicasPropiasCarro() const = 0;
    virtual double CalcularPrecioVenta() const = 0;
    void MostrarFichaTecnica() const;

    string GetModelo();
    string GetFechaSalida();
    virtual int GetPlazas() const = 0;
    double GetVelocidad();
    Motor* GetMotor() const;
    void SetMotor(Motor* newMotor);
    int GetId() const;
};



#endif
