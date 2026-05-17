#include "Profesor.h"
#include "Curso.h"

using namespace std;

/**
 * @brief Constructor de profesor
 * 
 * Llama al constructor de Persona y luego inicializa los atributos propios
 */

 Profesor::Profesor(string nombre, string apellido, int edad, string documento, string especialidad, double salario) : Persona(nombre, apellido, edad, documento){
    this->especialidad = especialidad;
    this->salario = salario;
 }

 //Destructor
 Profesor::~Profesor(){
    //Nada que liberar
 }

//Getters
string Profesor::getEspecialidad() const{
    return this->especialidad;
}

double Profesor::getSalario() const {
    return this->salario;
}

//Setters
void Profesor::setEspecialidad(string especialidad){
    this->especialidad = especialidad;
}

void Profesor::setSalario(double salario){
    //Validacion para el salario
    if(salario > 0){
        this->salario = salario;
    } else{
        cerr << "Error: Slario no válido (" << salario << "). Debe ser mayor a 0." << endl;
    }
}
