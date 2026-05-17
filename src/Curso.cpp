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

/**
 * @brief Metodos para registar profesor y estudiante
 * 
 * @param prof 
 */

//Registrar Profesor
void Curso::registrarProfesor(Profesor* prof){
    if(prof != nullptr){
        this->profesor = prof;
        cout << "Profesor " << prof->getNombre() << " " << prof->getApellido() << " registrado en el curso " << this->nombreCurso << endl;
    } else{
        cerr << "Error: Profesor no válido" << endl;
    }
}

//Registrar Estudiante
void Curso::registrarEstudiante(Estudiante* est){
    if(est != nullptr){
        estudiantes.push_back(est);
        cout << "Estudiante " << est->getNombre() << " " << est->getApellido() << " registrado en el curso " << this->nombreCurso << endl;
    }
}

//Mostrar información del curso
void Curso::mostrarInformacion() const{
    cout << "       Información del Curso       " << endl;
    cout << " Nombre:       " << this->nombreCurso << endl;
    cout << " Código:       " << this->codigoCurso << endl;
    cout << " Creditos:     " << this->creditos << endl;

    if(profesor != nullptr){
        cout << " Profesor:  " << profesor->getNombre() << " " << profesor->getApellido() << endl;
    } else{
        cout << " Estudiantes: " << estudiantes.size() << " inscritos" << endl;
        cout << "_______________________________________" << endl;
    }
}

//Mostrar lista de estudiantes
void Curso::mostrarEstudiantes() const{
    if(estudiantes.empty()){
        cout << "No hay estudiantes inscritos en el curso " << this->nombreCurso << endl;
        return;
    }

    cout << "\n --- Estudiantes inscritos en " << this->nombreCurso << " ---" << endl;
    for(size_t i = 0; i < estudiantes.size(); i++){
        cout << i + 1 << ". " << estudiantes[i]->getNombre() << " " << estudiantes[i]->getApellido() << " (código: " << estudiantes[i]->getCodigo() << ")" << endl;
    }
}

