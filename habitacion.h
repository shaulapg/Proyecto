#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <iostream>

int num_habi = 1;

class Habitacion{
    private:
    int numero, tipo;
    bool disponibilidad;

    public:
    Habitacion(): numero(0), tipo(0), disponibilidad(false){};
    Habitacion(int tip, bool disp): tipo(tip), disponibilidad(disp){
        numero = num_habi;
        num_habi++;
    }
    int get_numero();
    int get_tipo();
    bool get_disponibilidad();
    void set_disponibilidad(bool);
};

int Habitacion::get_numero(){
    return numero;
}

int Habitacion::get_tipo(){
    return tipo;
}

bool Habitacion::get_disponibilidad(){
    return disponibilidad;
}

void Habitacion::set_disponibilidad(bool disp){
    disponibilidad = disp;
}

#endif