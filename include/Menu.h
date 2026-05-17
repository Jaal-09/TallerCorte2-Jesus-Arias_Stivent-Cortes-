#ifndef MENU_H
#define MENU_H

#include <vector>

//Declaracion anticipada de las clases
class Estudiante;
class Profesor;
class Curso;
class Matricula;

/**
 * @brief Muestra el menú principal en la consola
 * 
 */
void mostrarMenu();

/**
 * @brief Registrar un nuevo estudiante
 * @param estudiantes Vector de punteros a Estudiante
 */
void registrarEstudiante(std::vector<Estudiante*>& estudiantes);

/**
 * @brief Registra un nuevo profesor
 * @param profesores Vector de punteros a Profesor
 * 
 */
void registrarProfesor(std::vector<Profesor*>& profesores);

/**
 * @brief Crea un nuevo curso
 * @param cursos Vector de punteros a Curso
 * @param profesores Vector de profesores (para asignar)
 */
void crearCurso(std::vector<Curso*>& cursos, std::vector<Profesor*>& profesores);

/**
 * @brief Matricula un estudiante en un curso
 * @param matriculas Vector de punteros a Matricula
 * @param estudiantes Vector de estudiantes
 * @param cursos Vector de cursos
 */
void matricularEstudiante(std::vector<Matricula*>& matriculas, std::vector<Estudiante*>& estudiantes, std::vector<Curso*>& cursos);

/**
 * @brief Asigna una nota a la matricula
 * @param matriculas Vector de matriculas
 * 
 */
void asignarNota(std::vector<Matricula*>& matriculas);

/**
 * @brief Muestra todos los estudiantes
 * @param estudiantes Vector de estudiantes
 */
void mostrarEstudiantes(const std::vector<Estudiante*>& estudiantes);

/**
 * @brief Muestra todos los profesores
 * @param profesores Vector de profesores
 */
void mostrarProfesores(const std::vector<Profesor*>& profesores);

/**
 * @brief Muestra todos los cursos
 * @param cursos Vector de cursos
 */
void mostrarCursos(const std::vector<Curso*>& cursos);

/**
 * @brief Muestra todas las matriculas
 * @param matriculas Vector de matriculas
 */
void mostrarMatriculas(const std::vector<Matricula*>& matriculas);

/**
 * @brief Libera toda la memoria
 * @param estudiantes Vector de estudiantes
 * @param profesores Vector de profesores
 * @param cursos Vector de cursos
 * @param matriculas Vector de matriculas
 */
void liberarMemoria(std::vector<Estudiante*>& estudiantes, std::vector<Profesor*>& profesores, std::vector<Curso*>& cursos, std::vector<Matricula*>& matriculas);

#endif