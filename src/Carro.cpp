#include "../include/header.h"

Carro::Carro(string modelo, int idCarro, int plazas, double velocidad, string fechaSalida, Motor* motor)
{
    this->modelo=modelo;
    this->idCarro=idCarro;
    this->plazas=plazas;
    this->velocidad=velocidad;
    this->fechaSalida=fechaSalida;
    this->motor=motor;
}

void Carro::MostrarFichaTecnica() const {
    cout <<BLUE<<"--------------------------------------"<<endl;
    cout <<"        FICHA TECNICA DEL VEHICULO:   "<<endl;
    cout <<"--------------------------------------"<<endl;
    cout <<"Modelo: " << modelo <<endl;
    cout <<"Fecha de salida: " << fechaSalida <<endl;
    cout <<"Plazas: " << GetPlazas() <<endl;
    cout <<"Velocidad: " << velocidad <<" km/h"<<endl;
    cout <<"Caracteristicas Propias: ";
            CaracteristicasPropiasCarro();
    cout <<"Costo de Venta: "<< CalcularPrecioVenta()<<" $$"<<endl;
    cout <<"--------------------------------------"<<endl;
    cout <<RESET;
    motor->MostrarFichaTecnica();
}

string Carro::GetModelo()
{
    return modelo;
}

string Carro::GetFechaSalida()
{
    return fechaSalida;
}

Motor* Carro::GetMotor() const
{
    return motor;
}
void Carro::SetMotor(Motor* nuevoMotor) {
    motor = nuevoMotor;
}

double Carro::GetVelocidad()
{
    return velocidad;
}

int Carro::GetId() const
{
    return idCarro;
}

int Carro::contCarros = 0;

