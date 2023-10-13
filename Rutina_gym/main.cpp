#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "User.h"

using namespace std;


/*
void Registro_User()
{

}*/

void Login_user(vector <User> user1)
{
    string nombre;
    string password;
    bool band=true;
   // int size = user1.;

    cout<<"-----Nombre de usuario: "<<endl;
    cin.ignore();
    getline(cin, nombre);


    for(int i=0; i<user1.size();i++)
    {
        if(nombre==user1[i].getName()  )
        {
            do
            {
                cout<<"Password"<<endl;
                getline(cin, password);
                if(password!=user1[i].getPassword())
                {
                    cout<<"Contrasenia incorrecta, vuleve a introducir tu clave"<<endl;
                    system("pause");
                    system("cls");

                }
                else
                    band=false;



            }while(band);
            break;
        }

        if(i==user1.size()-1)
        {
            cout<<"Usuario no encontrado"<<endl;
            system("pause");
        }
    }



}

char Menu_Inicio(char logs)
{
        int lm=0;
        bool rep= true;


        do
            {
                system("cls");
                cout<<"--------Rutina de Gym--------\n\n\r"<<endl;
                cout<<"1.- Usuario existente\n"<< "2.- nuevo usuario\n"<<"3.-salir\n"<<endl;
                cin>> logs;

                lm=(int)logs;
                // se utiliza valores de 49 al 51 porque son valores de 1 al 3 en ascii, para que el usuario no introduzca letras o  simbolos especiales
                if (lm<49 || lm>51)
                {
                    cout<<"ingrese una opcion valida"<<endl;
                    system("pause");
                    rep=true;
                }
                else
                    rep=false;

            }while(rep);

    return logs;


}



//leer archivo para declarar arrayñist y que devuelva el array list de usuarios

int main()
    {
        vector <User> users;
        char login=0;
        bool reps=true;
        //prueba de agregar usuarios
        for(int i=0; i<5;i++){
        User us("David Carmona", i, "ZVesda2125", "si", "sas", 123, 122);

        users.push_back(us);
        }


        for(int i=0; i<users.size();i++)
        {
            cout<<users[i].getID();
        }

        for(auto element: users){

            cout<< element.getPassword()<<endl;
            }
            system("pause");//fin de pruebas



    do{
         switch (Menu_Inicio(login))
            {
                case 49:
                    {
                        system("cls");
                        Login_user(users);
                    }
                break;

                case 50:
                    {
                        system("cls");
                        cout<<"Para registrar un usuario"<<endl;
                    }

                break;

                case 51:
                    {
                        reps=false;

                    }

                break;
            }
        }
        while(reps);

    }
