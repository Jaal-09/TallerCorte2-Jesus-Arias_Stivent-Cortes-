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

//Setters
void Persona::setNombre(string nombre){
    this->nombre = nombre;
}

void Persona::setApellido(string apellido){
    this->apellido = apellido;
}

void Persona::setEdad(int edad){
    //Validación de edad
    if(edad >= 0 && edad <= 110){
        this->edad = edad;
    } else{
        cerr << "Error: edad no válida (" << edad << "). Debe estar entre 0 y 110. " << endl;
    }
}

void Persona::setDocumento(string documento){
    this->documento = documento;
}

//Metodo para mostrar la información

void Persona::mostrarInformacion() const{
    cout << "       DATOS PERSONALES        " << endl;
    cout << "Nombre:        " << this->nombre << " " << this->apellido <<endl;
    cout << "Edad:          " << this->edad << " años " << endl;
    cout << "Documento:   " << this->documento << endl;
}






