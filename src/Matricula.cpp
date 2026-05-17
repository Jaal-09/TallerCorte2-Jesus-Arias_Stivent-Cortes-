#include "Matricula.h"
#include "Estudiante.h"
#include "Curso.h"

using namespace std;

//Constructor
Matricula::Matricula(Estudiante* estudiante, Curso* curso, string estado){
    this->estudiante = estudiante;
    this->curso = curso;
    this->estado = estado;
    this->notaFinal = 0.0; //Inicialmente sin nota
}

//Destructor 
Matricula::~Matricula(){
    //Aunque no liberamos estudiante ni curso, son gestionados por el sistema
}