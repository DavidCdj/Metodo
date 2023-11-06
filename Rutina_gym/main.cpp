#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string.h>
#include "User.h"

using namespace std;
vector <User> users;

void saveUsersToFile(std::vector<User> use, const char* filename)
{
    std::ofstream outfile(filename, ios::binary);
    if (outfile.is_open())
    {
        int n = use.size();
        outfile.write((char*)&n, sizeof(int));
        for (int i=0; i<n;i++)
        {
       // error: lvalue required as unary '&' operand|
       //outfile.write((char*)&users, sizeof(User));
            int id= users[i].getID();
            std::string name=users[i].getName();
            std::string password=users[i].getPassword();
            std::string lesiones=users[i].getLesiones();
            std::string enfermedades=users[i].getEnfermedades();
            float altura=users[i].getAltura();
            float peso=users[i].getPeso();
            int edad=users[i].getEdad();
            char sexo=users[i].getSexo();
            outfile.write((char*)&id, sizeof(int));
            outfile.write((char*)&name, sizeof(string));
            outfile.write((char*)&password, sizeof(string));
            outfile.write((char*)&altura, sizeof(float));
            outfile.write((char*)&lesiones, sizeof(std::string));
            outfile.write((char*)&peso, sizeof(float));
            outfile.write((char*)&enfermedades, sizeof(std::string));
            outfile.write((char*)&edad, sizeof(int));
            outfile.write((char*)&sexo, sizeof(char));
        }
        outfile.close();
    }
}

// Lee un vector de objetos User de un archivo binario

void readUsersFromFile(const char* filename)
{
    vector<User> usuarios;
    ifstream infile(filename, std::ios::binary);

        int n;
        infile.read((char*)&n, sizeof(int));
        //usuarios.reserve(n);
        for (int i = 0; i <n; i++)
        {

            int edad,id;
            float altura, peso, imc;
            char sexo;
            std::string name, password, lesiones, enfermedades;
            infile.read((char*)&id, sizeof(int));
            infile.read((char*)&name, sizeof(string));
            infile.read((char*)&password, sizeof(std::string));
            infile.read((char*)&altura, sizeof(float));
            infile.read((char*)&lesiones, sizeof(std::string));
            infile.read((char*)&peso, sizeof(float));
            infile.read((char*)&enfermedades, sizeof(std::string));
            infile.read((char*)&edad, sizeof(int));
            infile.read((char*)&sexo, sizeof(char));
            User user(name, id, password,  altura, lesiones,  peso, enfermedades,   edad, sexo);
            users.push_back(user);
            //system("pause");
        }

    infile.close();
    //return usuarios;
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
    float valor;
    string numeros;
    system("cls");
    do{
        conta=0;
        cout<<tipodato<<" de usuario: "<<endl;
        getline(cin, numeros);
        for(int i=0; i<numeros.size();i++)
        {
            sd=(int)numeros[i];
            cout<<sd<<endl;
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
    valor= std::stof(numeros);

    return valor;
}
void MostrarDatos(User u)
{
            std::cout<<"Tu informacion es la siguiente: "<<std::endl;
            cout<<"Nombre: "<< u.getName() <<endl;
            cout<<"Edad:  "<<u.getEdad() <<endl;
            cout<<"Peso:  "<<u.getPeso()<<endl;
            cout<<"Altura:  "<<u.getAltura()<<endl;
            cout<<"Sexo:  "<<u.getSexo()<<endl;
            cout<<"Enfermedades:  "<<u.getEnfermedades()<<endl;
            cout<<"Lesiones:  "<<u.getLesiones()<<endl;
            cout<<"IMC: "<< (u.getPeso()/(u.getAltura()*u.getAltura()) )<<endl;
}

bool SiNo(string lees)
{
    bool flag, tiene;
    char condiciontype;
        do{
            system("cls");
            cout<<"Usted presenta alguna "<< lees << " ? Y/N"<<endl;
            //cin.ignore();
            cin>> condiciontype;
            cin.ignore();
            if (tolower(condiciontype)!= 'y' && tolower(condiciontype)!='n')
                {
                    cout<<"ingrese una opcion valida:"<<condiciontype<<endl;
                    system("pause");
                    flag=true;
                }
                else{
                        if (tolower(condiciontype)== 'y')
                        tiene=true;
                        else{tiene=false;}
                        flag=false;
                    }
            }while(flag);

     return tiene;
}

bool OpcionesValidas(int opc)
{
    bool rep;
    if(opc<49 || opc>52)
        {
            cout<<"ingrese una opcion valida"<<endl;
            system("pause");
            rep=true;
        }
    else
        rep=false;
    return rep;
}

std::string Enfermedad()
{
    string enfermedades;
    int menenfer;
    char logs;
    bool flags;
    flags= SiNo("enfermedad que le impida ejercitarse adecuadamente");
    if(flags)
    {
        do{
            cout<<"Que tipo de enfermedad presenta?\n"<<"[1] Cardiaca \n[2] Pulmonar \n[3] Artritis \n[4] Cardiovascular "<<endl;
            cin>>logs;
            cin.ignore();
            menenfer=(int)logs;
            system("cls");
        }while(OpcionesValidas(menenfer));

        // se podria hacer una funcion para  que mejor le determine la enfermedad
        switch (logs)
            {
                case 49:
                    enfermedades="Cardiaca";
                break;

                case 50:
                    enfermedades="Pulmonar";

                break;

                case 51:
                    enfermedades="Artritis";
                    break;

                case 52:
                    enfermedades="Cardiovascular";

                break;
            }
    }
    else { enfermedades="NP" ;}

    return enfermedades;
}




std::string Lesion()
{
    string lesiones;
    bool flags;
    flags= SiNo("lesión que le impida ejercitarse adecuadamente");
    if(flags)
    {
        cout<<"presenta lesión"<<endl;
        lesiones="Fractura";

    }
    else {lesiones="NP";}

    return lesiones;
}



void Registro_User() //funcion para registrar usuario donde pedira sus datos
{
        std:: string name,  password,  cpassword,sexo, lesiones, enfermedades;
        char condiciontype, sex;
        int  id,edad;
        float peso, altura;
        bool flag;
        system("pause");
        cout<<"----------Bienvenido----------\n --Ingresa tus  datos correctamente--"<<endl;

        name=OnlyLetters("Nombre");
        edad=OnlyNums("Edad");
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
        enfermedades= Enfermedad();
        lesiones= Lesion();


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
        User us(name, id,password, altura, lesiones, peso, enfermedades,   edad, sex);
        users.push_back(us);
        MostrarDatos(us);
        system("pause");
        system("cls");
        cout<<"Inicie sesion"<<endl;
        system("pause");
        saveUsersToFile(users, "usuariosdata.bin");
}

void Login_user()
{
    string nombre;
    string password;
    bool band=true;
    bool flag=true;

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
        char logs;
        do
            {
                system("cls");
                cout<<"--------Rutina de Gym--------\n\n\r"<<endl;
                cout<<"1.- Usuario existente\n"<< "2.- nuevo usuario\n"<<"3.-salir\n"<<endl;
                cin>>logs;
                cin.ignore();
                lm=(int)logs;
                system("cls");
            }while(OpcionesValidas(lm));
    return logs;
}



int main()
    {
        bool reps=true;

            //readUsersFromFile("usuariosdata.bin");
            //system("pause");


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
                /*saveUsersToFile(users, "usuariosdata.bin");
                int n=users.size();
                 for(int j=0; j<n;j++)
                   {
                       cout<<n;
                      MostrarDatos(users[j]);

                   }
                   MostrarDatos(users[0]);


                    system("pause");*/
                }

                break;
            }
        }
        while(reps);

    }
