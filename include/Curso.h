#ifndef CURSO_H
#define CURSO_H


#include <iostream>
#include <string>
#include <vector>


//Declaracion anticipada para evitar includes circulares
class Profesor;
class Estudiante;

/**
 * @brief
 * @class Curso
 * Representa un curso académico
 */

 class Curso{
    private:
        std::string nombreCurso;
        std::string codigoCurso;
        int creditos;
        Profesor* profesor;
        std::vector<Estudiante*> estudiantes;

    public:
        /**
         * @brief Constructor de Curso
         * @param nombreCurso Nombre del curso
         * @param codigoCurso Código unico del curso
         * @param creditos Número de creditos
         */
        Curso(std::string nombreCurso, std::string codigoCurso, int creditos);

        /**
         * @brief Destructor de curso
         * 
         */

        ~Curso();

        //Getters
        std::string getNombreCurso() const;
        
        std::string getCodigoCurso() const;

        int getCreditos() const;

        Profesor* getProfesor() const;

        //Setters
        void setNombreCurso(std::string nombreCurso);

        void setCodigoCurso(std::string codigoCurso);

        void setCreditos(int creditos);

        //Metodos principales

        /**
         * @brief Registra un profesor para el curso
         * @param prof Puntero al profesor
         */
        void registrarProfesor(Profesor* prof);

        /**
         * @brief Registra un estudiante en el curso
         * @param est Puntero al estudiante
         */
        void registrarEstudiante(Estudiante*est);

        /**
        * @brief Muestra la información completa del curso
        */
        void mostrarInformacion() const;

        /**
         * @brief Muestra la lista de estudiantes inscritos
         */
        void mostrarEstudiantes() const;
 };

 #endif