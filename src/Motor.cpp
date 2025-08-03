#include "../include/header.h"


Motor::Motor(string codigo, string fechaSalida, string especialista, int vecesReensamblado)
{
    this->codigo=codigo;
    this->fechaSalida=fechaSalida;
    this->especialista=especialista;
    this->vecesReensamblado=vecesReensamblado;
}

void Motor::MostrarFichaTecnica() const {
    
    cout <<YELLOW<<"----------------------------------"<<endl;
    cout <<"        FICHA TECNICA DEL MOTOR: "<<endl;
    cout <<"----------------------------------"<<endl;
    cout <<"Tipo de Motor: "<< GetTipoMotor() << endl;
    cout <<"Codigo: " << codigo << endl;
    cout <<"Fecha de salida: " << fechaSalida <<endl;
    cout <<"Especialista: " << especialista << endl;
    cout <<"Veces reensamblado: " << vecesReensamblado <<endl;
    cout <<"Costo de Venta del Motor: " <<CalcularCosto()<<" $$"<<endl;
    cout <<"Caracteristicas Propias: "; 
            CaracteristicasPropias();
    cout <<"----------------------------------"<<endl;
    cout <<RESET;
}

string Motor::GetCodigo() const {
    return codigo;
}

int Motor::GetVecesReensamblado()
{
    return vecesReensamblado;
}

string Motor::GetFechaSalida()
{
    return fechaSalida;
}

string Motor::GetEspecialista()
{
    return especialista;
}