#include "Menu.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Curso.h"
#include "Matricula.h"

#include <iostream>
#include <limits>

using namespace std;

//funciones auxiliares privadas

static void limpiarBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static void pausar(){
    cout << "\nPresione Enter para continuar...";
    limpiarBuffer();
    cin.get();
}

void mostrarMenu(){
    cout << "\n========================================" << endl;
    cout << "                MENÚ PRINCIPAL           " << endl;
    cout << "========================================" << endl;
    cout << " 1. Registrar estudiante" << endl;
    cout << " 2. Registrar profesor" << endl;
    cout << " 3. Crear curso" << endl;
    cout << " 4. Matricular estudiante" << endl;
    cout << " 5. Asignar nota" << endl;
    cout << " 6. Mostrar estudiantes" << endl;
    cout << " 7. Mostrar profesores" << endl;
    cout << " 8. Mostrar cursos" << endl;
    cout << " 9. Mostrar matrículas" << endl;
    cout << "10. Salir" << endl;
    cout << "========================================" << endl;
}

//Registrar estudiante
void registrarEstudiante(vector<Estudiante*>& estudiantes){
    string nombre, apellido, documento, codigo;
    int edad, semestre;
    double promedio;

     cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;
    
    cout << "Nombre: ";
    cin >> nombre;
    
    cout << "Apellido: ";
    cin >> apellido;
    
    cout << "Edad: ";
    cin >> edad;
    
    cout << "Documento: ";
    cin >> documento;
    
    cout << "Código de estudiante: ";
    cin >> codigo;
    
    cout << "Semestre (1-12): ";
    cin >> semestre;
    
    cout << "Promedio (0.0-5.0): ";
    cin >> promedio;
    
    Estudiante* nuevo = new Estudiante(nombre, apellido, edad, documento, codigo, semestre, promedio);
    estudiantes.push_back(nuevo);
    
    cout << "\n Estudiante registrado exitosamente." << endl;
    pausar();
}

//Registrar profesor
void registrarProfesor(vector<Profesor*>& profesores){
    string nombre, apellido, documento, especialidad;
    int edad;
    double salario;

    cout << "\n--- Registro de Profesor ---" << endl;

    cout << "Nombre: ";
    cin >> nombre;
    
    cout << "Apellido: ";
    cin >> apellido;
    
    cout << "Edad: ";
    cin >> edad;
    
    cout << "Documento: ";
    cin >> documento;
    
    cout << "Especialidad: ";
    cin >> especialidad;
    
    cout << "Salario: ";
    cin >> salario;
    
    Profesor* nuevo = new Profesor(nombre, apellido, edad, documento, especialidad, salario);
    profesores.push_back(nuevo);
    
    cout << "\n Profesor registrado exitosamente." << endl;
    pausar();
}

//Metodo para crear curso
void crearCurso(vector<Curso*>& cursos, vector<Profesor*>& profesores) {
    string nombreCurso, codigoCurso;
    int creditos;
    
    cout << "\n--- CREACIÓN DE CURSO ---" << endl;
    
    cout << "Nombre del curso: ";
    cin >> nombreCurso;
    
    cout << "Código del curso: ";
    cin >> codigoCurso;
    
    cout << "Créditos (1-6): ";
    cin >> creditos;
    
    Curso* nuevoCurso = new Curso(nombreCurso, codigoCurso, creditos);
    
    // Asignar profesor si hay disponibles
    if (!profesores.empty()) {
        cout << "\nProfesores disponibles:" << endl;
        for (size_t i = 0; i < profesores.size(); i++) {
            cout << i + 1 << ". " << profesores[i]->getNombre() << " " 
                 << profesores[i]->getApellido() << endl;
        }
        
        int profesorIndex;
        cout << "Seleccione profesor (0 para ninguno): ";
        cin >> profesorIndex;
        
        if (profesorIndex > 0 && profesorIndex <= (int)profesores.size()) {
            nuevoCurso->registrarProfesor(profesores[profesorIndex - 1]);
        }
    } else {
        cout << "\n No hay profesores registrados." << endl;
    }
    
    cursos.push_back(nuevoCurso);
    cout << "\n Curso creado exitosamente." << endl;
    pausar();
}

//Metodo para Matricula
void matricularEstudiante(vector<Matricula*>& matriculas, vector<Estudiante*>& estudiantes, vector<Curso*>& cursos) {
    if (estudiantes.empty() || cursos.empty()) {
        cout << "\n⚠ Se necesitan estudiantes y cursos para matricular." << endl;
        pausar();
        return;
    }
    
    cout << "\n--- MATRICULACIÓN ---" << endl;
    
    // Mostrar estudiantes
    cout << "\nEstudiantes:" << endl;
    for (size_t i = 0; i < estudiantes.size(); i++) {
        cout << i + 1 << ". " << estudiantes[i]->getNombre() << " " 
             << estudiantes[i]->getApellido() << endl;
    }
    
    int estIndex;
    cout << "Seleccione estudiante: ";
    cin >> estIndex;
    
    // Mostrar cursos
    cout << "\nCursos:" << endl;
    for (size_t i = 0; i < cursos.size(); i++) {
        cout << i + 1 << ". " << cursos[i]->getNombreCurso() << endl;
    }
    
    int cursoIndex;
    cout << "Seleccione curso: ";
    cin >> cursoIndex;
    
    string estado;
    cout << "Estado (Activa/Cancelada): ";
    cin >> estado;
    
    if (estIndex > 0 && estIndex <= (int)estudiantes.size() &&
        cursoIndex > 0 && cursoIndex <= (int)cursos.size()) {
        
        Matricula* nueva = new Matricula(estudiantes[estIndex - 1], cursos[cursoIndex - 1], estado);
        matriculas.push_back(nueva);
        cursos[cursoIndex - 1]->registrarEstudiante(estudiantes[estIndex - 1]);
        
        cout << "\n Matrícula realizada." << endl;
    } else {
        cout << "\n Selección no válida." << endl;
    }
    pausar();
}

//Metodo registrar notas
void asignarNota(vector<Matricula*>& matriculas) {
    if (matriculas.empty()) {
        cout << "\n No hay matrículas." << endl;
        pausar();
        return;
    }
    
    cout << "\n--- ASIGNAR NOTA ---" << endl;
    
    // Mostrar solo matrículas activas
    vector<size_t> activas;
    for (size_t i = 0; i < matriculas.size(); i++) {
        if (matriculas[i]->getEstado() == "Activa") {
            activas.push_back(i);
            cout << activas.size() << ". " 
                 << matriculas[i]->getEstudiante()->getNombre() << " "
                 << matriculas[i]->getCurso()->getNombreCurso() << endl;
        }
    }
    
    if (activas.empty()) {
        cout << "No hay matrículas activas." << endl;
        pausar();
        return;
    }
    
    int seleccion;
    double nota;
    cout << "Seleccione: ";
    cin >> seleccion;
    cout << "Nota (0-5): ";
    cin >> nota;
    
    if (seleccion > 0 && seleccion <= (int)activas.size()) {
        matriculas[activas[seleccion - 1]]->asignarNota(nota);
    }
    pausar();
}

//Metodos para mostar los estudiantes

void mostrarEstudiantes(const vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        cout << "\n⚠ No hay estudiantes." << endl;
    } else {
        cout << "\n=== ESTUDIANTES ===" << endl;
        for (size_t i = 0; i < estudiantes.size(); i++) {
            cout << "\n--- Estudiante " << i + 1 << " ---" << endl;
            estudiantes[i]->mostrarInformacion();
        }
    }
    pausar();
}


//Metodo para mostrar los profesores
void mostrarProfesores(const vector<Profesor*>& profesores) {
    if (profesores.empty()) {
        cout << "\n⚠ No hay profesores." << endl;
    } else {
        cout << "\n=== PROFESORES ===" << endl;
        for (size_t i = 0; i < profesores.size(); i++) {
            cout << "\n--- Profesor " << i + 1 << " ---" << endl;
            profesores[i]->mostrarInformacion();
        }
    }
    pausar();
}