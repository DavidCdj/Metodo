#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "User.h"

#define FILE_NAME "Usuarios.dat" //archivo en forma binaria

using namespace std;
vector <User> users;

bool OnlyLetters(string name_user) //recorre el string  que busca si introdujo solo letras, en casi de que si devuelve false.
{
    bool flagss;
    int conta=0;
    int lm=0;
    for(int i=0; i<name_user.size();i++)
    {
        lm=(int)tolower(name_user[i]);
        if(lm<97 || lm>122 && lm!=32 && lm<160 || lm>165 )
        {
            conta++;
            flagss=true;
        }
        else flagss=false;
    }

    if(flagss)
    {
        cout<<"Introduzca solo letras"<<endl;
        system("pause");
        system("cls");
    }
    return flagss;
}

bool OnlyNums(float numeros)//validacion de entrada de solo numeros
{
    bool flagss;
    int conta=0;
    int lm;
    string numgene=std::to_string(numeros);
    for(int i=0; i<numgene.size();i++)
    {
        lm=(int)numgene[i];
        if( (lm<48 || lm>57) && lm!=46 )
        {
            conta++;
            cout<<"no es un numero "<<lm<<"  "<<numgene[i] <<endl;
            system("pause");
            flagss=true;
        }
        else flagss=false;
    }
    if(flagss)
    {
        cout<<"Introduzca solo numeros"<<endl;
        system("pause");
        system("cls");
    }
    return flagss;

}



void Registro_User() //funcion para registrar usuario donde pedira sus datos
{
        std:: string name, lesiones, enfermedades, password;
        char condiciontype;
        int  id, edad;
        float peso, altura;
        bool flag=true;
            do{
                cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;
                cout<<"Nombre de Usuario: "<<endl;
                cin.ignore();
                getline(cin, name);
                flag=OnlyLetters(name);
            }while(flag);

            do{
                cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;
                cout<<"Nombre de Usuario: \n"<<name<<endl;
                cout<<"Edad: "<<endl;
                cin>>edad;
                OnlyNums((float)edad);
            }while(flag);




            cout<<"Altura: "<<endl;
            cin>>altura;
            OnlyNums(altura);

            cout<<"Peso: "<<endl;
            cin>>peso;
            OnlyNums(peso);

            cout<<"Usted presenta alguna lesion o un enfermedad cardiovascular? Y/N"<<endl;
            cin>> condiciontype;


            if(tolower(condiciontype)== 'y')

                    {
                        cout<<"Que tipo de enfermedad presenta?"<<endl;
                        cout<<"Respiratoria [1]: \n"<<"Cardiovscular [2]: \n"<<endl;
                        cin.ignore();
                        system("pause");

                    }

}

void Login_user()
{
    string nombre;
    string password;
    bool band=true;
    bool flag=true;
   // int size = user1.;

    do{
            cout<<"-----Nombre de usuario: "<<endl;
            cin.ignore();
            getline(cin, nombre);
            flag=OnlyLetters(name);
        }while(flag);



    for(int i=0; i<users.size();i++)
    {
        if(nombre==users[i].getName()  )
        {
            do
            {
                cout<<"Password"<<endl;
                getline(cin, password);
                if(password!=users[i].getPassword())
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

        if(i==users.size()-1)
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






void leerAarchivo()
{

}

void CrearArchivo()
{



}




//leer archivo para declarar arrayñist y que devuelva el array list de usuarios

int main()
    {

        char login=0;
        bool reps=true;
        //prueba de agregar usuarios
        for(int i=0; i<5;i++){
        User us("David Carmona", i, "ZVesda2125", "si", "sas", 123, 122, 24);

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
                        Login_user();
                    }
                break;

                case 50:
                    {
                        system("cls");
                        Registro_User();
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
