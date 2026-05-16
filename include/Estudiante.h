#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include "Persona.h"

/**
 * @brief Clase Estudiante que hereda de Persona
 * 
 */

class Estudiante : public Persona{
    private:
        std::string codigo;
        int semestre;
        double promedio;

    public:
    //constructor
    Estudiante(std::string nombre, std::string apellido, int edad, std::string documento, std::string codigo, int semestre, double promedio);

    //Destructor
    ~Estudiante();
};

#endif
