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
        cerr << "Error: Salario no válido (" << salario << "). Debe ser mayor a 0." << endl;
    }
}

//Metodo para asignar curso
void Profesor::asignarCurso(Curso* curso){
    if(curso != nullptr){
        curso->registrarProfesor(this);
        cout << "Profesor " << this->getNombre() << " asignado al curso " << curso->getNombreCurso() << endl;
    } else{
        cerr << "Error: curso no válido" << endl;
    }
}

//Mostrar información (override)
void Profesor::mostrarInformacion() const{
    //Llama al metodo de la clase base Persona
    Persona::mostrarInformacion();

    cout << "       Datos Profesionales     " << endl;
    cout << "Especialidad:      " << this->especialidad << endl;
    cout << "Salario:           $" << this->salario << endl; 
}
