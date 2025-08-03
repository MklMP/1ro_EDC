#ifndef CARROOMNIBUS_H
#define CARROOMNIBUS_H

#include "header.h"

class CarroOmnibus : public Carro {
private:
    int cantidadPuertas;

public:
    CarroOmnibus(string modelo,int idCarro, double velocidad, string fechaSalida, Motor* motor, int cantidadPuertas);
    
    double CalcularPrecioVenta() const override;
    int GetPlazas() const override;
    int GetCantPuertas();
    void CaracteristicasPropiasCarro() const override;
};

#endif
