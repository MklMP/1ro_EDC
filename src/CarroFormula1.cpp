#include "../include/header.h"

CarroFormula1::CarroFormula1(string modelo, int idCarro, double velocidad, string fechaSalida, Motor* motor,
                             double pesoCarroceria) : Carro(modelo,idCarro,plazas,velocidad,fechaSalida,motor)
{
    this->pesoCarroceria=pesoCarroceria;
}

double CarroFormula1::CalcularPrecioVenta() const
{
    double precio =  velocidad * 5 + (1 / pesoCarroceria) + motor->CalcularCosto();

    if(precio < 0)
    {
        return 0;
    };

    return precio;
}

double CarroFormula1::GetPesoCarroceria()
{
    return pesoCarroceria;
}

int CarroFormula1::GetPlazas() const
{
    return plazas;
}

void CarroFormula1::CaracteristicasPropiasCarro() const
{
    cout<<"-> Peso de Carroceria: "<<pesoCarroceria<<" Kg"<<endl;
}