#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>


class User
{
    private:
    std::string name, id, lesiones, enfermedades, password;
    int peso, altura;
    public:
        //User(std::string, int);
        User(std::string, int, std::string, int, int, std::string, std::string); //constructor
        //metodos

};

User::User( std::string _name, int _id, std::string _password, int _altura, int _peso, std::string _lessiones, std::string _enfermedades)
{
    name = _name;
    id = _id;
    password = _password;
    altura = _altura;
    peso = _peso;
    lesiones = _lessiones;
    enfermedades = _enfermedades;
}



#endif // USER_H

