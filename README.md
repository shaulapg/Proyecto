# Proyecto

# Objetivo 
El objetivo es estructurar un hotel. En este hotel se plantea la existencia de las clases:

Hotel: encargado de gestionar las habitaciones, empleados y clientes

Personas: clase madre de empleados y clientes

Empleados: pueden hacer reservas con descuento

Clientes: personas que harán las reservas de las habitaciones

Habitaciones: Podrán ser reservadas, se puede hacer varias reservas al mismo cuarto con el objetivo de poder apartarlos a lo largo del tiempo (ej: una de 18 al 24 y la otora reserva del 28 al 31)

Reserva: manejo de las reservaciones de las habitaciones

Al ingresar se puede elegir entrar como administrados, empleado o cliente para poder ver varias funciones. En el caso del administrador, se pueden dar de alta empleados, clientes y habitaciones, asi como consultar estas mismas, ademas de consultar conjuntamente clientes y empleados usando la opcion "Mostrar a todas las personas" del menu de administrador. Por otro lado los empleados y clientes pueden hacer las mismas cosas: consultar sus datos, cambiar su constacto y hacer una reserva, esto ultimo con la unica diferencia de que los empleados tienen un descuento.

# Consideraciones
Casos de error: Empalmamiento de las reservas, se debe checar disponibilidad antes de reservar porque el programa no es capaz de evitar empalmamientos.

El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos
compilar con: "g++ personas.h reserva.h hotel.h habitacion.h main.cpp"
correr en linux: "/a.out"
correr en windows: "a.exe

# Versiones
Versión 1: _SICT0301A - Evalúa los componentes que integran una problemática_: Se agregó el UML para plantear la base. Se agregó link al proyecto anterior.

Versón 2: Comienzo desde cero. Se agregó UML nueva y se agregaron casos de error. _SICT0303A - Implementa acciones científicas_: Se agrego primer archivo de herencias, con las clases cliente y empleado de la clase madre personas.h. La clase personas.h cuenta con sobrecarga en cada clase, es decir, se encuentra en tres casos diferentes, esto con los contructores default y los que toman datos [ln 14, 15, 56, 57, 84,85]. 

Versión 3: Se agregaron mas clases (habitacion.h y hotel.h) y el main, la clase habitacion.h cuenta con sobrecarga en los constructores [ln 15-19] . Actualización de UML. Se agregaron apuntadores para implementar polimorfismo en la clase Hotel en el archivo hotel.h para los objetos tipo empleados, clientes y habitacion [ln 17-20] para poder crearlos [ln 35, 40, 45]. Corrccion de la esturctura de las clases: getters, setters y constructores.

Versión 4: Se agregó el main completo y se modificaron todas las clases para adpatarse a los requerimientos: se implemento la clase abstracta "Personas" en personas.h [ln 38, 45] asimismo se implemento la sobreescritura con esta clase abstracta. Se actualizo el UML. Se agrego la clase reserva en reserva.h con su apuntador en personas.h para que este tipo de objetos pueda crear reservas. Se agregaron comentarios. Se expandio el main para mejor uso del codigo.

Version 5: Correccion de todas las clases. Se agregaron comentarios y  _SICT0303A - Implementa acciones científicas_: se implemento la capacidad de agregar todos los tipos de objetos. Se agrego una nueva lista: Personas, que incluye tanto clientes como empleados para el correcto uso de polimorfismo. Se adapto el UML a las modificaciones del codigo. Se expandio el main para implementar nuevas funciones y se adoapto el codigo para mejor creacion de reservas. Se agrego un arreglo con apuntadores para objetos de tipo reserva en personas.h [ln 28] y correccion de apuntadores.
