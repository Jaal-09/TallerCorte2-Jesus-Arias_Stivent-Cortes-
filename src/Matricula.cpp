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

//Getters
Estudiante* Matricula::getEstudiante() const{
    return this->estudiante;
}

Curso* Matricula::getCurso() const {
    return this->curso;
}

string Matricula::getEstado() const{
    return this->estado;
}

double Matricula::getNotaFinal() const{
    return this->notaFinal;
}

//Setters
void Matricula::setEstado(string estado){
    this->estado = estado;
}

void Matricula::asignarNota(double nota){
    //Validación de nota
    if(nota >= 0.0 && nota <= 5.0){
        this->notaFinal = nota;
        cout << " Nota: " << nota << " asignada a " << estudiante->getNombre() << " " << estudiante->getApellido() << " en el curso " << curso->getNombreCurso() << endl;

        //Si la nota es aprobatoria cambiamos el estado
        if(nota >= 3.0 && estado == "Activa"){
            setEstado("Aprobada");
        } else if( nota < 3.0 && estado == "Activa"){
            setEstado("Reprobada");
        }
    }else{
        cerr << "Error: Nota no válida (" << nota << "). Debe estar entre 0.0 y 5.0" << endl;
    }
}

//Mostrar información
void Matricula::mostrarInformacion() const{
    cout << "       Información de Matricula        " << endl;
    cout << " Estudiante:  " << estudiante->getNombre() << " " << estudiante->getApellido() << endl;
    cout << " Curso:       " << curso->getNombreCurso() << " (" << curso->getCodigoCurso() << ") " << endl;
    cout << " Estado:      " << estado << endl;
    cout << " Nota Final:  " << notaFinal << endl;
    cout << " __________________________________ " << endl;
}

