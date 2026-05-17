#include "Curso.h"
#include "Profesor.h"
#include "Estudiante.h"

using namespace std;

//Constructor
Curso::Curso(string nombreCurso, string codigoCurso, int creditos){
    this->nombreCurso = nombreCurso;
    this->codigoCurso = codigoCurso;
    this->creditos = creditos;
    this->profesor = nullptr; //Inicialmente no tendra valor
}

Curso::~Curso(){
    //Solo limpiamos el vector
    estudiantes.clear();
}

//Getters
string Curso::getNombreCurso() const{
    return this->nombreCurso;
}

string Curso::getCodigoCurso() const{
    return this->codigoCurso;
}

int Curso::getCreditos() const{
    return this->creditos;
}

Profesor* Curso::getProfesor() const{
    return this->profesor;
}

//Setters
void Curso::setNombreCurso(string nombreCurso){
    this->nombreCurso = nombreCurso;
}

void Curso::setCodigoCurso(string codigoCurso){
    this->codigoCurso = codigoCurso;
}

void Curso::setCreditos(int creditos){
    //Validacion de los creditos
    if(creditos > 0 && creditos <= 6){
        this->creditos = creditos;
    } else{
        cerr << "Error: Créditos no válidos (" << creditos << "). Deben estar entre 1 y 6." << endl;
    }
}