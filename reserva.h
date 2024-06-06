/**
 * Proyecto Hotel
 * Shaula Suhail Paz Garay
 * A01712013
 * 06/Junio/2024
*/

#ifndef RESERVA_H
#define RESERVA_H

//Bibliotecas
#include <string>
#include <iostream>

//Variable para contar las reservas
int cont_r = 0;
class Reserva{
    //Declaracion de atributos privados
    private:
    int noches, tipo;
    std::string fecha_entrada, fecha_salida, registrado_a;

    //Declaracion de atributos publicos
    public:
    //Constructor default
    Reserva(): fecha_entrada(""), fecha_salida(""), noches(0), registrado_a(""), tipo(0){};
    //Constructor con datos
    Reserva(std::string ent, std::string sal, int noch, std::string reg, int tip): fecha_entrada(ent), fecha_salida(sal), noches(noch), registrado_a(reg), tipo(tip){};

    std::string get_entrada();
    std::string get_salida();
    int get_noches();
    std::string get_registrado();
    int get_tipo();
    void set_salida(std::string);
};

/**get_entrada getter de la entrada a la habitacion
 * 
 * Se obtiene la fecha en la que se empezo/empezara
 * a usar la habitacion
 * 
 * @param
 * @return fecha_entrada a la habitacion
 */
std::string Reserva::get_entrada(){
    return fecha_entrada;
}

/**get_salida getter de la fecha esperada para
 * desocupar la habitacion
 * 
 * Devuelve la fecha registrada para abanodnar la
 * habitacion
 * 
 * @param
 * @return fecha_salida
 */
std::string Reserva::get_salida(){
    return fecha_salida;
}

/**get_noches getter de las noches que se pasaran
 * en el cuarto
 * 
 * Devuelve cuantas noches se hospedara el huesped
 * que hizo la reservacion
 * 
 * @param
 * @return noches a hospedarse
 */
int Reserva::get_noches(){
    return noches;
}

/**get_registrado getter de la persona que reservo
 * el cuarto
 * 
 * Devuelve el nombre de la persona a la que se
 * hizo el registro de la habitacion
 * 
 * @param
 * @return registrado_a
 */
std::string Reserva::get_registrado(){
    return registrado_a;
}

/**get_tipo getter del tipo de habitacion que es
 * segun la tabla encontrada en el main
 * 
 * Regresa el tipo de habitacion solo con numero
 * 
 * @param
 * @return tipo
 */
int Reserva::get_tipo(){
    return tipo;
}

/**set_salida setter de la salida estimada de
 * la habitacion
 * 
 * Devuelve el dia que se registro para salir
 * de la habitacion
 * 
 * @param salida
 * @return
 */
void Reserva::set_salida(std::string salida){
    fecha_salida = salida;
}

#endif