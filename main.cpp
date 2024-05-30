#include <iostream>
#include <string>

#include "personas.h"
#include "hotel.h"
#include "habitacion.h"

main(){
    Hotel hotel;
    std::cout << "Creacion de ejemplos" << std::endl;
    hotel.agrega_empleado("Juan", "juan@gmail.com", false);
    hotel.agrega_empleado("Ana", "ana@gmail.com", true);
    hotel.agrega_empleado("José", "jose@gmail.com", true);
    hotel.muestra_empleado();
}