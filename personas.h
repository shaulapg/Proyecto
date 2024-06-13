/**
 * Proyecto Hotel
 * Shaula Suhail Paz Garay
 * A01712013
 * 06/Junio/2024
*/

#ifndef PERSONAS_H
#define PERSONAS_H

//Bibliotecas
#include <string>
#include <iostream>
#include <sstream>

//Archivos a usar para su alteracion
#include "reserva.h" //Hacer reservas
#include "habitacion.h" //Checar cupos de habitaciones

//Variables para contar las reservas
int cont_res = 0;
int num_res = 0;
class Personas{
    //Atributos protegidos de la clase
    protected:
    std::string id, nombre, contacto;
    //Creacion de apuntadores para 20 objetos de tipo reserva
    Reserva *res[20];

    //Atributos publicos
    public:
    //Constructor default
    Personas(){};
    //Constructor con datos
    Personas(std::string nom, std::string cont): nombre(nom), contacto(cont){};

    //Declaracion de metodo abstracto ser sobreescrito mas tarde
    virtual float reservar(int, int) = 0;

    std::string get_id();
    std::string get_nombre();
    std::string get_contacto();
    void set_id(std::string);
    void set_contacto(std::string);
    virtual void imprime() = 0;
};

/**get_id getter del atributo id
 *
 * @param
 * @ return id
*/
std::string Personas::get_id(){
    return id;
}

/**get_id getter del atributo nombre
 *
 * @param
 * @ return nombre
*/
std::string Personas::get_nombre(){
    return nombre;
}

/**get_id getter del atributo contacto
 *
 * @param
 * @ return contacto
*/
std::string Personas::get_contacto(){
    return contacto;
}

/**get_id setter del atributo id
 *
 * @param string del nuevo id
 * @ return
*/
void Personas::set_id(std::string i){
    id = i;
}

/**get_id setter del atributo id
 *
 * @param string del nuevo contacto
 * @ return
*/
void Personas::set_contacto(std::string cont){
    contacto = cont;
}

//Contador de empleados para asignacion de id
int emp_id = 0;
class Empleado : public Personas{
    //Atributo privado
    private:
    bool trabajando;

    //Atributos publicos
    public:
    //Constructor default
    Empleado(){};
    //Constructor con datos
    Empleado(std::string nom, std::string cont, bool trab): Personas(nom, cont), trabajando(trab) {
        //Variable temporal para concatenar letra de identificacion y numero
        std::stringstream set_i;
        //Concatenar
        set_i << "E" << emp_id;
        //Asignacion del nuevo id
        set_id(set_i.str());
        //Aumento para el proximo id
        emp_id++;
    }

    void agrega_reserva(Reserva *);
    float reservar(int, int);
    void imprime();
    bool get_trabajando();
    void set_trabajando(bool);
    void muestra_reservas();
};

/**agrega_reserva crea una nueva reserva
 *
 * usa el objeto previamente creado de reserva
 * para registrarla en la lista de reservas
 * 
 * @param Reserva * reserva a realizar
 * @ return
*/
void Empleado::agrega_reserva(Reserva * objeto){
    if (cont_res < 20){
        res[cont_res] = objeto;
        cont_res++;
    }
}

/**reservar calcula el precio de la reserva
 *
 * toma en cuenta las noches y tipo de habitacion
 * para calcular el precio de la reserva
 * 
 * @param int tipo de habitacion, int numero de
 * noches
 * @ return float precio de la habitacion
*/
float Empleado::reservar(int tip, int noch){
    //Declaracion para el precio a devolver
    float precio = 0;
    //Switch segun el tipo de habitacion
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
    //Precio con descuento de empleado
    precio = precio * 0.85;
    return precio;
}

/**imprime se encarga de imprimir todos los atributos
 * de el objeto dado
 * 
 * Imprime todos los atributos y trabaja en conjunto a 
 * muestra_empleado
 *
 * @param
 * @ return
*/
void Empleado::imprime(){
    std::cout << "|ID: " << id << std::endl;
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Contacto: " << contacto << std::endl;
    std::cout << "|Esta trabajando: " << trabajando << std::endl;
    std::cout << std::endl;
}

/**get_trabajando getter del estado del trabajador (en
 * trabajo o no)
 *
 * @param
 * @ return bool trabajando
*/
bool Empleado::get_trabajando(){
    return trabajando;
}

/**set_trabajando setter del atributo trabajando
 *
 * @param bool del estado de trabajador respecto
 * a su labor
 * @ return
*/
void Empleado::set_trabajando(bool disp){
    trabajando = disp;
}

/**muestra_reservas muestra todas las reservas
 * registrados previamente
 * 
 * Manda a llamar a todas las reservas una por una.
 * No se encarga de imprimirlas, pero si de pasar
 * una por una para que otra funcion se encargue de 
 * imprimirlas
 * 
 * @param
 * @return
*/
void Empleado::muestra_reservas(){
    for(int i = 0; i < cont_res; i++){
        res[i]->imprime();
    }
}


//Variable para manejar el id de los clientes
int cliente_id = 0;
class Cliente : public Personas{
    //Declaracion de atributos privados
    private:
    bool estancia;

    //Declaracion de atributos publicos
    public:
    //Constructor default
    Cliente(){};
    //Constructor con datos
    Cliente(std::string nom, std::string cont, bool est): Personas(nom, cont), estancia(est){
        //Auxiliar para asignacion de id
        std::stringstream set_i;
        //Concatenar la letra de identificacion y el numero
        set_i << "C" << cliente_id;
        //Asignacion del nuevo id
        set_id(set_i.str());
        //Aumento del contador para el proximo id
        cliente_id++;;
    };

    float reservar(int, int);
    
    void imprime();
    bool get_estancia();
    void set_estancia(bool);
};

/**reservar toma el objeto de reserva precreado
 * y lo registra para que se reserve formalmente
 *
 * Se calcula el precio por la estadia en el
 * hotel segun la habitacion
 * 
 * @param Reserva * reserva a registrar
 * @ return precio de la reserva
*/
float Cliente::reservar(int tip, int noch){
    float precio = 0;
    //Switch para asignar el precio segun la habitacion
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
    //Se devuelve el precio segun el proceso anterior
    return precio;
}

/**get_estancia getter de estancia
 *
 * Para saber si el cliente se encuentra hospedado
 * en el hotel actualmente
 * 
 * @param
 * @return estancia actual
*/
bool Cliente::get_estancia(){
    return estancia;
}

/**set_estancia setter de la estancia
 *
 * Registra la salida o entrada de una persona del hotel
 * 
 * @param bool est a punto de cmbiar
 * @ return
*/
void Cliente::set_estancia(bool est){
    estancia = est;
}

/**imprime se encarga de mostrar los datos de los objetos
 *
 * Trabaja en conjunto con muestra_clientes oara desplegar
 * toda la informacion de todos los clientes
 * 
 * @param
 * @ return
*/
void Cliente::imprime(){
    std::cout << "|Id: " << id << std::endl;
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Contacto: " << contacto << std::endl;
    std::cout << "|Estancia: " << estancia << std::endl;
    std::cout << std::endl;
}

#endif