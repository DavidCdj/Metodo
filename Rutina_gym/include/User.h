#ifndef USER_H
#define USER_H
#include <string>


class User
{
    private:
    string name, id, lesiones, enfermedades, password;
    int peso, altura;
    public:
        User(string, int, string,string,string, int,int); //constructor
        //metodos
};

User::User(string _name, int _id, string _password, int _altura, int _peso, string _lessiones, string _enfermedades)
{
    name=_name;
    id=_id;
    password= _password;
    altura= _altura;
    peso= _peso;
    lesiones = _lessiones;
    enfermedades = _enfermedades;
}

#endif // USER_H
