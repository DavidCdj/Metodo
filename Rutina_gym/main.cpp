#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cctype> //libreria que ocupe para pasar de mayuculas a minusculas se puede usar de ambas formas
#include <cstdlib>
#include <fstream> //para los archivos
#include <vector> //utilice para crear y usar vectores
#include <string.h> //para utlizar strings.
#include "User.h"

using namespace std;
vector <User> users;

void saveUsersToFile(std::vector<User> use, const char* filename)
{
    std::ofstream outfile(filename );
    if (outfile.is_open())
    {

        int n = use.size();
        outfile.write((char*)&n, sizeof(int));
        for (int i=0; i<n;i++)
        {
            int id= users[i].getID();
            std::string name=users[i].getName();
            std::vector<char> bytes(name.begin(), name.end());
            std::string password=users[i].getPassword();
            std::vector<char> byt(password.begin(), password.end());
            char lesiones=users[i].getLesiones();
            char enfermedades=users[i].getEnfermedades();
            float altura=users[i].getAltura();
            float peso=users[i].getPeso();
            int edad=users[i].getEdad();
            char sexo=users[i].getSexo();
            int tamaniovector=bytes.size();
            int tamaniopass=byt.size();
            outfile.write((char*)&id, sizeof(int));
            outfile.write((char*)&tamaniovector, sizeof(int));
            //outfile.write((char*)&name, sizeof(string));
            outfile.write(bytes.data(), bytes.size());
            //outfile.write((char*)&password, sizeof(string));
            outfile.write((char*)&tamaniopass, sizeof(int));
            outfile.write(byt.data(), byt.size());
            outfile.write((char*)&altura, sizeof(float));
            outfile.write((char*)&lesiones, sizeof(char));
            outfile.write((char*)&peso, sizeof(float));
            outfile.write((char*)&enfermedades, sizeof(char));
            outfile.write((char*)&sexo, sizeof(char));
            outfile.write((char*)&edad, sizeof(int));
        }
        outfile.close();
    }
}

// Lee un vector de objetos User de un archivo binario

void readUsersFromFile(const char* filename)
{
    vector<User> usuarios;
    ifstream infile(filename );
        int n;
        infile.read((char*)&n, sizeof(int));
        for (int i = 0; i <n; i++)
        {
            int edad,id, vectortam, tamaniopass;
            float altura, peso, imc;
            char sexo, enfermedades, lesiones;

            infile.read((char*)&id, sizeof(int));
            infile.read((char*)&vectortam, sizeof(int));
            std::vector<char> bytes(vectortam);
            //infile.read((char*)&name, sizeof(string));
            infile.read(bytes.data(), bytes.size());
            infile.read((char*)&tamaniopass, sizeof(int));
            //infile.read((char*)&password, sizeof(std::string));
            std::vector<char> bytpass(tamaniopass);
            infile.read(bytpass.data(), bytpass.size());
            infile.read((char*)&altura, sizeof(float));
            infile.read((char*)&lesiones, sizeof(char));
            infile.read((char*)&peso, sizeof(float));
            infile.read((char*)&enfermedades, sizeof(char));
            infile.read((char*)&sexo, sizeof(char));
            infile.read((char*)&edad, sizeof(int));
            std::string name(bytes.begin(), bytes.end());
            std::string password(bytpass.begin(), bytpass.end());
            User user(name, id, password,  altura, lesiones,  peso, enfermedades,   edad, sexo);
            users.push_back(user);
        }
    infile.close();
}

string OnlyLetters(string tipovalor) //Validacion de entrada de solo letras.
{
    bool flagss;
    int conta, lm=0;
    string name;
    do{     //recorre todo el string, analizando si solo introdujo letras, en caso de que no el ciclo se repetira hasta que lo realice correctamente
            system("cls");
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
    }while(flagss||name.empty());//el ciclo se repetira hasta que  el usuario solo introduja letras, name.empty  se expresa en caso de que no  halla leido nada el string,
    return name;
}


float OnlyNums(string tipodato)//validacion de entrada de solo numeros
{
    bool flagss=true;
    int conta, sd=0;
    float valor;
    string numeros;
    do{
        system("cls");
        conta=0;
        cout<<tipodato<<" de usuario: "<<endl;
        getline(cin, numeros);
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
            flagss=true;
        }
         else flagss=false;
    }while(flagss||numeros.empty());
    valor= std::stof(numeros);
    return valor;
}

string TipoDeEnfermedad(char logs)//funcion  para mandar que tipo de enfermedad presenta el usuario cuando se imprimen los datos, o se quiere saber por separado
{
    string enfer;
    int lm;
    try{
        lm = int(logs);
    }catch(std::exception& e){cout<<"Nose guardo correctamente"<<endl;}
    switch (lm)
            {
                case 48:
                    enfer="NP";
                break;

                case 49:
                    enfer="Cardiaca";
                break;

                case 50:
                    enfer="Pulmonar";

                break;

                case 51:
                    enfer="Artritis";
                    break;

                case 52:
                    enfer="Cardiovascular";
                break;
            }
    return enfer;
}

string TipoDeFractura(char logs)
{
    string frac;
    int lm;
    try{
        lm = int(logs);
    }catch(std::exception& e){cout<<"Nose guardo correctamente"<<endl;}
    switch (lm)
            {
                case 48:
                    frac="NP";
                break;

                case 49:
                    frac="Fractura";
                break;

                case 50:
                    frac="Dislocacion";

                break;

                case 51:
                    frac="Esguince";
                    break;

                case 52:
                    frac="Desgarro";
                    break;

                case 53:
                    frac="Tendinitis";
                break;
            }

    return frac;
}

void MostrarDatos(User u) //cada que se  llama, solo mostrara los datos del usuario
{
            std::cout<<"Tu informacion es la siguiente: "<<std::endl;
            cout<<"Nombre: "<< u.getName() <<endl;
            cout<<"Edad:  "<<u.getEdad() <<endl;
            cout<<"Peso:  "<<u.getPeso()<<endl;
            cout<<"Altura:  "<<u.getAltura()<<endl;
            cout<<"Sexo:  "<<u.getSexo()<<endl;
            cout<<"Enfermedades:  "<<TipoDeEnfermedad(u.getEnfermedades())<<endl;
            cout<<"Lesiones:  "<<TipoDeFractura(u.getLesiones())<<endl;
            cout<<"IMC: "<< (u.getPeso()/(u.getAltura()*u.getAltura()) )<<endl;
            cout<<"IMC: "<< (u.getPassword() )<<endl;
}

bool SiNo(string lees) //funcion para la eleccion  de si o no, ejemplo si desea realizar algun cambio
{
    bool flag, tiene;
    char condiciontype;
        do{
            system("cls");
            cout<< lees << " ? Y/N"<<endl;
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

bool OpcionesValidas(string opc, int ascci)
{
    bool rep;
    int sd,conta=0,lm;
    try{
            lm=std::stoi(opc);
    }catch(std::invalid_argument& e){conta=1;}
    if(opc.size()==1)
    {
         for(int i=0; i<opc.size();i++)
        {
            sd=(int)opc[i];
            if(sd<49 || sd>ascci)
            conta++;
        }
        if (conta>0)
        {
            cout<<"ingrese una opcion valida"<<endl;
            system("pause");
            system("cls");
            rep=true;
        }
        else  rep=false;

    }
    else
        {
            cout<<"ingrese una opcion valida"<<endl;
            system("pause");
            system("cls");
            rep=true;
        }

    return rep;
}


char MenusDeOpciones(string opciones, int asci)
{
    char opcion;
    string vl;
    do{
            cout<<opciones<<endl;
            cin>>opcion;
            cin.ignore();
            vl=opcion;
        }while(OpcionesValidas(vl, asci));
    return opcion;
}

char Enfermedad()
{
    string enfermedades;
    int menenfer;
    char logs;
    bool flags;
    flags= SiNo("Usted presenta alguna enfermedad que le impida ejercitarse adecuadamente");
    if(flags)
        logs=MenusDeOpciones("Que tipo de enfermedad presenta?\n [1] Cardiaca \n[2] Pulmonar \n[3] Artritis \n[4] Cardiovascular ", 52);

    else { logs='0' ;}
    return logs;
}

char Lesion()
{
    string lesiones;
    bool flags;
    char logs;
    flags= SiNo("Usted presenta alguna lesión que le impida ejercitarse adecuadamente");
    if(flags)
        logs=MenusDeOpciones("Que tipo de lesion presenta? \n[1] Fractura \n[2] Dislocacion \n[3] Esguience \n[4] Desgarre \n[5] Tendinitis ",53);
    else {logs='0';}
    return logs;
}

string Pass()
{
    string password,cpassword;
    bool flag;

        do{
                system("cls");
                cout<<"Introduce tu contraseña: "<<endl;
                getline(cin, password);
                if(!password.empty())
                {
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
                }
                else flag=true;

        }while(flag);

    return password;
}

void Cambios(int id)
{
    bool flag,validar;
    char cambiar,enfermedad, lesion;
    string name, cpassword;
    float peso, altura;
    int edad;
    flag=SiNo("Desea Realizar algun cambio ");

        if(flag)
        {
            cambiar=MenusDeOpciones("Que paranetro quieres cambar?\n[1] Nombre \n[2] Peso \n[3] Edad \n[4] Enfermedad \n[5] Lesion \n[6] Altura \n[7] Password ", 55 );
            switch(cambiar)
            {
                case 49:
                    name=OnlyLetters("Nombre");
                    users[id].setName(name);
                    break;

                case 50:
                    peso=OnlyNums("Peso");
                    users[id].setPeso(peso);
                    break;

                case 51:
                    edad=OnlyNums("Edad");
                    users[id].setEdad(edad);
                break;

                case 52:
                    enfermedad=Enfermedad();
                    users[id].setEnfermedades(enfermedad);
                    break;

                case 53:
                    lesion=Lesion();
                    users[id].setLesiones(lesion);
                    break;

                case 54:
                    altura=OnlyNums("Altura");
                    users[id].setAltura(altura);
                    break;

                case 55:
                    cpassword=Pass();
                    users[id].setPassword(cpassword);
                    break;
            }

            saveUsersToFile(users, "usuariosdata.txt");
            system("pause");
        }
        MostrarDatos(users[id]);

}

void RutinaGuardar(char lesioon, char enfermedd)
{


}

void RutinaMostrar()
{

}


void Registro_User() //funcion para registrar usuario donde pedira sus datos
{
        std:: string name,  password,  cpassword,sexo;
        char condiciontype, sex, enfermedades, lesiones;
        int  id,edad;
        float peso, altura;
        bool flag;
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
        system("cls");
        cpassword=Pass();
        system("cls");
        id=users.size();
        User us(name, id,cpassword, altura, lesiones, peso, enfermedades, edad, sex);
        users.push_back(us);
        MostrarDatos(us);
        system("pause");
        Cambios(id);
        system("cls");
        cout<<"Inicie sesion"<<endl;
        system("pause");
        saveUsersToFile(users, "usuariosdata.txt");
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
        string lmf;
        char logs;
        do
        {
            system("cls");
            cout<<"--------Rutina de Gym--------\n\n\r"<<endl;
            cout<<"1.- Usuario existente\n"<< "2.- nuevo usuario\n"<<"3.-salir\n"<<endl;
            getline(cin, lmf);
        }while(OpcionesValidas(lmf, 52));
            lm=std::stoi(lmf);
    return lm;
}

int main()
    {
        bool reps=true;
            readUsersFromFile("usuariosdata.txt");
    do{
         switch (Menu_Inicio())
            {
                case 1:
                    {
                        system("cls");
                        Login_user();
                    }
                break;

                case 2:
                    {
                        system("cls");
                        Registro_User();
                    }

                break;

                case 3:
                    {
                        reps=false;

                    }
                    break;

                case 4:
                {
                    for(int i=0;i<users.size();i++)
                    {
                        MostrarDatos(users[i]);
                        Cambios(i);
                        system("pause");
                    }
                }

                break;
            }
        }
        while(reps);

    }
