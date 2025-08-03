#include "../include/header.h"


MotorAlta::MotorAlta(string codigo, string fechaSalida, string especialista, int vecesReensamblado, 
                    double maxRevoluciones, double consumo) : Motor(codigo,fechaSalida,especialista,vecesReensamblado)
{
    this->maxRevoluciones=maxRevoluciones;
    this->consumo=consumo;
}

double MotorAlta::CalcularCosto() const 
{   
    double costo = (maxRevoluciones * 1.5 + consumo) - (100 * vecesReensamblado);

    if(costo < 0)
    {
        return 0;
    };

    return costo;
}

string MotorAlta::GetTipoMotor() const {
    return "Motor de Altas Revoluciones";
}

double MotorAlta::GetMaxRevoluciones() 
{
    return maxRevoluciones;
};

double MotorAlta::GetConsumo()
{
    return consumo;
};

void MotorAlta::CaracteristicasPropias() const{
    cout<<"-> Max. Revoluciones(min): "<<maxRevoluciones<<endl;
    cout<<"\t\t\t -> Consumo(Km*L): "<<consumo<<endl;
}