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
int cont_p = 0; //Contador de personas registradas (empleados + clientes)
int cont_e = 0; //Contador de empleados
int cont_h = 0; //Contador de habitaciones
int cont_c = 0; //Contador de clientes

class Hotel{
    //Declaracion de atributos privados
    private:
    //Creacion de apuntadores con 20 objetos cada uno, Personas tiene 40 porque almacena 2 tipos de objetos
    Personas *per[40]; //Declarado para usar polimorfismo
    Habitacion *hab[20];
    Empleado *emp[20];
    Cliente *clien[20];

    //Declaracion de atributos publicos
    public:
    //Constructor default sin parametros, no registra datos para poder manejar apuntadores mejor
    Hotel(){};

    //Declaraciones para agregar objetos
    void agrega_habitacion(Habitacion *);
    void agrega_empleado(Empleado *);
    void agrega_cliente(Cliente *);
    //Declaraciones para imprimir objetos registrados
    void muestra_personas();
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
 * objeto de este tipo previamente hecho, tambien
 * agrega a la lista de personas
 * 
 * Toma el objeto ya contruido y lo agrega a la lista
 * de empleados si hay espacio y aumenta su contador
 * en una unidad, igualmente lo agrega a la lista de
 * personas con ayuda de un auxiliar y aumenta el
 * contador de personas en 1.
 * 
 * @param Empleado * empleado a registrar
 * @return
*/
void Hotel::agrega_empleado(Empleado * objeto){
    //agrega empleados si hay espacio
    if (cont_e < 20){
        emp[cont_e] = objeto;
        cont_e++;

        //creacion del auxiliar
        Personas *aux[cont_p + 1];

        //Pasa a los empleados al auxiliar
        for(int i = 0; i < cont_e; i++){
            aux[i] = per[i];
        }
        //Agrega al nuevo empleado al auxiliar
        aux[cont_e - 1] = objeto;
        //Agrega a los clientes al auxiliar
        for(int i = 0; i < cont_c; i++){
            aux[cont_e + i] = per[cont_e + i - 1];
        }
        cont_p++;
        //Pasa los objetos del auxiliar a la lista original
        for(int i = 0; i < cont_p; i++){
            per[i] = aux[i];
        }
    }
}

/**agrega_cliente agrega clientes al registro del hotel
 * 
 * Recibe el objeto de tipo cliente previamente hecho y
 * lo agrega a la lista si hay espacio, depsues aumenta
 * su contador en 1. Igualmente lo agrega a la lista de
 * personas con ayuda de un auxiliar y aumenta el
 * contador de personas en 1.
 * 
 * @param Cliente * cliente a registrar
 * @return
*/
void Hotel::agrega_cliente(Cliente * objeto){
    //Agrega al cliente si hay espacio
    if (cont_c < 20){
        clien[cont_c] = objeto;
        cont_c++;

        //creacion del auxiliar
        Personas *aux[cont_p + 1];

        //Pasa a los objetos al auxiliar
        for(int i = 0; i < cont_p; i++){
            aux[i] = per[i];
        }
        cont_p++;
        //Agrega al nuevo objeto al auxiliar
        aux[cont_p - 1] = objeto;
        //Pasa los objetos del auxiliar a la lista original
        for(int i = 0; i < cont_p; i++){
            per[i] = aux[i];
        }
    }
}

/**muestra_personas muestra a todas las personas
 * registrados previamente (empleados y clientes)
 * 
 * Manda a llamar a todas las personas una por una.
 * No se encarga de imprimirlas todas pero si de pasar
 * una por una para que otra funcion se encargue de 
 * imprimirlas
 * 
 * @param
 * @return
*/
void Hotel::muestra_personas(){
    for(int i = 0; i < cont_p; i++){
        per[i]->imprime();
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
    for(int i = 0; i < cont_e; i++){
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
    for(int i = 0; i < cont_c; i++){
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
    for(int i = 0; i < cont_h; i++){
        hab[i]->imprime_hab();
    }
}

#endif