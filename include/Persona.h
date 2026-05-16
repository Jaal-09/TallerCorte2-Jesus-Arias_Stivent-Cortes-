#ifndef PERSONA_H
#define Persona_H

#include <iostream>
#include <string>

/**
 * @brief Clase base persona
 * 
 */

class Persona{
    private:

        std::string nombre;
        std::string apellido;
        int edad;
        std::string documento;

    public:
        //Constructor
        Persona(std::string nombre, std::string apellido, int edad, std::string dcoumento);

        //Destructor
        virtual ~Persona();

        //Getters
        std::string getNombre() const;
        std::string getApellido() const;
        int getEdad() const;
        std::string getDocumento() const;

        //setters
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setEdad(int edad);
        void setDocumento(std::string docuemnto);

        virtual void mostrarInformacion() const;


};

#endif