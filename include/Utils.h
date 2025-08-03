#ifndef _UTILS_
#define _UTILS_

#include "header.h"
#include "Carro.h"
#include "CarroFormula1.h"
#include "CarroOmnibus.h"
#include "CarroSport.h"
#include "CarroLujo.h"

#include "Motor.h"
#include "MotorAlta.h"
#include "MotorFuerza.h"
#include "MotorTrabajo.h"

#include "Ensambladora.h"

const string nombre_de_mi_archivo_de_motores = "../data/MotorData.txt";
const string nombre_de_mi_archivo_de_carros = "../data/CarData.txt";

class Utils {
    public:

    static int GenerarNumeroEntre(unsigned int ini, unsigned int fin){
        srand(static_cast<unsigned int>(time(0)));
        int rini = min(ini, fin);
        int rfin = max(ini, fin);
        if(rfin == 0) rfin = 1;
        return rini + rand() % (rfin + 1 - rini);
    }

    static int ContarLineas(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
            return -1;
        }

        string linea;
        int contador = 0;
        while (getline(archivo, linea)) {
            contador++;
        }

        archivo.close();
        return contador;
    }

    static void Banner()
    {   
        string color_random = "\033[3"+to_string(GenerarNumeroEntre(1,6)) +"m";

        cout<<endl;
        cout<<color_random<<R"(        
                                                            **********************************
                                                            **    Ensambladora de Carros    **
                                                            **   _______ _____    ______    **
                                                            **  (_______|____ \  / _____)   **
                                                            **   _____   _   \ \| /         **
                                                            **  |  ___) | |   | | | V 1.0   **
                                                            **  | |_____| |__/ /| \_____    **
                                                            **  |_______)_____/  \______)   **
                                                            **                              **)";
        cout<<color_random<<"\n                                                            **"<<YELLOW<<"        By Mkl & JAV          "<<color_random<<"**"<<RESET<<endl;
        cout<<color_random<<"                                                            **********************************"<<RESET<<endl;
                
    }
    
    static void ShowMenu(int pM, int pC, int cantMotoresDisponibles, int cantCarrosEnsamblados) {
        

        int cantMotoresFabricados = ContarLineas(nombre_de_mi_archivo_de_motores);
        string color_random = "\033[3"+to_string(GenerarNumeroEntre(1,6)) +"m";

        cout <<CYAN<<"            ╔════════════════════════════════════════╗ "<<endl;                              
        cout <<"            ║"<<color_random<<"      #### MENÚ DEL SISTEMA ####        "<<CYAN<<"║ "<<endl;                         
        cout <<CYAN<<"            ╠════════════════════════════════════════╣ "<<endl; 
        cout <<CYAN<<"            ¦"<<color_random<<"    Plan Anual: -> Motores: "<<cantMotoresDisponibles+cantCarrosEnsamblados<<"/"<<pM<<CYAN<<"        ¦   "<<CYAN<<endl; 
        cout <<CYAN<<"            ¦"<<color_random<<"                -> Carros : "<<cantCarrosEnsamblados<<"/"<<pC<<CYAN<<"        ¦   "<<CYAN<<endl; 
        cout <<CYAN<<R"(            ╠════════════════════════════════════════╣                               
            ║   [1] Agregar Motor                    ║                     
            ║   [2] Ensamblar Carro                  ║                                                 _________            __   _
            ║   [3] Mostrar Carros Ensamblados       ║                            _______         _____/ |_||_\ |        _ __   / \)"<<endl;
        cout<<"            ║   [4] Mostrar Motores Disponibles ["<<YELLOW<<cantMotoresDisponibles<<CYAN<<"]  ║                           /|_||_\\\\`.___   //   _    _ _\\ \\     _ _      /_S_\\ "<<endl;
        cout<<CYAN<<R"(            ║   [5] Carros de Mayor Velocidad (150Km)║                     __   (   _    _ _\ \\ ```(_)------(_)-`==             |
            ║   [6] Ómnibus de Mayor Capacidad       ║            _____________==`-(_)------(_)-'___________________________     |
            ║   [7] Carros con Motores Reensamblados ║         _____   _____   _____   ______   ______   _____    ______   ____  | 
            ║   [8] Porcentaje de Cumplimiento       ║       ____________________________________________________________________|_    
            ║   [9] Dar Baja a un Vehículo           ║                        
            ║   [10] Ganancia Total                  ║                        
            ╠════════════════════════════════════════╣                                                                 By Mkl & JAV
            ║   [0] Guardar y Salir                  ║                                                             Version - 1.0   
            ╚════════════════════════════════════════╝ )";

        cout<<color_random<<"\n                                        Opción(#): "<<GREEN;
        
    }

    static void SelectionPanel(int planMotores,int planCarros)
    {
        Ensambladora ensambladora(planMotores, planCarros);
    
        system("chcp 65001 > nul"); 
        Utils::CargarDatos(ensambladora);

        int opcion;
        do {
            
            system("cls");

            int planMotoresAux = ensambladora.GetPlanMotores();
            int planCarrosAux = ensambladora.GetPlanCarros();

            int cantM = ensambladora.GetMotores().size();
            int cantC = ensambladora.GetCarros().size();

            Utils::Banner();
            Utils::ShowMenu(planMotoresAux, planCarrosAux,cantM,cantC);
            cin >> opcion;

            if (cin.fail()) 
            {
                cin.clear(); // Restablecer estado de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
                cerr <<RED<< "\t\t\n            Error: Entrada no valida. Por favor, ingrese un numero." << RESET<<endl;
                sleep_for(seconds(2));
                opcion = 123;   //estrategia jj 
                system("cls");
                continue; 
            }

            switch (opcion){
                case 1:
                    system("cls");
                    Utils::Banner();
                    Utils::AddMotor(ensambladora);

                    break;
                case 2:
                    system("cls");
                    Utils::Banner();
                    Utils::AddCarro(ensambladora);
                    break;
                case 3:
                    system("cls");
                    Utils::Banner();
                    ensambladora.MostrarFichaTecnicaCarros();
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
                    system("cls");
                    Utils::Banner();
                    ensambladora.MostrarMotoresDisponibles();
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 5:
                    system("cls");
                    Utils::Banner();
                    ensambladora.MostrarCarrosRapidos();
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 9:
                    system("cls");
                    Utils::Banner();
                    int id;
                    cout<<"## Dar Baja a un Vehiculo ##"<<endl;
                    ensambladora.ListarIDCarros();
                    
                    cout<<"Id del Carro: ";cin>>id;
                    ensambladora.DarDeBajaCarro(id);
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 7:
                    // Mostrar un listado con los carros que tengan motores re-ensamblados
                    system("cls");
                    Utils::Banner();
                    ensambladora.MostrarCarrosReensamblados();                
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 8:
                    // Porcentaje de cumplimiento de la planta.
                    system("cls");

                    Utils::Banner();
                    cout<<"Porcentaje de Cumplimiento entre Carros y Motores: ";
                    cout<<YELLOW<<ensambladora.CalcularPorcentajeCumplimiento()<<" %"<<endl<<RESET;
                    cout<<endl;
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 10:
                    system("cls");
                    Utils::Banner();
                    // Ganancia total de la ensambladora dividida por cada tipo
                    cout<<"Una Vez Vendido Los Carros >> Ganancia Total: ";
                    cout<<YELLOW<<"$ "<<ensambladora.CalcularGanancias()<<RESET<<endl;
                    cout << "Pulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 6:
                    //Omnibus de mayor capacidad
                    ensambladora.MostrarOmnibusMayorCapacidad();
                    cout <<"\n\nPulse una tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                case 0:
                    system("cls");
                    Utils::Banner();
                    Utils::GuardarDatos(ensambladora);
                    Utils::GuardarDatosHtml(ensambladora);
                    cout << "Datos guardados. Saliendo...\n"<<RESET;
                    break;
                default:
                    cout << RED << "                Opción inválida. Inténtalo de nuevo.\n" << RESET;
                    sleep_for(seconds(1));
                    break;
            }
        } while (opcion != 0);

    }
    
    static void AddMotor(Ensambladora& ensambladora)
    {   
        
        string codigo, fechaSalida, especialista;
        int vecesReensamblado, tipo,caballosFuerza;
        double revoluciones,consumo;
        bool artesanal;
        
        cout<<endl<<endl;
        cout <<CYAN<<">> "<<RESET<<"Tipo de motor -> ("<<YELLOW<<"1"<<RESET<<": Alta Revolucion, "<<YELLOW<<"2"<<RESET<<": Fuerza, "<<YELLOW<<"3"<<RESET<<": Trabajo): ";
        cin >> tipo;
        if(tipo==2){cout<<CYAN<<">> "<<RESET<<"Caballos de Fuerza: "; cin>>caballosFuerza;}
        else if(tipo==1){cout<<CYAN<<">> "<<RESET<<"RPM: "; cin>>revoluciones;
                        cout<<CYAN<<">> "<<RESET<<"Consumo(Km*L): ";cin>>consumo;}
        else if(tipo==3){cout<<CYAN<<">> "<<RESET<<"Es artesanal: "; cin>>artesanal;}
        else 
        {
            cout<<RED<<"ERROR: Entrada Invalida!! "<<RESET;
            sleep_for(seconds(8));
            return;
        }
        
        cout <<CYAN<<">> "<<RESET<<"Ingrese codigo de motor: ";
        cin >> codigo;
        cout <<CYAN<<">> "<<RESET<< "Ingrese fecha de salida (YYYY-MM-DD): ";
        cin >> fechaSalida;
        cout <<CYAN<<">> "<<RESET<< "Especialista a cargo: ";
        cin.ignore();
        getline(cin, especialista);
        cout <<CYAN<<">> "<<RESET<< "Numero de veces reensamblado: ";
        cin >> vecesReensamblado;

        Motor* nuevoMotor;
        if (tipo == 2) nuevoMotor = new MotorFuerza(codigo, fechaSalida, especialista, vecesReensamblado, caballosFuerza);
        else if (tipo == 1) nuevoMotor = new MotorAlta(codigo, fechaSalida, especialista, vecesReensamblado, revoluciones, consumo);
        else nuevoMotor = new MotorTrabajo(codigo, fechaSalida, especialista, vecesReensamblado, artesanal);

        ensambladora.AgregarMotor(nuevoMotor);
        Utils::GuardarDatos(ensambladora);//esto lo hago para que me actualice simplemente
        
    }

    static void AddCarro(Ensambladora& ensambladora)
    {   
        string modelo, fechaSalida;
        double velocidad, pesoCarroceria, costoTapiceria;
        int cantidadPuertas, tipoC, plazas, cantVelocidades;
        bool cambioUniversal;
        int idCarro = GenerarNumeroEntre(100000,999999);

        vector<Motor*> motoresDisponibles = ensambladora.GetMotores();

        if(motoresDisponibles.size() <= 0)
        {
            cout<<RED<<"--------------------------------------------------------------"<<RESET<<endl;
            cout<<RED<<"\nAun No se disponen de Motores para ensamblar un Vehiculo !!"<<RESET<<endl;
            cout<<RED<<"--------------------------------------------------------------"<<RESET<<endl;
            cout<<"\nPulse una tecla para continuar...";
            cin.ignore();
            cin.get();
            return;
        }

        cout << endl << endl;
        cout << CYAN << ">> " << RESET << "Tipo de Carro (" 
            << YELLOW << "1" << RESET << ": Formula1, " 
            << YELLOW << "2" << RESET << ": Omnibus, " 
            << YELLOW << "3" << RESET << ": Sport, " 
            << YELLOW << "4" << RESET << ": Lujo): ";
        cin >> tipoC;
        if (tipoC == 1) {
            cout << CYAN << ">> " << RESET << "Peso de Carroceria: "; 
            cin >> pesoCarroceria;
        }
        else if (tipoC == 2) {
            cout << CYAN << ">> " << RESET << "Cant. Puertas: "; 
            cin >> cantidadPuertas;
        }
        else if (tipoC == 3) {
            cout << CYAN << ">> " << RESET << "Cant. Velocidades: "; 
            cin >> cantVelocidades;
            cout << CYAN << ">> " << RESET << "Cambio Universal: "; 
            cin >> cambioUniversal;
        }
        else if (tipoC == 4) {
            cout << CYAN << ">> " << RESET << "Costo de la Tapiceria: "; 
            cin >> costoTapiceria;
        }
        else {
            cout << RED << "ERROR: Entrada Inválida" << RESET;
            sleep_for(seconds(1));
            return;
        }
        
        cout << CYAN << ">> " << RESET << "Ingrese modelo de carro: ";
        cin >> modelo;
        cout << CYAN << ">> " << RESET << "Ingrese velocidad máxima (km/h): ";
        cin >> velocidad;
        cout << CYAN << ">> " << RESET << "Ingrese fecha de salida (YYYY-MM-DD): ";
        cin >> fechaSalida;
        
        Carro* nuevoCarro = nullptr;
        Motor* motorAdecuado = nullptr;
        
        //itero enre los carros para verificar id y no repetirlos iD
        for(const auto& carro : ensambladora.GetCarros())
        {
            if(idCarro = (carro)->GetId())
            {
                idCarro = GenerarNumeroEntre(100000,999999);
            }//AQUI HAY un problema y es que puede coincidir el numero again aunque 
            // con esto hay menor probabilidad de coincidencia 
        }

        if (tipoC == 1) { // Fórmula 1 -> necesita un MotorAlta
            motorAdecuado = ensambladora.GetMotor("MotorAlta");
            nuevoCarro = new CarroFormula1(modelo, idCarro, velocidad, fechaSalida, motorAdecuado, pesoCarroceria);
        }
        else if (tipoC == 2) { // Ómnibus -> necesita un MotorFuerza
            motorAdecuado = ensambladora.GetMotor("MotorFuerza");
            nuevoCarro = new CarroOmnibus(modelo, idCarro, velocidad, fechaSalida, motorAdecuado, cantidadPuertas);
        }
        else if (tipoC == 3) { // Sport -> necesita un MotorTrabajo no artesanal
            motorAdecuado = ensambladora.GetMotor("MotorTrabajo");
            nuevoCarro = new CarroSport(modelo, idCarro, plazas, velocidad, fechaSalida, motorAdecuado, cantVelocidades, cambioUniversal);
        }
        else if (tipoC == 4) { // Lujo -> también usa MotorTrabajo, pero se requiere que sea artesanal
            motorAdecuado = ensambladora.GetMotor("MotorTrabajo");
            MotorTrabajo* motorTrabajo = dynamic_cast<MotorTrabajo*>(motorAdecuado);
            if (motorTrabajo != nullptr && motorTrabajo->GetEsArtesanal()) {
                // Si el motor es artesanal, asigna el carro de lujo
                nuevoCarro = new CarroLujo(modelo, idCarro, plazas, velocidad, fechaSalida, motorAdecuado, costoTapiceria);
            }
            else {
                // Si el motor no es artesanal, se asigna como Carro Sport  
                nuevoCarro = new CarroSport(modelo, idCarro, plazas, velocidad, fechaSalida, motorAdecuado, cantVelocidades, cambioUniversal);
                cout << YELLOW << "El motor no es artesanal. Se asignará como Carro Sport." << RESET << endl;
            }
        }
        
        cout << YELLOW << "\nVerificando motor asignado: " 
            << (motorAdecuado ? motorAdecuado->GetTipoMotor() : "Ninguno") 
            << RESET << endl;

        if ((dynamic_cast<MotorAlta*>(motorAdecuado) && dynamic_cast<CarroFormula1*>(nuevoCarro)) ||
            (dynamic_cast<MotorFuerza*>(motorAdecuado) && dynamic_cast<CarroOmnibus*>(nuevoCarro)) ||
            (dynamic_cast<MotorTrabajo*>(motorAdecuado) && (dynamic_cast<CarroSport*>(nuevoCarro) || dynamic_cast<CarroLujo*>(nuevoCarro))))
        {
            ensambladora.EnsamblarCarro(nuevoCarro);
            cout << GREEN << "Motor: " << motorAdecuado->GetTipoMotor() 
                << " -> Vehículo: " << nuevoCarro->GetModelo() << RESET << endl;
            cout << endl << endl;
            system("pause");
            cout << "Pulse Una Tecla Para Continuar...." << endl;
        } 
        else 
        {
            cout << RED << "Error: El motor no es compatible con el carro." << RESET << endl;
            delete nuevoCarro;
            cout << endl << endl;
            system("pause");
            cout << "Pulse Una Tecla Para Continuar...." << endl;
        }
    }

    static void GuardarDatosHtml(Ensambladora& ensambladora) {
        ofstream archivo("../Registro.html");
        if (!archivo) {
            cerr << "❌ No se pudo crear el archivo HTML." << endl;
            return;
        }

        archivo << R"(<!DOCTYPE html>
        <html lang="es">
        <head>
            <meta charset="UTF-8">
            <title>Ensambladora - Reporte</title>
            <link rel="stylesheet" type="text/css" href="Css/styles.css">
        </head>
        <body>
            <h1>📦 Reporte de la Fabrica</h1>
            <div class="wrapper">
                <div class="section">
        )";

        // Mostrar Motores
        archivo << "<h2>🔧 Motores Registrados</h2>\n";
        for (Motor* motor : ensambladora.GetMotoresAux()) {
            string tipo;
            string extra;

            if (auto alta = dynamic_cast<MotorAlta*>(motor)) {
                tipo = "MotorAlta";
                extra = "Revoluciones: " + to_string(alta->GetMaxRevoluciones()) + " | Consumo: " + to_string(alta->GetConsumo());
            } else if (auto fuerza = dynamic_cast<MotorFuerza*>(motor)) {
                tipo = "MotorFuerza";
                extra = "Caballos de Fuerza: " + to_string(fuerza->GetCantCaballosFuerza());
            } else if (auto trabajo = dynamic_cast<MotorTrabajo*>(motor)) {
                tipo = "MotorTrabajo";
                extra = string("Artesanal: ") + (trabajo->GetEsArtesanal() ? "Sí" : "No");
            }

            archivo << "<div class='motor'>\n";
            archivo << "<div><span class='etiqueta'>Tipo:</span> " << tipo << "</div>\n";
            archivo << "<div><span class='etiqueta'>Código:</span> " << motor->GetCodigo() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Especialista:</span> " << motor->GetEspecialista() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Veces Reensamblado:</span> " << motor->GetVecesReensamblado() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Fecha de Salida:</span> " << motor->GetFechaSalida() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Detalles:</span> " << extra << "</div>\n";
            archivo << "</div>\n";
        }
        archivo << "</div>\n";
        archivo << "<div class='section'>\n";
        // Mostrar Carros
        archivo << "<h2>🚘 Carros Ensamblados</h2>\n";
        for (Carro* carro : ensambladora.GetCarros()) {
            string tipo;
            string extras;

            if (auto f1 = dynamic_cast<CarroFormula1*>(carro)) {
                tipo = "Formula1";
                extras = "Peso Carrocería: " + to_string(f1->GetPesoCarroceria());
            } else if (auto bus = dynamic_cast<CarroOmnibus*>(carro)) {
                tipo = "Omnibus";
                extras = "Puertas: " + to_string(bus->GetCantPuertas());
            } else if (auto sport = dynamic_cast<CarroSport*>(carro)) {
                tipo = "Sport";
                extras = "Plazas: " + to_string(sport->GetPlazas()) + " | Velocidades: " + to_string(sport->GetCantVelocidades()) +
                        " | Cambio Universal: " + (sport->GetCambioUniversal() ? "Sí" : "No");
            } else if (auto lujo = dynamic_cast<CarroLujo*>(carro)) {
                tipo = "Lujo";
                extras = "Plazas: " + to_string(lujo->GetPlazas()) + " | Costo Tapicería: " + to_string(lujo->GetCostoTapiceria());
            }

            archivo << "<div class='carro'>\n";
            archivo << "<div><span class='etiqueta'>Tipo:</span> " << tipo << "</div>\n";
            archivo << "<div><span class='etiqueta'>Modelo:</span> " << carro->GetModelo() << "</div>\n";
            archivo << "<div><span class='etiqueta'>ID:</span> " << carro->GetId() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Velocidad:</span> " << carro->GetVelocidad() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Fecha de Salida:</span> " << carro->GetFechaSalida() << "</div>\n";
            if (carro->GetMotor())
                archivo << "<div><span class='etiqueta'>Motor Asignado:</span> " << carro->GetMotor()->GetCodigo() << "</div>\n";
            archivo << "<div><span class='etiqueta'>Detalles:</span> " << extras << "</div>\n";
            archivo << "</div>\n";
        }
        archivo << "</div>\n";
        archivo << "</div>\n";
        archivo << "</body>\n</html>\n";
        archivo.close();
        cout << "✅ Se ha creado el archivo 'Registro.html' con éxito." << endl;
    }

    static void GuardarDatos(Ensambladora &ensambladora) {

        ofstream archivoMotores(nombre_de_mi_archivo_de_motores, ios::out | ios::trunc);
        if (!archivoMotores) {
            cout << "Error al abrir MotorData.txt para guardar datos." << endl;
            return;
        }
        
        // Se asume que GetMotoresAux() retorna la lista completa de motores que se han guardado.
        vector<Motor*> motores = ensambladora.GetMotoresAux();
        
        for (Motor* motor : motores) {
            string tipoMotor;
            if (dynamic_cast<MotorAlta*>(motor))
                tipoMotor = "MotorAlta";
            else if (dynamic_cast<MotorFuerza*>(motor))
                tipoMotor = "MotorFuerza";
            else if (dynamic_cast<MotorTrabajo*>(motor))
                tipoMotor = "MotorTrabajo";
            else 
                continue;
            
            // Formato: tipoMotor codigo fechaSalida especialista vecesReensamblado [datosEspecíficos]
            archivoMotores << tipoMotor << " " 
                            << motor->GetCodigo() << " " 
                            << motor->GetFechaSalida() << " " 
                            << motor->GetEspecialista() << " " 
                            << motor->GetVecesReensamblado() << " ";

            //y caract propias de cada uno
            if (tipoMotor == "MotorAlta") {
                MotorAlta* mAlta = static_cast<MotorAlta*>(motor);
                archivoMotores << mAlta->GetMaxRevoluciones() << " " << mAlta->GetConsumo();
            } else if (tipoMotor == "MotorFuerza") {
                MotorFuerza* mFuerza = static_cast<MotorFuerza*>(motor);
                archivoMotores << mFuerza->GetCantCaballosFuerza();
            } else if (tipoMotor == "MotorTrabajo") {
                MotorTrabajo* mTrabajo = static_cast<MotorTrabajo*>(motor);
                // Se guarda "1" o "0" según si es artesanal o no.
                archivoMotores << (mTrabajo->GetEsArtesanal() ? "1" : "0");
            }
            archivoMotores << endl;
        }
        archivoMotores.close();
        
        ////////////////////
        // Guardar Carros
        ///////
        ofstream archivoCarros(nombre_de_mi_archivo_de_carros, ios::out | ios::trunc);
        if (!archivoCarros) {
            cout << "Error al abrir CarData.txt para guardar datos." << endl;
            return;
        }
        
        // Escribimos un encabezado para identificar la sección.
        archivoCarros << "CARROS" << endl;
        
        // Recorremos la lista de carros ensamblados.
        vector<Carro*> carros = ensambladora.GetCarros();
        for (Carro* carro : carros) {
            string tipoCarro;
            if (dynamic_cast<CarroFormula1*>(carro))
                tipoCarro = "Formula1";
            else if (dynamic_cast<CarroOmnibus*>(carro))
                tipoCarro = "Omnibus";
            else if (dynamic_cast<CarroSport*>(carro))
                tipoCarro = "Sport";
            else if (dynamic_cast<CarroLujo*>(carro))
                tipoCarro = "Lujo";
            else 
                continue;
            
            // Formato: tipoCarro modelo idCarro velocidad fechaSalida [plazas] [datosEspecíficos] motorCodigo
            archivoCarros << tipoCarro << " " 
                        << carro->GetModelo() << " " 
                        << carro->GetId() << " " 
                        << carro->GetVelocidad() << " " 
                        << carro->GetFechaSalida() << " ";
            // Para los carros Sport y Lujo se guarda también el campo "plazas".
            if (tipoCarro == "Sport" || tipoCarro == "Lujo")
                archivoCarros << carro->GetPlazas() << " ";
            if (tipoCarro == "Formula1") {
                CarroFormula1* cF1 = static_cast<CarroFormula1*>(carro);
                archivoCarros << cF1->GetPesoCarroceria() << " ";
            } else if (tipoCarro == "Omnibus") {
                CarroOmnibus* cO = static_cast<CarroOmnibus*>(carro);
                archivoCarros << cO->GetCantPuertas() << " ";
            } else if (tipoCarro == "Sport") {
                CarroSport* cS = static_cast<CarroSport*>(carro);
                archivoCarros << cS->GetCantVelocidades() << " " 
                            << (cS->GetCambioUniversal() ? "1" : "0") << " ";
            } else if (tipoCarro == "Lujo") {
                CarroLujo* cL = static_cast<CarroLujo*>(carro);
                archivoCarros << cL->GetCostoTapiceria() << " ";
            }
            
            // Se guarda el código del motor asignado al carro.
            if (carro->GetMotor())
                archivoCarros << carro->GetMotor()->GetCodigo();
            archivoCarros << endl;
        }
        archivoCarros.close();
        system("cls");
    }
    
    static string trim(const string &s) {
        auto start = s.begin();
        while (start != s.end() && isspace(*start)) {
            start++;
        }
        auto end = s.end();
        do {
            end--;
        } while (end != start && isspace(*end));

        return string(start, end + 1);
    }

    static void CargarDatos(Ensambladora &ensambladora) {
        vector<Motor*> motoresGuardadosAux = ensambladora.GetMotoresAux(); // copia exacta de mi lista
        ifstream archivoMotores(nombre_de_mi_archivo_de_motores, ios::in);
        if (archivoMotores) {
            string linea;
            while (getline(archivoMotores, linea)) {
                string trimmed = trim(linea);
                if (trimmed.empty())
                    continue;
                    // Cada línea debe tener el formato:
                    // tipoMotor codigo fechaSalida especialista vecesReensamblado [datosEspecíficos]
                    istringstream iss(trimmed);
                    string tipoMotor, codigo, fechaSalida, especialista;
                    int vecesReensamblado;
                    iss >> tipoMotor >> codigo >> fechaSalida >> especialista >> vecesReensamblado;
                    Motor* motor = nullptr;
                    if (tipoMotor == "MotorAlta") {
                        double rpm, consumo;
                        iss >> rpm >> consumo;
                        motor = new MotorAlta(codigo, fechaSalida, especialista, vecesReensamblado, rpm, consumo);
                    } else if (tipoMotor == "MotorFuerza") {
                        int caballos;
                        iss >> caballos;
                        motor = new MotorFuerza(codigo, fechaSalida, especialista, vecesReensamblado, caballos);
                    } else if (tipoMotor == "MotorTrabajo") {
                        int artesanalInt;
                        iss >> artesanalInt;
                        bool artesanal = (artesanalInt == 1);
                        motor = new MotorTrabajo(codigo, fechaSalida, especialista, vecesReensamblado, artesanal);
                    }
                    if (motor)
                        // Agregamos este motor a la copia auxiliar
                        motoresGuardadosAux.push_back(motor);     
            }
            archivoMotores.close();
        }
        // 2. Cargar los carros desde "ensambladora.txt"
        vector<Carro*> carrosAcumulados;
        ifstream archivoCarros(nombre_de_mi_archivo_de_carros);
        if (archivoCarros) {
            string seccionActual = "";
            string linea;
            while (getline(archivoCarros, linea)) {
                string trimmed = trim(linea);
                if (trimmed.empty())
                    continue;
                if (trimmed == "CARROS") {
                    seccionActual = "CARROS";
                    continue;
                }
                if (seccionActual != "CARROS")
                    continue; // saltamos cualquier línea fuera de la sección
                // Formato esperado (una línea por carro):
                // tipoCarro modelo idCarro velocidad fechaSalida [plazas] [datosEspecíficos] motorCodigo
                istringstream iss(trimmed);
                string tipoCarro, modelo, fechaSalida, motorCodigo;
                int idCarro;
                double velocidad;
                iss >> tipoCarro >> modelo >> idCarro >> velocidad >> fechaSalida;
                int plazas = 0; // solo se usa para Sport y Lujo
                Carro* carro = nullptr;
                // Si es Sport o Lujo se espera el campo "plazas"
                if (tipoCarro == "Sport" || tipoCarro == "Lujo") {
                    iss >> plazas;
                }
                // Según el tipo, se leen datos específicos y se obtiene el código del motor.
                if (tipoCarro == "Formula1") {
                    double pesoCarroceria;
                    iss >> pesoCarroceria >> motorCodigo;
                    carro = new CarroFormula1(modelo, idCarro, velocidad, fechaSalida, nullptr, pesoCarroceria);
                } else if (tipoCarro == "Omnibus") {
                    int cantidadPuertas;
                    iss >> cantidadPuertas >> motorCodigo;
                    carro = new CarroOmnibus(modelo, idCarro, velocidad, fechaSalida, nullptr, cantidadPuertas);
                } else if (tipoCarro == "Sport") {
                    int cantidadVelocidades, cambioUniversalInt;
                    iss >> cantidadVelocidades >> cambioUniversalInt >> motorCodigo;
                    bool cambioUniversal = (cambioUniversalInt == 1);
                    carro = new CarroSport(modelo, idCarro, plazas, velocidad, fechaSalida, nullptr, cantidadVelocidades, cambioUniversal);
                } else if (tipoCarro == "Lujo") {
                    double costoTapiceria;
                    iss >> costoTapiceria >> motorCodigo;
                    carro = new CarroLujo(modelo, idCarro, plazas, velocidad, fechaSalida, nullptr, costoTapiceria);
                }
                if (carro) {
                    // Buscar en el vector auxiliar el motor cuyo código coincide
                    auto it = find_if(motoresGuardadosAux.begin(), motoresGuardadosAux.end(),
                                        [&](Motor* m) { return m->GetCodigo() == motorCodigo; });
                    if (it != motoresGuardadosAux.end()) {
                        carro->SetMotor(*it);
                        // Una vez asignado, se elimina de la copia para que ya no se considere libre.
                        motoresGuardadosAux.erase(it);
                    }
                    carrosAcumulados.push_back(carro);
                }
            } 
            archivoCarros.close();
        }
        // 3. Agregar los carros ensamblados a la ensambladora.
        for (Carro* c : carrosAcumulados) {
            ensambladora.EnsamblarCarro(c);
        }
        // 4. Agregar a la ensambladora los motores que aún quedaron libres.
        for (Motor* m : motoresGuardadosAux) {
            ensambladora.AgregarMotor(m);
        }
    }
};

#endif // _UTILS_


