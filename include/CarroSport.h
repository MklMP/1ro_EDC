#ifndef CARROSPORT_H
#define CARROSPORT_H

#include "header.h"

class CarroSport : public Carro {
private:
    int cantidadVelocidades;
    bool cambioUniversal;

public:
    CarroSport(string modelo,int idCarro, int plazas, double velocidad, string fechaSalida, Motor* motor, int cantidadVelocidades, bool cambioUniversal);
    
    double CalcularPrecioVenta() const override;
    int GetPlazas() const override;
    int GetCantVelocidades();
    bool GetCambioUniversal();
    void CaracteristicasPropiasCarro() const override;
};

#endif
