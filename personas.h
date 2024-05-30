#ifndef PERSONAS_H
#define PERSONAS_H

#include <string>
#include <iostream>
#include <sstream>

#include "reserva.h"

class Personas{
    private:
    std::string id, nombre, contacto;

    public:
    Personas(): id(0), nombre(""), contacto(""){};
    Personas(std::string nom, std::string cont): nombre(nom), contacto(cont){};

    //double reservar(int, int, int, std::string, int);

    std::string get_id();
    std::string get_nombre();
    std::string get_contacto();
    void set_id(std::string);
    void set_contacto(std::string);
};

/*double Personas::reservar(int entr, int sal, int noch, std::string reg, int tip){
    res[num_res] = new Reserva(entr, sal, noch, reg, tip);
    num_res++;
    double precio;
    switch (tip){
        case 1:
        precio = 250 * noch;
        break;
        case 2:
        precio = 280 * noch;
        break;
        case 3:
        precio = 320 * noch;
        break;
        case 4:
        precio = 350 * noch;
        break;
    }
    return precio;
}*/


std::string Personas::get_id(){
    return id;
}

std::string Personas::get_nombre(){
    return nombre;
}

std::string Personas::get_contacto(){
    return contacto;
}

void Personas::set_id(std::string i){
    id = i;
}

void Personas::set_contacto(std::string cont){
    contacto = cont;
}


class Empleado : public Personas{
    private:
    int emp_id = 0;
    bool trabajando;

    public:
    Empleado(): Personas(), trabajando(false){};
    Empleado(std::string nom, std::string cont, bool trab): Personas(nom, cont), trabajando(trab) {
        set_id("E" + emp_id);
        emp_id++;
    }

    //double reservar(int, int, int, std::string, int);

    std::string to_string();
    bool get_trabajando();
    void set_trabajando(bool);
};

std::string Empleado::to_string(){
    std::stringstream aux;
    aux << "Id: " << get_id() << " Nombre: " << get_nombre() << "Contacto: " << get_contacto() << " Esta trabajando: " << trabajando;
    return aux.str();
}

/*double Empleado::reservar(int entr, int sal, int noch, std::string reg, int tip){
    double precio;
    switch (tip){
        case 1:
        precio = 250 * noch;
        break;
        case 2:
        precio = 280 * noch;
        break;
        case 3:
        precio = 320 * noch;
        break;
        case 4:
        precio = 350 * noch;
        break;
    }

    double real = precio * 0.85;
    return real;
}*/

bool Empleado::get_trabajando(){
    return trabajando;
}

void Empleado::set_trabajando(bool disp){
    trabajando = disp;
}


class Cliente : public Personas{
    private:
    int cliente_id = 0;
    bool estancia;

    public:
    Cliente(): Personas(), estancia(false){};
    Cliente(std::string nom, std::string cont, bool est): Personas(nom, cont), estancia(est){
        std::string i = "C" + cliente_id;
        set_id(i);
        cliente_id++;
    };
    
    bool get_estancia();
    void set_estancia(bool);
};

bool Cliente::get_estancia(){
    return estancia;
}

void Cliente::set_estancia(bool est){
    estancia = est;
}

#endif