#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include "Persona.h"

/**
 * @brief Clase Estudiante que hereda de Persona
 * 
 * Representa a un estudiante con atributos especificos como código, semestre y promedio
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

    //Getters
    std::string getCodigo() const;
    int getSemestre() const;
    double getPromedio() const;

    //Setters
    void setCodigo(std::string codigo);
    void setSemestre(int semestre);
    void setPromedio(double promedio);

    //Metodo para inscribir curso aun sin implementar
    void inscribirCurso(class Curso* curso);

    /**
     * @brief Muestra informacion completa del estudiante
     * @override sobrescribe el metodo de Persona
     */
    void mostrarInformacion() const override;
};

#endif
