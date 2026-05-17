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

        //Getters
        Estudiante* getEstudiante() const;

        Curso* getCurso() const;

        std::string getEstado() const;

        double getNotaFinal() const;

        //Setters
        void setEstado(std::string estado);

        /**
         * @brief Asignar una nota final al estudiante
         * @param nota Nota final (0.0 a 5.0)
         */
        void asignarNota(double nota);

        //Metodos 

        /**
         * @brief Muestra la información completa de la matricula
         * 
         */
        void mostrarInformacion() const;
 };

 #endif