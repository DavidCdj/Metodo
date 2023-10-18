#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>


class User
{
    //atributos
    private:
        std:: string name, lesiones, enfermedades, password,sexo;
        int  id, edad;
        float peso, altura;
    //metodos
    public:
        User(std::string, int, std::string, std::string, std::string, float, float,int, std::string); //constructor
        User();
        void setName(std::string);
        std::string getName();

        void setID( int);
        int getID();

        void setLesiones(std:: string);
        std::string getLesiones();

        void setEnfermedades(std::string);
        std::string getEnfermedades();

        void setPassword(std::string);
        std::string getPassword();

        void setPeso(float);
        float getPeso();

        void setAltura(float);
        float getAltura();

        void setEdad(int);
        int getEdad();

        void setSexo(std::string);
        std::string getSexo();

        void Imprimir();

};
//constructor
User::User(std::string _name, int _id, std::string _password,  std::string _lessiones,
           std::string _enfermedades, float _altura, float _peso, int _edad,  std::string _sexo)
{
    name=_name;
    id=_id;
    password= _password;
    altura= _altura;
    peso= _peso;
    lesiones = _lessiones;
    enfermedades = _enfermedades;
    edad= _edad;
    sexo= _sexo;
}
User::User()
{

}

void User::setName(std::string _name)
{
    name = _name;
}

std::string User::getName()
{
    return name;
}

void User::setID(int _id)
{
    id=_id;
}

int User::getID()
{
    return id;
}

void User::setLesiones(std::string _lesiones)
{
    lesiones=_lesiones;
}

std::string User::getLesiones()
{
    return lesiones;
}

void User::setEnfermedades(std::string _enfermedades)
{
    enfermedades= _enfermedades;
}

std::string User::getEnfermedades()
{
    return enfermedades;
}

void User::setPassword(std::string _password)
{
    password= _password;
}

std::string User::getPassword()
{
    return password;
}

void User::setPeso(float _peso)
{
    peso=_peso;
}

float User::getPeso()
{
    return peso;
}

void User::setAltura(float _altura)
{
    altura=_altura;
}
float User::getAltura()
{
     return altura;
}

void User::setEdad(int _altura)
{
    altura=_altura;
}
int User::getEdad()
{
    return altura;
}

void User::setSexo(std::string _sexo)
{
    sexo=_sexo;
}
std::string User::getSexo()
{
     return sexo;
}
#endif // USER_H
