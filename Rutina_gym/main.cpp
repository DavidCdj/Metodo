#include <iostream>
#include <stdio.h>
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
void saveUsersToFile(std::vector<User>& use, const char* filename)
{

    std::ofstream outfile(filename, ios::binary);
    if (outfile.is_open())
    {
        int n = use.size();
        //outfile.write((char*)&n, sizeof(int));
        for (User& user : use)
        {
       // error: lvalue required as unary '&' operand|
            int id= user.getID();
            std::string name=user.getName();
            std::string password=user.getPassword();
            std::string lesiones=user.getLesiones();
            std::string enfermedades=user.getEnfermedades();
            float altura=user.getAltura();
            float peso=user.getPeso();
            int edad=user.getEdad();
            std::string sexo=user.getSexo();

            outfile.write((char*)&id, sizeof(int));
            outfile.write((char*)&name, sizeof(std::string));
            outfile.write((char*)&password, sizeof(std::string));
            outfile.write((char*)&lesiones, sizeof(std::string));
            outfile.write((char*)&enfermedades, sizeof(std::string));
            outfile.write((char*)&altura, sizeof(float));
            outfile.write((char*)&peso, sizeof(float));
            outfile.write((char*)&edad, sizeof(int));
            outfile.write((char*)&sexo, sizeof(std::string));
        }
        outfile.close();
    }
}

// Lee un vector de objetos User de un archivo binario

std::vector<User> readUsersFromFile(const char* filename)
{
    std::vector<User> users;
    std::ifstream infile(filename, ios::binary);
    if (infile.is_open())
    {
        int n;
        //infile.read((char*)&n, sizeof(int));
        for (int i = 0; i < 4; i++)
        {

            int edad,id;
            //std::string id;

            float altura, peso, imc;
            std::string name, password, lesiones, enfermedades,sexo;
            infile.read((char*)&id, sizeof(int));
            //infile.getline(id, sizeof(std::string));
            infile.read((char*)&name, sizeof(std::string));
            infile.read((char*)&password, sizeof(std::string));
            infile.read((char*)&lesiones, sizeof(std::string));
            infile.read((char*)&enfermedades, sizeof(std::string));
            infile.read((char*)&altura, sizeof(float));
            infile.read((char*)&peso, sizeof(float));
            infile.read((char*)&edad, sizeof(int));
            infile.read((char*)&sexo, sizeof(std::string));
            cout<< name<<id<<password<<lesiones<<enfermedades<<altura<<peso<<edad<<sexo<<endl;


            User user(name, id, password, lesiones, enfermedades, altura, peso, edad, sexo);
            cout<<"error"<<endl;


            users.push_back(user);
            cout<<"error"<<endl;
            cout<<i<<"\n"<<endl;
        }
        infile.close();
    }
}
void MostrarDatos(User u)
{
            std::cout<<"Tu informacion es la siguiente: "<<std::endl;
            std::cout<<"Nombre:  "<< u.getName() <<std::endl;
            std::cout<<"Edad:  "<<u.getEdad() <<std::endl;
            std::cout<<"Peso:  "<<u.getPeso()<<std::endl;
            std::cout<<"Altura:  "<<u.getAltura()<<std::endl;
            std::cout<<"Sexo:  "<<u.getSexo()<<std::endl;
            std::cout<<"Lesiones:  "<<u.getLesiones()<<std::endl;
            std::cout<<"Enfermedades:  "<<u.getEnfermedades()<<std::endl;
            std::cout<<"IMC: "<< (u.getPeso()/(u.getAltura()*u.getAltura()) )<<std::endl;
}



string OnlyLetters(string tipovalor) //recorre el string  que busca si introdujo solo letras, en casi de que si devuelve false.
{
    bool flagss;
    int conta;
    int lm=0;
    string name;
    system("cls");
    do{
            conta=0;

            cout<<tipovalor<<" de usuario: "<<endl;
            getline(cin, name);
            for(int i=0; i<name.size();i++)
            {
                lm=(int)name[i];
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

    }while(flagss);

            return name;
}


float OnlyNums(string tipodato)//validacion de entrada de solo numeros
{
    bool flagss=true;
    int conta=0;
    int sd=0;
    string numeros;
    system("cls");
   // float valor
    do{
            conta=0;
        cout<<tipodato<<" de usuario: "<<endl;
        getline(cin,numeros);
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
    }while(flagss);
    cin.clear();
    return stoi(numeros);
}



void Registro_User() //funcion para registrar usuario donde pedira sus datos
{
        std:: string name, lesiones, enfermedades, password,  cpassword,sexo;
        char condiciontype, sex;
        int  id,edad;
        float peso, altura;
        bool flag;
        system("pause");
        cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;

        name=OnlyLetters("Nombre");
        edad=(int)OnlyNums("Edad");
        peso=OnlyNums("Peso");
        altura=OnlyNums("Altura");
        do{
                cout<<"Ingresa tu sexo: \n [H]Hombre \n [M]Mujer "<<endl;
                cin>>sex;
                cin.ignore();
                if( tolower(sex)!='h' && tolower(sex)!='m')
                {
                    cout<<"Ingrese un sexo valido"<<endl;
                    system("pause");
                    flag=true;
                }
                else flag=false;
        }while(flag);

            do{
                    system("cls");
                    cout<<"Usted presenta alguna lesion o un enfermedad cardiovascular? Y/N"<<endl;
                    //cin.ignore();
                    cin>> condiciontype;
                    cin.ignore();
                    if (tolower(condiciontype)!= 'y' && tolower(condiciontype)!='n')
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
            id=users.size();
            User us(name, id,password, lesiones, enfermedades, altura, peso, edad, sexo);
            users.push_back(us);
            MostrarDatos(us);
            system("pause");
            system("cls");
            cout<<"Inicie sesion"<<endl;
            system("cls");


}

void Login_user()
{
    string nombre;
    string password;
    bool band=true;
    bool flag=true;
   // int size = user1.;

    nombre=OnlyLetters("Nombre");

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
                cin>>logs;
                cin.ignore();
                lm=(int)logs;
                // se utiliza valores de 49 al 51 porque son valores de 1 al 3 en ascii, para que el usuario no introduzca letras o  simbolos especiales
                if (lm<49 || lm>52)
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

int main()
    {
        bool reps=true;
        for(int i=0; i<5;i++)
            {
                User us("David Carmona ", i, " ZVesda2125", "si", "sas", 1, 2, 60, "h");
                users.push_back(us);

            }


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

                case 52:
                {
                    saveUsersToFile(users, "usuariosdata.bin");
                    readUsersFromFile("usuariosdata.bin");
                    //MostrarDatos(users[0]);
                }

                break;
            }
        }
        while(reps);

    }
