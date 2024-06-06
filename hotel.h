/**
 * Proyecto Hotel
 * Shaula Suhail Paz Garay
 * A01712013
 * 06/Junio/2024
*/

#ifndef HOTEL_H
#define HOTEL_H

//Bibliotecas
#include <string>
#include <iostream>

//Archivos para acceder a clases necesarias
#include "personas.h" //Creacion de objetos "persona"
#include "habitacion.h" //Creacion de objetos "habitacion"
#include "reserva.h" //Creacion de objetos "reserva"

//Contadores para llevar registro de la cantidad de objetos por clase
int cont_e = 0; //Contador de empleados
int cont_h = 0; //Contador de habitaciones
int cont_c = 0; //Contador de clientes

class Hotel{
    //Declaracion de atributos privados
    private:
    //Creacion de apuntadores con 20 objetos cada uno
    Habitacion *hab[20];
    Personas *emp[20];
    Personas *clien[20];

    //Declaracion de atributos publicos
    public:
    //Constructor default
    Hotel(){};

    void agrega_habitacion(Habitacion *);
    void agrega_empleado(Personas *);
    void agrega_cliente(Personas *);
    void muestra_empleado();
    void muestra_cliente();
    void muestra_habitacion();
};

/**
 * agrega_habitacion crea habitaciones con apuntadores
 * 
 * Se toma el objeto habitacion como parametro para 
 * agregarlo al registro de habitaciones solo si hay
 * espacion en la lista, despues aumenta su contador
 * en una unidad.
 * 
 * @param Habitacion * habitacion a registrar
 * @return
*/
void Hotel::agrega_habitacion(Habitacion * objeto){
    if (cont_h < 20){
        hab[cont_h] = objeto;
        cont_h++;
    }
}

/**agrega_empleado da de alta empleados recibiendo un
 * objeto de este tipo previamente hecho
 * 
 * Toma el objeto ya contruido y lo agrega a la lista
 * de empleados si hay espacio y aumenta su contador
 * en una unidad
 * 
 * @param Personas * empleado a registrar
 * @return
*/
void Hotel::agrega_empleado(Personas * objeto){
    if (cont_e < 20){
        emp[cont_e] = objeto;
        cont_e++;
    }
}

/**agrega_cliente agrega clientes al registro del hotel
 * 
 * Recibe el objeto de tipo cliente previamente hecho y
 * lo agrega a la lista si hay espacio, depsues aumenta
 * su contador en 1.
 * 
 * @param Personas * clientes a registrar
 * @return
*/
void Hotel::agrega_cliente(Personas * objeto){
    if (cont_c < 20){
        clien[cont_c] = objeto;
        cont_c++;
    }
}

/**muestra_empleado muestra todos los empleados
 * registrados previamente
 * 
 * Manda a llamar a todos los empleados uno por uno.
 * No se encarga de imprimirlos todos pero si de pasar
 * uno por uno para que otra funcion se encargue de 
 * imprimirlos
 * 
 * @param
 * @return
*/
void Hotel::muestra_empleado(){
    for(int i = 0; i < 20; i++){
        emp[i]->imprime();
    }
}

/**muestra_cliente muestra todos los clientes
 * registrados
 * 
 * Manda a llamar a todos los clientes uno por uno
 * para que una funcion externa imprima sus
 * atributos
 * 
 * 
 * @param
 * @return
*/
void Hotel::muestra_cliente(){
    for(int i = 0; i < 20; i++){
        clien[i]->imprime();
    }
}

/**muestra_habitacion muestra las habitaciones
 * en el hotel
 * 
 * Manda a llamar todas las habitaciones una
 * por una para que otra funcion muestre sus
 * atributos 
 * 
 * @param
 * @return
*/
void Hotel::muestra_habitacion(){
    for(int i = 0; i < 20; i++){
        hab[i]->imprime_hab();
    }
}

#endif