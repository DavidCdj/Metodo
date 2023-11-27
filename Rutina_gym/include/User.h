#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

//Clase usuario, se utiliza para generar al usuario como objeto, y tiene sus metodos getters y setters,
class User
{
    //atributos
    private:
        std:: string name, password;
        int  id, edad ;
        float peso, altura;
        char sexo,enfermedades, lesiones;
    //metodos
    public:
        User(std::string, int, std::string, float, char, float, char, int, char); //constructor
        User();
        void setName(std::string);
        std::string getName();

        void setID( int);
        int getID();

        void setLesiones(char);
        char getLesiones();

        void setEnfermedades(char);
        char getEnfermedades();

        void setPassword(std::string);
        std::string getPassword();

        void setPeso(float);
        float getPeso();

        void setAltura(float);
        float getAltura();

        void setEdad(int);
        int getEdad();

        void setSexo(char);
        char getSexo();

        //void Imprimir();

};
//constructor
User::User(std::string _name, int _id, std::string _password, float _altura,  char _lessiones,
           float _peso, char _enfermedades,   int _edad,  char _sexo)
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

void User::setLesiones(char _lesiones)
{
    lesiones=_lesiones;
}

char User::getLesiones()
{
    return lesiones;
}

void User::setEnfermedades(char _enfermedades)
{
    enfermedades= _enfermedades;
}

char User::getEnfermedades()
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

void User::setEdad(int _edad)
{
    edad=_edad;
}
int User::getEdad()
{
    return edad;
}

void User::setSexo(char _sexo)
{
    sexo=_sexo;
}
char User::getSexo()
{
     return sexo;
}

#endif // USER_H
