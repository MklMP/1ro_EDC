#ifndef CARROLUJO_H
#define CARROLUJO_H

#include "header.h"

class CarroLujo : public Carro {
private:
    double costoTapiceria;

public:
    CarroLujo(string modelo, int idCarro,int plazas, double velocidad, string fechaSalida, Motor* motor, double costoTapiceria);
    

    int GetPlazas() const override;
    double CalcularPrecioVenta() const override;
    double GetCostoTapiceria();
    void CaracteristicasPropiasCarro() const override;

};

#endif
