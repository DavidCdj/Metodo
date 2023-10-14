#ifndef USER_H
#define USER_H
#include <string>


class User
{
    //atributos
    private:
        std:: string name, lesiones, enfermedades, password;
        int peso, altura, id, edad;
    //metodos
    public:
        User(std::string, int, std::string, std::string, std::string, int,int,int); //constructor

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

        void setPeso(int);
        int getPeso();

        void setAltura(int);
        int getAltura();

        void setEdad(int);
        int getEdad();

};
//constructor
User::User(std::string _name, int _id, std::string _password,  std::string _lessiones, std::string _enfermedades, int _altura, int _peso, int _edad)
{
    name=_name;
    id=_id;
    password= _password;
    altura= _altura;
    peso= _peso;
    lesiones = _lessiones;
    enfermedades = _enfermedades;
    edad= _edad;
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

void User::setPeso(int _peso)
{
    peso=_peso;
}

int User::getPeso()
{
    return peso;
}

void User::setAltura(int _altura)
{
    altura=_altura;
}
int User::getAltura()
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
#endif // USER_H
