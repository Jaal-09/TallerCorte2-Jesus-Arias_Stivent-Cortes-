#include "Menu.h"
#include "Estudiante.h"
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