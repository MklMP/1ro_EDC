#include "../include/header.h"

CarroOmnibus::CarroOmnibus(string modelo,int idCarro, double velocidad, string fechaSalida, Motor* motor, 
    int cantidadPuertas) : Carro(modelo, idCarro, plazas, velocidad, fechaSalida, motor) 

{
    this->cantidadPuertas=cantidadPuertas;
}    


double CarroOmnibus::CalcularPrecioVenta() const {
    double precio =  (cantidadPuertas * 1.5 + motor->CalcularCosto()) * 3;

    if(precio < 0)
    {
        return 0; 
    };

    return precio;
}

int CarroOmnibus::GetPlazas() const
{
    // Verificar que el motor es de tipo MotorFuerza
    MotorFuerza* motorFuerza = dynamic_cast<MotorFuerza*>(motor);
    int plazas = 0;

    if (motorFuerza) {
        plazas = motorFuerza->GetCantCaballosFuerza() / 10;
    } else {
        cout<<"Este motor no es el Indicado para este Vehiculo!!"<<endl;
        plazas = 0;  // En caso de error, asignamos 0 plazas
    }
    
    return plazas;
}

int CarroOmnibus::GetCantPuertas()
{
    return cantidadPuertas;
}

void CarroOmnibus::CaracteristicasPropiasCarro() const
{
    cout<<"-> Cant. Puertas: "<<cantidadPuertas<<endl;
}
