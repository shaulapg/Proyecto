#ifndef PERSONAS_H
#define PERSONAS_H

#include<string>
#include<iostream>

class Personas{
    private:
    int id;
    std::string nombre, contacto;


    public:
    Personas(): id(0), nombre(""), contacto(""){};
    Personas(int i, std::string nom, std::string cont): id(i), nombre(nom), contacto(cont){};

    int get_id();
    std::string get_nombre();
    std::string get_contacto();
    void set_id(int);
    void set_nombre(std::string);
    void set_contacto(std::string);
};

int Personas::get_id(){
    return id;
}

std::string Personas::get_nombre(){
    return nombre;
}

std::string Personas::get_contacto(){
    return contacto;
}

void Personas::set_id(int i){
    id = i;
}

void Personas::set_nombre(std::string nom){
    nombre = nom;
}

void Personas::set_contacto(std::string cont){
    contacto = cont;
}


class Empleado : public Personas{
    private:
    bool disponibilidad;


    public:
    Empleado(): Personas(), disponibilidad(false){};
    Empleado(int i, std::string nom, std::string cont, bool disp): Personas(i, nom, cont), disponibilidad(disp){};

    float cobrar(float, float);

    bool get_disponibilidad();
    void set_disponibilidad(bool);
};

float Empleado::cobrar(float cobro, float entregado){
    float cambio = cobro - entregado;
    return cambio;
}

bool Empleado::get_disponibilidad(){
    return disponibilidad;
}

void Empleado::set_disponibilidad(bool disp){
    disponibilidad = disp;
}


class Cliente : public Personas{
    private:
    bool estado;

    public:
    Cliente(): Personas(), estado(false){};
    Cliente(int i, std::string nom, std::string cont, bool est): Personas(i, nom, cont), estado(est){};

    //pedir_reserva()
    
    bool get_estado();
    void set_estado(bool);
};

/*void Cliente::pedir_reserva(){
    kkk
}
*/

bool Cliente::get_estado(){
    return estado;
}

void Cliente::set_estado(bool est){
    estado = est;
}

#endif