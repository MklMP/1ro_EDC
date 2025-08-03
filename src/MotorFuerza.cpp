#include "../include/header.h"

MotorFuerza::MotorFuerza(string codigo, string fechaSalida, string especialista, int vecesReensamblado,
    int cantCaballosFuerza) : Motor(codigo, fechaSalida, especialista, vecesReensamblado)
{
    this->cantCaballosFuerza=cantCaballosFuerza;
};

double MotorFuerza::CalcularCosto() const
{
    double costo = (cantCaballosFuerza * 5) - (100 * vecesReensamblado);

    if(costo < 0)
    {
        return 0;
    };

    return costo;
}

int MotorFuerza::GetCantCaballosFuerza()
{
    return cantCaballosFuerza;
}

string MotorFuerza::GetTipoMotor() const {
    return "Motor de Fuerza";
}

void MotorFuerza::CaracteristicasPropias() const{
    cout<<"-> Cant. Caballos de Fuerza: "<<cantCaballosFuerza<<endl;
}