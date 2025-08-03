#ifndef CARROFORMULA1_H
#define CARROFORMULA1_H

#include "header.h"

class CarroFormula1 : public Carro {
private:
    double pesoCarroceria;
    const int plazas = 1;

public:
    CarroFormula1(string modelo,int idCarro, double velocidad, string fechaSalida, Motor* motor, double pesoCarroceria);
    
    int GetPlazas() const override;
    double CalcularPrecioVenta() const override;
    double GetPesoCarroceria();
    void CaracteristicasPropiasCarro() const override;
};

#endif
