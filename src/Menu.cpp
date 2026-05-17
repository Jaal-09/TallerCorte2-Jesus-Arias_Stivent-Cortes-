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
