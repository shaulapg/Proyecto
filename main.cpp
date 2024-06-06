/**
 * Proyecto Hotel
 * Shaula Suhail Paz Garay
 * A01712013
 * 06/Junio/2024
*/

//Bibliotecas
#include <iostream>
#include <string>

//Archivos del proyecto para desempeñar las funciones necesarias
#include "personas.h"
#include "hotel.h"
#include "habitacion.h"

//Declaracion de variables
bool continua = true;
int opcion, opcion1, noch, cuart;
float prec;
std::string nom, ent, sal, cont;

/**Proyecto simulacion de un hotel
 * Objetivo principla: Manejar el hotel y sus reservaciones desde 3 perspectivas:
 * Administracion del hotel
 * Clientes
 * Empleados
 * 
 * El archivo actual se centra en la interaccion con el usuario
*/

main(){
    //Inicializacion del hotel que controlara todo
    Hotel hotel;

    //Objetos creados sin caractericticas especificas para ser usados mas adelante
    Personas * empp;
    Cliente * clienp;
    Reserva * resp;

    //Inicializacion de Empleados base
    Personas * hotel1 = new Empleado("Juan", "juan@gmail.com", false);
    Personas * hotel2 = new Empleado("Ana", "ana@gmail.com", true);
    Personas * hotel3 = new Empleado("Jose", "jose@gmail.com", true);
    //Insersion de los empleados creados en la lista de empleados
    hotel.agrega_empleado(hotel1);
    hotel.agrega_empleado(hotel2);
    hotel.agrega_empleado(hotel3);

    //Inicializacion de Clientes base
    Cliente * clien1 = new Cliente("Valeria", "valeria@gmail.com", false);
    Cliente * clien2 = new Cliente("Axel", "axel@gmail.com", true);
    Cliente * clien3 = new Cliente("Fernanda", "fernanda@gmail.com", true);
    //Insersion de los clientes creados en la lista de clientes
    hotel.agrega_cliente(clien1);
    hotel.agrega_cliente(clien2);
    hotel.agrega_cliente(clien3);

    //Inicializacion de habitaciones base
    Habitacion * habit1 = new Habitacion(2, false);
    Habitacion * habit2 = new Habitacion(4, true);
    Habitacion * habit3 = new Habitacion(1, true);
    //Insersion de las habitaciones creadas en la listade habitaciones
    hotel.agrega_habitacion(habit1);
    hotel.agrega_habitacion(habit2);
    hotel.agrega_habitacion(habit3);

    //Inicializacion de habitaciones base, sirve como ejemplo de como se espera insertar una reserva
    Reserva * res1 = new Reserva("12/Junio/2024", "16/Junio/2024", 4, "Ana", 2);
    Reserva * res2 = new Reserva("22/Junio/2024", "25/Junio/2024", 3, "Juan", 1);

    //Se pide el nombre para su almacenamiento como cliente y como empleado
    std::cout << "Nombre: ";
    std::getline(std::cin, nom);
    //Creacion del perfil de cliente del usuario
    clienp = new Cliente(nom, "NA", true);
    //Creacion del perfil de cliente del usuario
    empp = new Empleado(nom, "NA", true);

    //while para que el programa corra continuamente
    while(continua == true){
        //Menu principal para elegir perfil
        std::cout << "Menu principal" << std::endl;
        std::cout << "1. Entrar como administrador" << std::endl;
        std::cout << "2. Entrar como cliente" << std::endl;
        std::cout << "3. Entrar como empleado" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Inserte una de las modalidaddes anteriores para continuar: ";
        std::cin >> opcion;
        //Comienzo del switch derivado del menu principal
        switch(opcion){
            case 1:
                //Menu del administrador
                std::cout << "Menu de administrador" << std::endl;
                std::cout << "1. Mostrar empleados" << std::endl;
                std::cout << "2. Mostrar clientes" << std::endl;
                std::cout << "3. Mostrar habitaciones" << std::endl;
                std::cout << "Inserte una opcion: ";
                std::cin >> opcion1;
                switch(opcion1){
                    //dependiendo de la opcion elegida se muestran los objetos almacenados
                    case 1:
                        hotel.muestra_empleado();
                    break;
                    case 2:
                        hotel.muestra_cliente();
                    break;
                    case 3:
                        hotel.muestra_habitacion();
                    break;
                }
            break;
            case 2:
                //Menu cliente
                std::cout << "Menu de cliente" << std::endl;
                std::cout << "1. Hacer Reserva" << std::endl;
                std::cout << "2. Cambiar contacto" << std::endl;
                std::cout << "3. Ver mi informacion" << std::endl;
                std::cout << "Inserte una opcion: ";
                std::cin >> opcion1;
                switch(opcion1){
                    case 1:
                        //Toma de datos para realizar la reserva
                        std::cout << "Fecha de entrada: ";
                        std::cin.ignore();
                        std::getline(std::cin, ent);
                        std::cout << "Fecha de salida: ";
                        std::getline(std::cin, sal);
                        std::cout << "Noches: ";
                        std::cin >> noch;
                        //Seleccion del tipo de cuarto con su propio menu
                        std::cout << "Tipos de cuarto" << std::endl;
                        std::cout << "1. Una cama para 1 persona" << std::endl;
                        std::cout << "2. Una cama para 2 personas" << std::endl;
                        std::cout << "3. Dos camas, 1 persona c/u" << std::endl;
                        std::cout << "4. Dos camas, 2 personas c/u" << std::endl;
                        std::cout << "Tipo de cuarto a reservar: ";
                        std::cin >> cuart;
                        //Se crea un objeto de reserva, pero aun no se almacena
                        resp = new Reserva(ent, sal, noch, nom, cuart);
                        //Almacenamiento de la reserva
                        prec = clienp->reservar(resp);
                        //Despliegue del precio segun la habitacion y cuantas noches se ocupara
                        std::cout << "Precio por la habitacion: " << prec << std::endl;
                    break;
                    case 2:
                        //Toma de datos para el cabio de contacto
                        std::cout << "Inserte su nuevo contacto: ";
                        std::cin >> cont;
                        //Cambio de contacto
                        clienp->set_contacto(cont);
                        clienp->imprime();
                    break;
                    case 3:
                        //Vista de los datos del usuario en el perfil de cliente
                        clienp->imprime();
                    break;
                }
            case 3:
                //Menu empleado
                std::cout << "Menu de empleado" << std::endl;
                std::cout << "1. Hacer Reserva" << std::endl;
                std::cout << "2. Cambiar contacto" << std::endl;
                std::cout << "3. Ver mi informacion" << std::endl;
                std::cout << "Inserte una opcion: ";
                std::cin >> opcion1;
                //Inicio del switch del empleado
                switch(opcion1){
                    case 1:
                        //Toma de datos para la reserva
                        std::cout << "Fecha de entrada: ";
                        std::cin.ignore();
                        std::getline(std::cin, ent);
                        std::cout << "Fecha de salida: ";
                        std::getline(std::cin, sal);
                        std::cout << "Noches: ";
                        std::cin >> noch;
                        //Menu de las habitaciones a elegir
                        std::cout << "Tipos de cuarto" << std::endl;
                        std::cout << "1. Una cama para 1 persona" << std::endl;
                        std::cout << "2. Una cama para 2 personas" << std::endl;
                        std::cout << "3. Dos camas, 1 persona c/u" << std::endl;
                        std::cout << "4. Dos camas, 2 personas c/u" << std::endl;
                        std::cout << "Tipo de cuarto a reservar: ";
                        std::cin >> cuart;
                        //Creacion del objeto para la reserva
                        resp = new Reserva(ent, sal, noch, nom, cuart);
                        //Agregacion del objeto para colocar la reserva formalmente
                        prec = empp->reservar(resp);
                        //Despliegue del precio de la habitacion escogida
                        std::cout << "Precio por la habitacion: " << prec << std::endl;
                    break;
                    case 2:
                        //Cambio de contacto, toma de datos
                        std::cout << "Inserte su nuevo contacto: ";
                        std::cin >> cont;
                        //Cambio de contacto, alteracion de la informacion previa
                        empp->set_contacto(cont);
                        //Muestra de los datos del usuario depsues del cambio
                        empp->imprime();
                    break;
                    case 3:
                        //Muestra de los datos del usuario en el perfil de empleado
                        empp->imprime();
                    break;
                }
            break;
            case 4:
                //Fin del while
                continua = false;
        }
    }
}