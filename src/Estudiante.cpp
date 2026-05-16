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

//Getters
string Estudiante::getCodigo() const{
    return this->codigo;
}

int Estudiante::getSemestre() const {
    return this->semestre;
}

double Estudiante::getPromedio() const {
    return this->promedio;
}

//Setters
void Estudiante::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Estudiante::setSemestre(int semestre){
    //Validacion de semestre
    if(semestre >= 1 && semestre <= 12){
        this->semestre = semestre;
    } else{
        cerr << "Error: semestre no válido (" << semestre << "). Debe estar entre 1 y maximo 12. " << endl;
    }
}

void Estudiante::setPromedio(double promedio) {
    if(promedio >= 0.0 && promedio <= 5.0){
        this->promedio = promedio;
    } else{
        cerr << "Error: Promedio no válido (" << promedio << "). Debe estar entre 0.0 y 5.0" << endl;
    }
}

//Metodo para inscribir curso
void Estudiante::inscribirCurso(Curso* curso){
    if(curso != nullptr){
        curso->registrarEstudiante(this);
        cout << "Estudiante " << this->getNombre() << " inscrito en el curso " << curso->getNombreCurso() << endl;
    } else{
        cerr << "Error: curso no válido" << endl;
    }
}

//Mostrar información (override)
void Estudiante::mostrarInformacion() const{
    //Realizamos un llamado al método de la clase base (Persona)
    Persona::mostrarInformacion();

    cout << "       Datos Academicos        " << endl;
    cout << "Código:            " << this->codigo << endl;
    cout << "Semestre:          " << this->semestre << endl;
    cout << "Promedio:          " << this->promedio << endl;
}