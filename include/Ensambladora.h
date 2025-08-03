#pragma once
#ifndef ENSAMBLADORA_H
#define ENSAMBLADORA_H

#include "header.h"

class Ensambladora {
private:
    
    vector<Motor*> motoresDisponibles;
    vector<Carro*> carrosEnsamblados;
    vector<Motor*> motoresGuardadosAux;
    int planMotores;
    int planCarros;
    
public:
    Ensambladora(int planMotores, int planCarros);
    ~Ensambladora();

    int GetPlanMotores();
    int GetPlanCarros();
    vector<Carro*> GetCarros();
    vector<Motor*> GetMotores();
    vector<Motor*> GetMotoresAux();
    void AgregarMotor(Motor* motor);
    void EnsamblarCarro(Carro* carro);
    void MostrarMotoresDisponibles() const;
    void MostrarCarrosRapidos() const;  // son los > 150 km/h
    void MostrarOmnibusMayorCapacidad() const;
    void MostrarFichaTecnicaCarros() const;
    void DarDeBajaCarro(int codigoCarro);
    void MostrarCarrosReensamblados() const;
    double CalcularPorcentajeCumplimiento() const;
    double CalcularGanancias() const;
    void ListarIDCarros();

    Motor* GetMotor(string tipoMotor);
    

};

#endif
