#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string.h>
#include "User.h"
#define FILE_NAME "Usuarios.dat" //archivo en forma binaria

using namespace std;
vector <User> users;

void GuardarArchivoBin(User uss)
{
   // User u;

    ofstream archivo("User_dat.dat", ios::binary);
    /*str
    strcpy(uss.getName(), uss.getName());
    strcpy(uss.getID(), uss.getID());
    strcpy(uss.getPassword, uss.getPassword());
    strcpy(uss.lesiones, uss.getLesiones());
    strcpy(uss.enfermedades, uss.getEnfermedades());
    strcpy(uss.altura, uss.getAltura());
    strcpy(uss.peso, uss.getPeso());
    strcpy(uss.edad, uss.getEdad());
    strcpy(uss.imc, uss.getImc());*/

    //strcpy();
    archivo.write((char*)&uss, sizeof(User));


}

bool OnlyLetters(string name_user) //recorre el string  que busca si introdujo solo letras, en casi de que si devuelve false.
{
    bool flagss;
    int conta=0;
    int lm=0;
    for(int i=0; i<name_user.size();i++)
    {
        lm=(int)name_user[i];
        if(((lm<65||lm>90) && (lm<97 || lm>122) ) && lm!=32 && (lm<160 || lm>165) )
            conta++;
    }

    if(conta>0)
    {
        cout<<"Introduzca solo letras"<<endl;
        system("pause");
        system("cls");
        flagss=true;
    }
    else flagss=false;
    return flagss;
}


bool OnlyNums(string numeros)//validacion de entrada de solo numeros
{
    bool flagss=true;
    int conta=0;
    int sd=0;
    for(int i=0; i<numeros.size();i++)
    {
        sd=(int)numeros[i];
        if( (sd<48 || sd>57) && sd!=46 )
                conta++;
    }
    if (conta>0)
    {
        cout<<"Introduzca solo numeros"<<endl;
        system("pause");
        system("cls");
        flagss=true;
    }
     else flagss=false;
    cin.clear();
    return flagss;
}
/*
void Imprimir_usuario()
{
    for(int i=0; i<users.size();i++)
    {
        cout<<users[i].getName()<<users[i].getID()<<users[i].getAltura()<<users[i].getEdad()<<users[i].getEnfermedades()<<users[i].getID()<<users[i].getImc()<<users[i].getLesiones()<<users[i].getPeso()<<endl;

    }


}*/



void Registro_User() //funcion para registrar usuario donde pedira sus datos
{
        std:: string name, lesiones, enfermedades, password, peso, altura, edad, cpassword;
        char condiciontype;
        int  id;
        float imc;
        bool flag;
            do{
                cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;
                cout<<"Nombre de Usuario: "<<endl;
                getline(cin, name);
            }while(OnlyLetters(name));

            do{
                system("cls");
                cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;
                cout<<"Nombre de Usuario: \n"<<name<<endl;
                cout<<"Edad: "<<endl;
                cin>>edad;
            }while(OnlyNums(edad));

            do{
                system("cls");
                cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;
                cout<<"Nombre de Usuario: \n"<<name<<endl;
                cout<<"Edad: \n"<<edad<<endl;
                cout<<"Altura: "<<endl;
                cin>>altura;
            }while(OnlyNums(altura));


            do{
                system("cls");
                cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;
                cout<<"Nombre de Usuario: \n"<<name<<endl;
                cout<<"Edad: \n"<<edad<<endl;
                cout<<"Altura: \n"<<altura<<endl;
                cout<<"Peso: "<<endl;
                cin>>peso;
            }while(OnlyNums(peso));

            do{
                    cout<<"Usted presenta alguna lesion o un enfermedad cardiovascular? Y/N"<<endl;
                    //cin.ignore();
                    cin>> condiciontype;
                    cin.ignore();
                    tolower(condiciontype);

                    if (condiciontype!= 'y' && condiciontype!='n')
                    {
                        cout<<"ingrese una opcion valida:"<<condiciontype<<endl;
                        system("pause");
                        flag=true;
                    }
                    else
                    flag=false;

            }while(flag);

            if(tolower(condiciontype)== 'y')
                    {
                        cout<<"Que tipo de enfermedad presenta?"<<endl;
                        cout<<"Respiratoria [1]: \n"<<"Cardiovscular [2]: \n"<<endl;
                        //cin.ignore(); falta agregar enfermedades





                        system("pause");
                    }
                else{
                    lesiones="NP";
                    enfermedades="NP";
                }
                //cin.ignore();
                system("cls");
                cout<<"Contraseña: "<<endl;
                getline(cin, password);
                do{
                        cout<<"Confirma tu contraseña: "<<endl;
                        getline(cin, cpassword);
                        if(password!=cpassword)
                        {
                            cout<<"Las contraseña no coinciden:"<<endl;
                            cout<<"Vuleve a intentarlo"<<endl;
                            system("pause");
                            system("cls");
                            flag=true;
                        }
                        else flag=false;
                }while(flag);

            system("cls");
            imc=(std::stof(peso))/(std::stof(altura));
            cout<<"Tu informacion es la siguiente: "<<endl;
            cout<<"Nombre:  "<<name<<endl;
            cout<<"Edad:  "<<edad<<endl;
            cout<<"Peso:  "<<peso<<endl;
            cout<<"Altura:  "<<altura<<endl;
            cout<<"Lesiones:  "<<lesiones<<endl;
            cout<<"Enfermedades:  "<<enfermedades<<endl;
            cout<<"IMC: "<< imc<<endl;

            system("pause");
            system("cls");
            cout<<"Inicie sesion"<<endl;
            system("cls");
            id=users.size();
            User us(name, id,password, lesiones, enfermedades, stoi(altura), stoi(peso), stoi(edad), imc);
            users.push_back(us);
            //Imprimir_usuario();
            //system("pause");
            GuardarArchivoBin(us);

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
            getline(cin, nombre);
            flag=OnlyLetters(nombre);
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

char Menu_Inicio()
{
        int lm=0;
        bool rep= true;
        char logs;
        do
            {
                system("cls");

                cout<<"--------Rutina de Gym--------\n\n\r"<<endl;
                cout<<"1.- Usuario existente\n"<< "2.- nuevo usuario\n"<<"3.-salir\n"<<endl;
                //cin.clear();
                cin>>logs;
                cin.ignore();
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
    User userarch=User();
    ifstream archivo("User_dat.dat", ios::binary);

    archivo.read((char*)&userarch, sizeof(User));

    cout<<"Nombre "<< userarch.getName()<<endl;
    cout<<"edad "<< userarch.getEdad()<<endl;




    system("pause");
    archivo.close();
}

int main()
    {

        //char login=0;
        bool reps=true;
        //prueba de agregar usuarios
        /*for(int i=0; i<5;i++)
            {
                User us("David Carmona", i, "ZVesda2125", "si", "sas", 123, 122, 24, 23);
                users.push_back(us);
                GuardarArchivoBin(us);
            }*/
            leerAarchivo();
            //cout<<users[2].getName()<<endl;
            //cout<<users[1].getName();
            system("pause");



    do{
         switch (Menu_Inicio())
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
