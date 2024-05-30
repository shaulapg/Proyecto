#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <iostream>

#include "personas.h"
#include "habitacion.h"

const int MAX = 500;

class Hotel{
    private:
    int num_hab = 1;
    int num_emp = 1;
    int num_clien = 1;
    Habitacion *hab[MAX];
    Empleado *emp[MAX];
    Cliente *clien[MAX];

    public:
    void muestra_empleado();
    void agrega_habitacion(int, bool);
    void agrega_empleado(std::string, std::string, bool);
    void agrega_cliente(std::string, std::string, bool);
};

void Hotel::muestra_empleado(){
    for(int i; 3; i++){
        std::cout << emp[i] -> to_string();
    }
}

void Hotel::agrega_habitacion(int tip, bool disp){
    hab[num_hab] = new Habitacion(tip, disp);
    num_hab++;
}

void Hotel::agrega_empleado(std::string nom, std::string cont, bool trab){
    emp[num_emp] = new Empleado(nom, cont, trab);
    num_emp++;
}

void Hotel::agrega_cliente(std::string nom, std::string cont, bool trab){
    clien[num_clien] = new Cliente(nom, cont, trab);
    num_clien++;
}

#endif