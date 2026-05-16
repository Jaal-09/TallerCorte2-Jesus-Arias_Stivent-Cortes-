#include "Estudiante.h"
#include "Curso.h"

using namespace std;

/**
 * @brief 
 * @class Estudiante que hereda de Persona
 * Llama al constructor de Persona y luego inicializa los atributos propios
 */

Estudiante::Estudiante(string nombre, string apellido, int edad, string documento, string codigo, int semestre, double promedio): Persona(nombre, apellido, edad, documento){
    this->codigo = codigo;
    this->semestre = semestre;
    this->promedio = promedio;
}

//Destructor
Estudiante::~Estudiante(){
    //No hay nada que liberar
}

