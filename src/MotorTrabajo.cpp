#include "../include/header.h"


MotorTrabajo::MotorTrabajo(string codigo, string fechaSalida, string especialista, int vecesReensamblado, bool esArtesanal)
    : Motor(codigo, fechaSalida, especialista, vecesReensamblado)
{
    this->esArtesanal=esArtesanal;
}

double MotorTrabajo::CalcularCosto() const {

    double costoBase = 1000 - (100 * vecesReensamblado);

    double costo = esArtesanal ? costoBase * 10 : costoBase;

    if(costo < 0)
    {
        return 0;
    };

    return costo;
}

string MotorTrabajo::GetTipoMotor() const {
    return "Motor de Trabajo";
}

bool MotorTrabajo::GetEsArtesanal()
{
    return esArtesanal;
}

void MotorTrabajo::CaracteristicasPropias() const{
    
    cout<<"-> Es Artesanal: "<<esArtesanal<<endl;
}

void MotorTrabajo::SetEsArtesanal(bool ban)
{
    esArtesanal=ban;
}
