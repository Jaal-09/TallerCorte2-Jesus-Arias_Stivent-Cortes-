#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <string>
#include "Persona.h"

/**
 * @brief 
 *@class La clase Profesor Hereda de la clase Persona
 * 
 * Representa a un Profesor con atributos especificos como especialidad y salario
 */

 class Profesor : public Persona{
    private:
        std::string especialidad;
        double salario;
    
    public:
        /**
        * @brief Constructor de Profesor
        * @param nombre Nombre del profesor
        * @param apellido Apellido del profesor
        * @param edad Edad del profesor
        * @param documento Documento de identidad
        * @param especialidad Especialidad del profesor
        * @param salario Salario del profesor
        */

        Profesor(std::string nombre, std::string apellido, int edad, std::string documento, std::string especialidad, double salario);

        //Destructor
        ~Profesor();

        //Getters
        std::string getEspecialidad() const;

        double getSalario() const;

        //Setters
        void setEspecialidad(std::string especialidad);

        void setSalario(double salario);

        /**
         * @brief Asigna un curso al profesor
         * @param curso Puntero al curso que se asignará
         */

         void asignarCurso(class Curso* curso);

         /**
          * @brief Muestra la información completa del profesor
          * @override Sobrescribe el método de Persona
          */

        void mostrarInformacion() const override;

 };

 #endif