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

