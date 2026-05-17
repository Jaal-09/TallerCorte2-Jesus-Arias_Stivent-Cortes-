/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Punto de entrada del sistema de registro universitario
 * @version 1.0
 * @date 2026-05-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <vector>

//Includes del proyectp
#include "Menu.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Curso.h"
#include "Matricula.h"

using namespace std;

int main(){

    //Vectores para almacenar datos
    vector<Estudiante*> estudiantes;
    vector<Profesor*> profesores;
    vector<Curso*> cursos;
    vector<Matricula*> matriculas;

    int opcion;

    cout << "       SISTEMA DE GESTIÓN UNIVERSITARIA        " << endl;

    do{
        mostrarMenu();
        cout << "Seleccione: ";
        cin >> opcion;

        switch(opcion){
            case 1: registrarEstudiante(estudiantes); break;
            case 2: registrarProfesor(profesores); break;
            case 3: crearCurso(cursos, profesores); break;
            case 4: matricularEstudiante(matriculas, estudiantes, cursos); break;
            case 5: asignarNota(matriculas); break;
            case 6: mostrarEstudiantes(estudiantes); break;
            case 7: mostrarProfesores(profesores); break;
            case 8: mostrarCursos(cursos); break;
            case 9: mostrarMatriculas(matriculas); break;
            case 10: cout << "\n Hasta Pronto " << endl; break;
            default: cout << "Opcion incorrecta. " << endl;
        }
    }while(opcion != 10);

    //Liberar la memoria
    liberarMemoria(estudiantes, profesores, cursos, matriculas);

    return 0;
}