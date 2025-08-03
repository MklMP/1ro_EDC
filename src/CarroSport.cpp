#include "../include/header.h"

CarroSport::CarroSport(string modelo, int idCarro, int plazas, double velocidad, string fechaSalida, Motor* motor, int cantidadVelocidades, bool cambioUniversal)
    : Carro(modelo, idCarro, plazas, velocidad, fechaSalida, motor)
{
    this->cantidadVelocidades=cantidadVelocidades;
    this->cambioUniversal=cambioUniversal;
}

double CarroSport::CalcularPrecioVenta() const {
    return cantidadVelocidades * 2 + motor->CalcularCosto() + (cambioUniversal ? 1000 : 0);
}

int CarroSport::GetCantVelocidades()
{
    return cantidadVelocidades;
}

bool CarroSport::GetCambioUniversal()
{
    return cambioUniversal;
}

int CarroSport::GetPlazas() const
{
    return plazas;
}

void CarroSport::CaracteristicasPropiasCarro() const
{
    cout<<"-> Cant. Velocidades de Caja: "<<cantidadVelocidades<<endl;
    cout<<"\t\t\t -> Cambio Universal:  "<<cambioUniversal<<endl;
}