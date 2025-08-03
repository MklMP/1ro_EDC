#include "../include/header.h"

CarroLujo::CarroLujo(string modelo, int idCarro, int plazas, double velocidad, string fechaSalida, Motor* motor, double costoTapiceria)
    : Carro(modelo,idCarro,plazas, velocidad, fechaSalida, motor)
{
    this->costoTapiceria=costoTapiceria;
};

double CarroLujo::CalcularPrecioVenta() const {
    double precio = (costoTapiceria + motor->CalcularCosto()) * 10;

    if(precio < 0)
    {
        return 0;
    };

    return precio;
}


double CarroLujo::GetCostoTapiceria()
{
    return costoTapiceria;
}

int CarroLujo::GetPlazas() const
{
    return plazas;
}

void CarroLujo::CaracteristicasPropiasCarro() const
{
    cout<<"-> Costo Tapiceria: "<<costoTapiceria<<" $$"<<endl;
}