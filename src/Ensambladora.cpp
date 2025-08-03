#include "../include/header.h"

Ensambladora::Ensambladora(int planMotores, int planCarros) {
    this->planCarros = planCarros;
    this->planMotores = planMotores;
}

Ensambladora::~Ensambladora() {
    for (Motor* motor : motoresDisponibles) delete motor;
    for (Carro* carro : carrosEnsamblados) delete carro;
}

//getter
int Ensambladora::GetPlanCarros(){return planCarros;}
int Ensambladora::GetPlanMotores(){return planMotores;}
vector<Motor*> Ensambladora::GetMotores(){return motoresDisponibles;}
vector<Motor*> Ensambladora::GetMotoresAux(){return motoresGuardadosAux;}
vector<Carro*> Ensambladora::GetCarros() {return carrosEnsamblados;}


// Se elimina el motor adecuado y se retorna (solo se borra una vez)
Motor* Ensambladora::GetMotor(string tipoMotor) {
    auto it = find_if(motoresDisponibles.begin(), motoresDisponibles.end(), [&](Motor* motor) {
        return (tipoMotor == "MotorAlta" && dynamic_cast<MotorAlta*>(motor)) ||
               (tipoMotor == "MotorFuerza" && dynamic_cast<MotorFuerza*>(motor)) ||
               (tipoMotor == "MotorTrabajo" && dynamic_cast<MotorTrabajo*>(motor));
    });

    if (it != motoresDisponibles.end()) {
        Motor* motorElegido = *it; //se desreferencia el iterador y se le as
        motoresDisponibles.erase(it);  // Se elimina la primera instancia encontrada
        return motorElegido;
    }
    return nullptr;  // No se encontró un motor adecuado
}

void Ensambladora::AgregarMotor(Motor* nuevoMotor) {
    if (!nuevoMotor) {
        cout << "Error: Motor inválido, no se puede agregar." << endl;
        return;
    }
    
    motoresDisponibles.push_back(nuevoMotor);  
    //lista auxiliar interna parra que lo s carros no se me queden sin motor al cargarlos
    motoresGuardadosAux.push_back(nuevoMotor);           
    cout << GREEN << "\nMotor agregado correctamente ->" 
         << YELLOW << " ID: " << nuevoMotor->GetCodigo() << RESET << endl;

    int contM=1;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout <<YELLOW<<"\t\t\t### Motores disponibles ###" <<RESET<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    for (const auto& motor : motoresDisponibles) {
        cout<<BLUE<<contM++<<".)"<<RESET<<" \t\t"<<motor->GetTipoMotor()<<" -> ID: " << motor->GetCodigo()<<endl;
    }

    sleep_for(milliseconds(100));
    system("cls");
}

void Ensambladora::EnsamblarCarro(Carro* carro) {
    if (!carro->GetMotor()) { //dif nptr
        cout <<RED<< "Error: El carro no tiene motor asignado." <<RESET<< endl;
        return;
    }
    carrosEnsamblados.push_back(carro);
   
    cout << "Carro ensamblado correctamente con el motor: " 
         << carro->GetMotor()->GetTipoMotor() 
         << " -> Vehiculo: " << carro->GetModelo() << endl;

}

void Ensambladora::ListarIDCarros()
{   
    int contC=1;
    for(const auto& carro : carrosEnsamblados)
    {
        cout<<BLUE<<contC++<<")"<<RESET<<" \t\t"<<carro->GetModelo()<<" -> ID: " << carro->GetId()<<endl;
    }
    cout<<"------------------------------------------------------------"<<endl;
}

void Ensambladora::DarDeBajaCarro(int codigoCarro) {

    auto it = find_if(carrosEnsamblados.begin(), carrosEnsamblados.end(), [&](Carro* carro) {
        return carro->GetId() == codigoCarro;
    });

    if (it != carrosEnsamblados.end()) {
        
        Carro* carroEliminado = *it;
        // Capturar el motor asignado antes de borrar el carro.
        Motor* motorSacado = carroEliminado->GetMotor();
        
        // Si el carro es de lujo, se requiere que el motor deje de ser "artesanal".
        if (dynamic_cast<CarroLujo*>(carroEliminado) != nullptr) {
            // Se asume que el motor de un carro de lujo es de tipo MotorTrabajo.
            MotorTrabajo* motorTrabajo = dynamic_cast<MotorTrabajo*>(motorSacado);
            if (motorTrabajo != nullptr) {
                motorTrabajo->SetEsArtesanal(false);
                cout <<YELLOW<< "El motor ahora deja de ser artesanal, puesto que el carro era de lujo." << RESET<<endl;
            }
        }
        
        
        delete carroEliminado;
        carrosEnsamblados.erase(it);
        cout <<GREEN<< "\nCarro con código " << codigoCarro << " ha sido dado de baja." <<RESET<< endl;
        
        
        motoresDisponibles.push_back(motorSacado);
    } else {
        cout <<RED<< "\nNo se encontró el carro con código " << codigoCarro << "." << RESET<<endl;
    }
}

void Ensambladora::MostrarFichaTecnicaCarros() const {
    cout << "Ficha técnica de todos los carros:\n";
    int cont = 0;
    for (const auto& carro : carrosEnsamblados) {
        carro->MostrarFichaTecnica();
        cont++;
    }
    cout << "----------------------------------" << endl;
    cout <<GREEN<<"Cant. Total de Carros Ensamblados: "<<cont<<RESET<<endl; 
    cout << "----------------------------------" << endl;
}

void Ensambladora::MostrarCarrosReensamblados() const {
    cout <<GREEN<< "Carros con motores reensamblados:\n"<<RESET<<endl;
    int cont = 0;
    
    for (const auto& carro : carrosEnsamblados) {
        
        CarroLujo* carroNoLujo = dynamic_cast<CarroLujo*>(carro);
        
        if(carroNoLujo != carro)
        {
            if (carro->GetMotor()->GetVecesReensamblado() > 0) {
                
                carro->MostrarFichaTecnica();    
                cont++;
            }
        }
    }
    
    cout << "----------------------------------" << endl;
    cout <<GREEN<<"Total Carros con motores reensamblados: "<<cont<<RESET<<endl;
    cout << "----------------------------------" << endl;
}

double Ensambladora::CalcularPorcentajeCumplimiento() const {
    if (planMotores == 0 || planCarros == 0) {
        return 0.0;
    }
    double porcentajeMotores = (static_cast<double>(motoresDisponibles.size()) / planMotores) * 100;
    double porcentajeCarros = (static_cast<double>(carrosEnsamblados.size()) / planCarros) * 100;
    return (porcentajeMotores + porcentajeCarros) / 2;
}

double Ensambladora::CalcularGanancias() const {
    double totalGanancias = 0;
    for (const auto& carro : carrosEnsamblados) {
        totalGanancias += carro->CalcularPrecioVenta();
    }
    return totalGanancias;
}

void Ensambladora::MostrarMotoresDisponibles() const {
    
    int cont = 0;
    for (const auto& motor : motoresDisponibles) {
        motor->MostrarFichaTecnica();
        cont++;
    }
    cout << "----------------------------------" << endl;
    cout <<GREEN<< "   Motores disponibles:" <<cont<<RESET<<endl;
    cout << "----------------------------------" << endl;
}

void Ensambladora::MostrarCarrosRapidos() const {
    
    int cont = 0;
    cout << "Carros con velocidad mayor a 150 km/h: " <<endl;
    for (const auto& carro : carrosEnsamblados) {
        if (carro->GetVelocidad() > 150) {
            carro->MostrarFichaTecnica();
            cont++;
        }
    }
    cout << "----------------------------------" << endl;
    cout <<GREEN<< "   Total Carros Rápidos:" <<cont<<RESET<<endl;
    cout << "----------------------------------" << endl;
}

void Ensambladora::MostrarOmnibusMayorCapacidad() const {
    Carro* mayorCapacidad = nullptr;
    for (const auto& carro : carrosEnsamblados) {
        if (auto omnibus = dynamic_cast<CarroOmnibus*>(carro)) {
            if (!mayorCapacidad || omnibus->GetPlazas() > mayorCapacidad->GetPlazas()) {
                mayorCapacidad = omnibus;
            }
        }
    }

    if (mayorCapacidad) {
        cout << "Ómnibus con mayor capacidad:" <<endl;
        mayorCapacidad->MostrarFichaTecnica();
    } else {
        cout << "No hay ómnibus ensamblados." << endl;
    }
}

