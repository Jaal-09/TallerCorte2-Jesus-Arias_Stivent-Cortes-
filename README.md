# 🎓 Sistema de Gestión Universitaria

## 📝 Descripción

Sistema académico desarrollado en **C++** para la gestión de:
- Estudiantes
- Profesores
- Cursos
- Matrículas
- Asignación de notas

## 🏗️ Estructura del Proyecto
TallerCorte2/
│
├── include/ # Archivos de cabecera (.h)
│ ├── Persona.h
│ ├── Estudiante.h
│ ├── Profesor.h
│ ├── Curso.h
│ ├── Matricula.h
│ └── Menu.h
│
├── src/ # Implementación (.cpp)
│ ├── Persona.cpp
│ ├── Estudiante.cpp
│ ├── Profesor.cpp
│ ├── Curso.cpp
│ ├── Matricula.cpp
│ └── Menu.cpp
│
├── docs/ # Documentación y diagramas UML
│ └── diagrama_clases.png
│
├── main.cpp # Punto de entrada
├── CMakeLists.txt # Configuración de CMake
├── .gitignore
└── README.md


## 🖥️ Menú Principal

| Opción | Funcionalidad |
|--------|---------------|
| 1 | Registrar estudiante |
| 2 | Registrar profesor |
| 3 | Crear curso |
| 4 | Matricular estudiante |
| 5 | Asignar nota |
| 6 | Mostrar estudiantes |
| 7 | Mostrar profesores |
| 8 | Mostrar cursos |
| 9 | Mostrar matrículas |
| 10 | Salir |

### Cómo compilar y ejecutar

### Opción 1: Compilación directa con g++

```bash
# Compilar
g++ -Iinclude -o universidad src/*.cpp main.cpp

# Ejecutar
./universidad