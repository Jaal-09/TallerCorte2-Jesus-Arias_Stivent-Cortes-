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

 //destructor
 Persona::~Persona(){
    //Es vital es importante para la herencia
 }

 //Getters
string Persona::getNombre() const{
    return this->nombre;
}

string Persona::getApellido() const{
    return this->apellido;
}

int Persona::getEdad() const{
    return this->edad;
}

string Persona::getDocumento() const{
    return this->documento;
}



