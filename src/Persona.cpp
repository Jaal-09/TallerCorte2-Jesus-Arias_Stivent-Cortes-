#include "Persona.h"

using namespace std;

/**
 * @brief Implementación de la clase Persona
 * @param nombre, apellido, documento tipo string
 * @param edad tipo int
 * 
 */


 //Constructor 
 Persona::Persona(string nombre, string apellido, int edad, string documento){
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->documento = documento;
 }

