/**
 * Proyecto Hotel
 * Shaula Suhail Paz Garay
 * A01712013
 * 06/Junio/2024
 * 
 * Clase para creacion de habitaciones en el hotel.
 * Unica que solo se maneja a si misma
*/

#ifndef HABITACION_H
#define HABITACION_H

//Bibliotecas
#include <string>
#include <iostream>

//Variable que almacena el numero de habitaciones existentes para asignar el numero de guia
int num_habi = 1;

class Habitacion{
    //Declaracion de variables privadas
    private:
    //Atributos privados de la clase
    int numero, tipo;
    bool disponibilidad;

    //Declaracion de variables publicas
    public:
    //Constructor default
    Habitacion(): numero(0), tipo(0), disponibilidad(false){};
    //Constructor con datos dados, el numero de habitacion se asigna automaticamente
    Habitacion(int tip, bool disp): tipo(tip), disponibilidad(disp){
        numero = num_habi;
        num_habi++;
    }

    
    void imprime_hab();
    int get_numero();
    int get_tipo();
    bool get_disponibilidad();
    void set_disponibilidad(bool);
};

/**
 * imprime_hab imprime la habitacion indicada con sus atributos
 * 
 * @param
 * @return
*/
void Habitacion::imprime_hab(){
    std::cout << "Numero: " << numero << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Disponibilidad: " << disponibilidad << std::endl;
}

/**
 * get_numero getter del atributo numero
 * 
 * @param
 * @return numero
*/
int Habitacion::get_numero(){
    return numero;
}

/**
 * get_tipo getter del atributo tipo
 * 
 * @param
 * @return tipo
*/
int Habitacion::get_tipo(){
    return tipo;
}

/**
 * get_disponibilidad getter del atributo disponibilidad
 * 
 * @param
 * @return disponibilidad
*/
bool Habitacion::get_disponibilidad(){
    return disponibilidad;
}

/**
 * set_disponibilidad setter del atributo disponibilidad
 * 
 * @param
 * @return disponibilidad
*/
void Habitacion::set_disponibilidad(bool disp){
    disponibilidad = disp;
}

#endif