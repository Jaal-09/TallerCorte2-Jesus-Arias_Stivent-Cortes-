#ifndef MATRICULA_H
#define MATRICULA_H

#include <iostream>
#include <string>

//Declaración anticipada
class Estudiante;
class Curso;

/**
 * @brief Clase Matricula
 * 
 * Representa la inscripción de un estudiante en un curso
 * con su estado y nota final
 */

 class Matricula{
    private:
        Estudiante* estudiante;
        Curso* curso;
        std::string estado;
        double notaFinal;
    
    public:
        /**
         * @brief Constructor de Matricula
         * @param estudiante Puntero al estudiante
         * @param curso Puntero al curso
         * @param estado Estado inicial de la matrícula
         */
        Matricula(Estudiante* estudiante, Curso* curso, std::string estado);

        //Destructor
        ~Matricula();

        
 }