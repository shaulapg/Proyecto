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
bool continua = true, continuaa, trab, hosp, disp;
int opcion, opcion1, noch, cuart;
float prec;
std::string nomb, nom, ent, sal, cont;

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
    //Inicializacion del empleado ficticio para registrar reservas
    Empleado empleado;
    Reserva * resp;

    //Inicializacion de Empleados con apuntadores
    Empleado * hotel1 = new Empleado("Juan", "juan@gmail.com", false);
    Empleado * hotel2 = new Empleado("Ana", "ana@gmail.com", true);
    Empleado * hotel3 = new Empleado("Jose", "jose@gmail.com", true);
    //Insersion de los empleados creados en la lista de empleados
    hotel.agrega_empleado(hotel1);
    hotel.agrega_empleado(hotel2);
    hotel.agrega_empleado(hotel3);

    //Inicializacion de Clientes con apuntadores
    Cliente * clien1 = new Cliente("Valeria", "valeria@gmail.com", false);
    Cliente * clien2 = new Cliente("Axel", "axel@gmail.com", true);
    Cliente * clien3 = new Cliente("Fernanda", "fernanda@gmail.com", true);
    //Insersion de los clientes creados en la lista de clientes
    hotel.agrega_cliente(clien1);
    hotel.agrega_cliente(clien2);
    hotel.agrega_cliente(clien3);

    //Inicializacion de habitaciones con apuntadores
    Habitacion * habit1 = new Habitacion(2, false);
    Habitacion * habit2 = new Habitacion(4, true);
    Habitacion * habit3 = new Habitacion(1, true);
    //Insersion de las habitaciones creadas en la lista de habitaciones
    hotel.agrega_habitacion(habit1);
    hotel.agrega_habitacion(habit2);
    hotel.agrega_habitacion(habit3);

    //Inicializacion de reservas con apuntadores
    Reserva * res1 = new Reserva("12/Junio/2024", "16/Junio/2024", 4, "Ana", 2);
    Reserva * res2 = new Reserva("22/Junio/2024", "25/Junio/2024", 3, "Juan", 1);
    //Insersion de las reservas creadas en la lista de reservas
    empleado.agrega_reserva(res1);
    empleado.agrega_reserva(res2);

    //Se pide el nombre para su almacenamiento como cliente y como empleado
    std::cout << "Nombre: ";
    std::getline(std::cin, nomb);
    //Creacion del perfil de cliente del usuario con apuntadores
    Cliente * clienp = new Cliente(nomb, "NA", true);
    //Eliminacion del ID porque no es un cliente real
    clienp->set_id("NA (empleado de prueba)");
    //Eliminacion del registro de clientes
    cliente_id--;
    //Creacion del perfil de empleado del usuario con apuntadores
    Empleado * empp = new Empleado(nomb, "NA", true);
    //Eliminacion del ID porque no es un empleado real
    empp->set_id("NA (cliente de prueba)");
    //Eliminacion del registro de empleados
    emp_id--;

    //while para que el programa corra continuamente
    while(continua == true){
        //Usado en caso de salir de una seccion, se restablece a true
        continuaa = true;
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
                //while para continuar en administrador, si se eligio, hasta que se indique lo contrario
                while(continuaa == true){
                    //Menu del administrador
                    std::cout << std::endl;
                    std::cout << "Menu de administrador" << std::endl;
                    std::cout << "1. Mostrar empleados" << std::endl;
                    std::cout << "2. Mostrar clientes" << std::endl;
                    std::cout << "3. Mostrar habitaciones" << std::endl;
                    std::cout << "4. Mostrar reservas" << std::endl;
                    std::cout << "5. Mostrar a todas las personas" << std::endl;
                    std::cout << "6. Dar de alta empleado" << std::endl;
                    std::cout << "7. Agregar cliente" << std::endl;
                    std::cout << "8. Dar de alta habitacion" << std::endl;
                    std::cout << "9. Regresar al menu principal" << std::endl;
                    std::cout << "Inserte una opcion: ";
                    std::cin >> opcion1;
                    std::cout << std::endl;
                    //dependiendo de la opcion elegida se muestran los objetos almacenados
                    if(opcion1 == 1)
                        hotel.muestra_empleado();
                    else if(opcion1 == 2)
                        hotel.muestra_cliente();
                    else if(opcion1 == 3)
                        hotel.muestra_habitacion();
                    else if(opcion1 == 4)
                        empleado.muestra_reservas();
                    else if(opcion1 == 5)
                        hotel.muestra_personas();
                    //comienzo de las opciones de registro
                    //opcion de registro de empleados
                    else if(opcion1 == 6){
                        //toma de datos
                        std::cout << "Nombre del empleado: ";
                        std::cin.ignore();
                        std::getline(std::cin, nom);
                        std::cout << "Contacto del empleado: ";
                        std::getline(std::cin, cont);
                        std::cout << "El empleado esta trabajando? (1 para si, 0 para no): ";
                        std::cin >> trab;
                        //creacion de apuntador para registrar al empleado
                        Empleado * auxe = new Empleado(nom, cont, trab);
                        //insersion a la lista de empleados
                        hotel.agrega_empleado(auxe);
                    }
                    //opcion de registro de clientes
                    else if(opcion1 == 7){
                        //toma de datos
                        std::cout << "Nombre del cliente: ";
                        std::cin.ignore();
                        std::getline(std::cin, nom);
                        std::cout << "Contacto del cliente: ";
                        std::getline(std::cin, cont);
                        std::cout << "El cliente esta hospedado en el hotel? (1 para si, 0 para no): ";
                        std::cin >> hosp;
                        //creacion de apuntador para registrar al cliente
                        Cliente * auxc = new Cliente(nom, cont, hosp);
                        //insersion a la lista de clientes
                        hotel.agrega_cliente(auxc);
                    }
                    //opcion de registro de habitaciones
                    else if(opcion1 == 8){
                        //toma de datos
                        std::cout << std::endl;
                        std::cout << "Tipos de habitacion" << std::endl;
                        std::cout << "1. Una cama para 1 persona" << std::endl;
                        std::cout << "2. Una cama para 2 personas" << std::endl;
                        std::cout << "3. Dos camas, 1 persona c/u" << std::endl;
                        std::cout << "4. Dos camas, 2 personas c/u" << std::endl;
                        std::cout << "Tipo de habitacion a registrar: ";
                        std::cin >> cuart;
                        std::cout << "La habitacion esta disponible? (1 para si, 0 para no): ";
                        std::cin >> disp;
                        //creacion de apuntador para registrar la habitacion
                        Habitacion * auxh = new Habitacion(cuart, disp);
                        //insersion a la lista de habitaciones
                        hotel.agrega_habitacion(auxh);
                    }
                    //opcion de salida del menu de administrador
                    else if(opcion1 == 9)
                        continuaa = false;
                    //opcion invalida
                    else
                        std::cout << "Opcion invalida";
                }
            break;
            case 2:
                //while para continuar en cliente, si se eligio, hasta que se indique lo contrario
                while(continuaa == true){
                    //Menu cliente
                    std::cout << std::endl;
                    std::cout << "Menu de cliente" << std::endl;
                    std::cout << "1. Hacer Reserva" << std::endl;
                    std::cout << "2. Cambiar contacto" << std::endl;
                    std::cout << "3. Ver mi informacion" << std::endl;
                    std::cout << "4. Regresar al menu principal" << std::endl;
                    std::cout << "Inserte una opcion: ";
                    std::cin >> opcion1;
                    std::cout << std::endl;
                    if(opcion1 == 1){
                        //Toma de datos para realizar la reserva
                        std::cout << "Fecha de entrada: ";
                        std::cin.ignore();
                        std::getline(std::cin, ent);
                        std::cout << "Fecha de salida: ";
                        std::getline(std::cin, sal);
                        std::cout << "Noches: ";
                        std::cin >> noch;
                        //Seleccion del tipo de cuarto con su propio menu
                        std::cout << std::endl;
                        std::cout << "Tipos de habitacion" << std::endl;
                        std::cout << "1. Una cama para 1 persona" << std::endl;
                        std::cout << "2. Una cama para 2 personas" << std::endl;
                        std::cout << "3. Dos camas, 1 persona c/u" << std::endl;
                        std::cout << "4. Dos camas, 2 personas c/u" << std::endl;
                        std::cout << "Tipo de cuarto a reservar: ";
                        std::cin >> cuart;
                        //Se crea un objeto de reserva, pero aun no se almacena
                        resp = new Reserva(ent, sal, noch, nom, cuart);
                        //Almacenamiento de la reserva
                        prec = clienp->reservar(cuart, noch);
                        empleado.agrega_reserva(resp);
                        std::cout << std::endl;
                        //Despliegue del precio segun la habitacion y cuantas noches se ocupara
                        std::cout << "Precio por la habitacion: " << prec << std::endl;
                    }
                    else if(opcion1 == 2){
                        //Toma de datos para el cambio de contacto
                        std::cout << std::endl;
                        std::cout << "Inserte su nuevo contacto: ";
                        std::cin >> cont;
                        //Cambio de contacto
                        clienp->set_contacto(cont);
                        std::cout << std::endl;
                        //Impresion del perfil con el contacto guardado
                        clienp->imprime();
                    }
                    else if(opcion1 == 3){
                        std::cout << std::endl;
                        //Vista de los datos del usuario en el perfil de cliente
                        clienp->imprime();
                    }
                    //Opcion para salir al menu principal
                    else if(opcion1 == 4)
                            continuaa = false;
                    //Opcion para seleccion inexistente
                    else
                        std::cout << "Opcion invalida";
                }
            break;
            case 3:
                //while para continuar en empleado, si se eligio, hasta que se indique lo contrario
                while(continuaa == true){
                    //Menu empleado
                    std::cout << std::endl;
                    std::cout << "Menu de empleado" << std::endl;
                    std::cout << "1. Hacer Reserva" << std::endl;
                    std::cout << "2. Cambiar contacto" << std::endl;
                    std::cout << "3. Ver mi informacion" << std::endl;
                    std::cout << "4. Regresar al menu principal" << std::endl;
                    std::cout << "Inserte una opcion: ";
                    std::cin >> opcion1;
                    std::cout << std::endl;
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
                            std::cout << std::endl;
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
                            prec = empp->reservar(cuart, noch);
                            empleado.agrega_reserva(resp);
                            //Despliegue del precio de la habitacion escogida
                            std::cout << std::endl;
                            std::cout << "Precio por la habitacion: " << prec << std::endl;
                        break;
                        case 2:
                            //Cambio de contacto, toma de datos
                            std::cout << "Inserte su nuevo contacto: ";
                            std::cin >> cont;
                            //Cambio de contacto, alteracion de la informacion previa
                            empp->set_contacto(cont);
                            std::cout << std::endl;
                            //Muestra de los datos del usuario depsues del cambio
                            empp->imprime();
                        break;
                        case 3:
                            std::cout << std::endl;
                            //Muestra de los datos del usuario en el perfil de empleado
                            empp->imprime();
                        break;
                        //Opcion para salir al menu principal
                        case 4:
                            continuaa = false;
                        break;
                        //Mensaje para opciones invalidas
                        default:
                            std::cout << "Opcion invalida";
                    }
                }
            break;
            case 4:
                //Fin del while principal (termina el codigo)
                continua = false;
            break;
        }
    }
}