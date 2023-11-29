#include <iostream>
#include <stdio.h>
#include <stdlib.h> //Sirve para convertir un entero a cadena de caracteres.
#include <cctype> //Convierte a mayúsculas  un carácter o un intervalo de caracteres
#include <cstdlib>// Sirve para ejecutar subprocesos o comandos del sistema operativo
#include <fstream> //para los archivos
#include <vector> //sirve  para crear y usar vectores
#include <string.h> //para utlizar strings.
#include <ctime> //fecha y hora de dia.
#include "User.h"

using namespace std;
vector <User> users; //Es un vector que contiene  objetos de tipo  User
vector<string> dia_semana;
//vector <string> ejercicios={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}; vector que dice que dia es, solo se ocuapara en caso de que lo vemaos necesario

//Funcion para guardar los usuarios resgistrados en un archivo. tiene 36 lienas de codigo,
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
            outfile.write(bytes.data(), bytes.size());
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

// Funcion que lee un archivo que contiene los usuarios, y los almacena en un vector, ese vector almacena objetos de tipo User, con sus respectivos parametros.
//contiene  30 lineas de codigo
void readUsersFromFile(const char* filename)
{
    vector<User> usuarios;
    ifstream infile(filename );
        int n;
        if(infile.fail())
                cout<<"Error al encontrar ek archivo"<<endl;
        else
        {
            try{
                infile.read((char*)&n, sizeof(int));
                for (int i = 0; i <n; i++)
                    {
                    int edad,id, vectortam, tamaniopass;
                    float altura, peso, imc;
                    char sexo, enfermedades, lesiones;
                    infile.read((char*)&id, sizeof(int));
                    infile.read((char*)&vectortam, sizeof(int));
                    std::vector<char> bytes(vectortam);
                    infile.read(bytes.data(), bytes.size());
                    infile.read((char*)&tamaniopass, sizeof(int));
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
            }catch(std::bad_alloc& e){}
        }

}


//Funcion que recibe como parametros un string, que fue ingresado previamente por el usuario, el cual va a validar  como entrada unicamente letras
// en caso de que no sean letras le indicara al usuario que introduzca solo letras, y estara en un bucle hasta que lo haga correctamente.
// 26 lineas de codigo
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


//Esta funcion es similar a la anterior solo que  este caso solo validara numeros
// 38 lineas de codigo
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

//Solo muestra en pantalla los datos del usuario, recibe como parametro un objeto User
//12 lineas de codigo
void MostrarDatos(User u)
{
    vector <string>enfert={"NP","Cardiaca","Pulmonar","Artritis","Cardiovascular"};;
    vector <string> lesszone = {"NP","Hombro","Piernas","Espalda","Pies"};
    string l,e;
    int x,y;
            e=u.getEnfermedades();
            y=stoi(e);
            l=u.getLesiones();
            x=stoi(l);
            std::cout<<"Tu informacion es la siguiente: "<<std::endl;
            cout<<"Nombre: "<< u.getName() <<endl;
            cout<<"Edad:  "<<u.getEdad() <<endl;
            cout<<"Peso:  "<<u.getPeso()<<endl;
            cout<<"Altura:  "<<u.getAltura()<<endl;
            cout<<"Sexo:  "<<u.getSexo()<<endl;
            cout<<"Enfermedades:  "<<enfert[y]<<endl;
            cout<<"Lesiones:  "<<lesszone[x]<<endl;
            cout<<"IMC: "<< (u.getPeso()/(u.getAltura()*u.getAltura()) )<<endl;
}


//Funcion para Determinar   la eleccion de si o no, marcada por el usuario, recibe como parametro un string previamente leido, y devuelve un  dato de tipo bool, para seguir operando
//23 lineas de codigo
bool SiNo(string lees)
{
    bool flag, tiene;
    char condiciontype;
        do{
            //system("cls");
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

//Funcion que recibe un string leido, y un numero que define las opciones correctas que presenta un menu, devuelve un valor tipo booleano, dependiendo  si ingreso una opcion valida o no
//este se determina con valores  de la tabla ascci.
//33 lineas de codigo
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

// muestra en pantalla, un menu de opciones previamente pasado por un string, y el numerod e opciones validas, determina mediante la funcion anterior si  tiene una opcionvalida o no
//en caso de que no, seguira en el do while, hasta que marque una opcion valida.
//11 lineas de codigo
char MenusDeOpciones(string opciones, int asci)
{
    char opcion;
    string vl;
    do{
            system("cls");
            cout<<opciones<<endl;
            cin>>opcion;
            cin.ignore();
            vl=opcion;
        }while(OpcionesValidas(vl, asci));
    return opcion;
}

//Funcion que determina si el usuario tiene una enfermedad, llama dos funciones, la primera que valida si tiene o no una enfermedad,
//la segunda funcion que llama, determina que tipo de enfermedad tiene.
//12 lineas de ocdigo
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

//Es una funcion muy similar a la anterior, pero en este caso determina  si tiene o no tiene lesion, y que  tipo de  lesion tiene.
//10 lineas de codigo
char Lesion()
{
    string lesiones;
    bool flags;
    char logs;
    flags= SiNo("Usted presenta alguna lesión que le impida ejercitarse adecuadamente");
    if(flags)
        logs=MenusDeOpciones("En que area presenta la lesion? \n[1] Hombro \n[2] Piernas \n[3] Brazos \n[4] Espalda \n[5] Pies ",53);
    else {logs='0';}
    return logs;
}

//esta funcion devuelve un string, que determina y lee del usuario la contrasenia que  quiere poner el usuario, y  compara para que este seguro de poner esa contrasenia
//28 lineas de codigo
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

//Esta funcion, le pide al usuario si desea hacer cambios a los datos que puso, previamente, se ejecuta cada vez que se registra el usuario
//si se llego a equivocar,  y cuando inicia sesion, por si quiere cambiar algun parametro
//53 lineas de codigo
void Cambios(int id)
{
    bool flag,validar;
    char cambiar,enfermedad, lesion;
    string name, cpassword;
    float peso, altura;
    int edad;
    MostrarDatos(users[id]);
    system("pause");
    while(SiNo("Desea Realizar algun cambio? "))
        {
            cambiar=MenusDeOpciones("Que parametro quieres cambar?\n[1] Nombre \n[2] Peso \n[3] Edad \n[4] Enfermedad \n[5] Lesion \n[6] Altura \n[7] Password ", 55 );
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
                    if(altura>2)altura=altura/100;
                    users[id].setAltura(altura);
                    break;

                case 55:
                    cpassword=Pass();
                    users[id].setPassword(cpassword);
                    break;
            }
            MostrarDatos(users[id]);
            saveUsersToFile(users, "usuariosdata.txt");
            system("pause");
        }
}

//Dependiendo que dia de la semana devolvera false o true, que servira para ver si es dia de descanso o de entrenamiento;
bool DiaSem(int day)
{
    bool flag;
    if(day==0 || day==2 ||day==4 || day==6)
    flag=false;
    else flag=true;
    return flag;
}

//identifica si tiene alguna enfermedad
bool TieneEnfermedad(int id )
{
    bool enfer;
    if((int) users[id].getEnfermedades()==48)
        enfer=true;

    else enfer=false;

    return enfer;
}

//Identifica  si tiene una lession o no.
bool TieneLesion(int id)
{
    bool enfer;
    if((int) users[id].getLesiones()==48)
        enfer=false;

    else enfer=true;

    return enfer;
}

//imprime en pantalla los ejercicios de  estiramiento
void Estiramiento()
{
    system("cls");
    cout<<"------------Estiramiento-----------"<<endl;
    cout<<"1. Cada ejercicio de  estiramiento debe de durar  8 segundos"<<endl;
    cout<<"2. Mueve la cabeza arriba y abajo "<<endl;
    cout<<"3. Mueve la cabez a los lados"<<endl;
    cout<<"4. Alterna abriendo  y cerrando los brazos"<<endl;
    cout<<"5. Manten los brazos estirados y gira las muniecas a un lado y luego al otro"<<endl;
    cout<<"6. Gira la cadera en circulos"<<endl;
    cout<<"7. Separa un poco  las piernas y toca tus rodillas  con mano contraria\n (Si puedes hazlo a la punta de tus pies )"<<endl;
    system("pause");
}

//imprime en pantalla ejercicio de calentamiento
void Calentamiento(int id)
{
    if(TieneEnfermedad(id))
    {
        system("cls");
        cout<<"-----Calentamiento-----"<<endl;
        cout<<"\nNota: Los ejercicios de calentamiento, son sugerencias \n no realices todas solo uno por dia."<<endl;
        cout<<"Entre 10 y 15 minutos, depende de como te sientas."<<endl;
        cout<<"1. Trotar en la caminadora"<<endl;
        cout<<"2. Escaladora,"<<endl;
        cout<<"3. Eliptica"<<endl;
        cout<<"4. Bicicleta"<<endl;
        cout<<"5. Saltar la cuerda"<<endl;
        system("pause");

    }
    else{
          system("cls");
        cout<<"----------Calentamiento----------"<<endl;
        cout<<"\nNota: Los ejercicios de calentamiento, son sugerencias \n no realices todas solo uno por dia."<<endl;
        cout<<"Solo realiza 10 minutos  de un ejercicio, con una leve intensidad,\n recuerda ir a tu ritmo y escuchar tu cuerpo\n"<<endl;
        cout<<"1. Caminar  sea en caminadora o al aire libre"<<endl;
        cout<<"2. Eliptica"<<endl;
        cout<<"3. Bicicleta"<<endl;

        system("cls");


    }
}
void rutinapesolibre(vector<string> pesolibre, int xd, int cre){

    int i=0,a=0;
    system("cls");
    cout<<"----------Entrenamiento----------"<<endl;
    while(i<6)
    {
        int ran =a + rand() % 5;
        a=a+cre;
        if(a<31)
        {
            if(ran!=(0+xd) ||ran!=(1+xd) || ran!=(2+xd) || ran!=(3+xd) || ran!=(4+xd) || ran!=(5+xd))
            {

                cout<<i+1<<") "<<pesolibre[ran]<<endl;;
                i++;
            }
        }
            else a=0;
    }
    system("pause");
}

void rutinMachine(vector<string> pesolibre, vector<string> machine, int xd, int cre, int cd, int cree)
{
    int  a=6, b=0,i=0;
    system("cls");
    cout<<"----------Entrenamiento----------"<<endl;
    while(i<6)
    {
        int ran =a + rand() % 5;
        int rand2= b+ rand()% 3;

        a=a+cre;
        b=b+cree;
        if(a<31 || b<20)
        {
            if(ran!=(0+xd) || ran!=(1+xd) || ran!=(2+xd) || ran!=(3+xd) || ran!=(4+xd) || ran!=(5+xd) || rand2!=(0+cd) ||rand2!=(1+cd) || rand2!=(2+cd) || rand2!=(3+cd))
            {
                if((i+1)%2==0)
                {
                    cout<<(i+1)<<") "<<pesolibre[ran]<<endl;

                    a=a+6;
                }
                else{
                    cout<<(i+1)<<") "<<machine[rand2]<<endl;

                    b=b+8;
                }
                i++;
            }
        }
        else {a=6; b=0;}
    }
    system("pause");
}


//Funcion que arma la rutina para el usuario, como parametro el indice donde se encunetra el usuario
void Gym_day(int id)
{
    //indica que dia de la semana nos encontradmos
    vector <string> machine ={
        //pierna 0 a 3
        "Press de pierna",
        "Extensión de cuádriceps",
        "Flexión de isquiotibiales",
        "Curl femoral",
        //hombros 4 a 7
        "Press de hombros",
        "Elevaciones laterales",
        "Elevaciones frontales",
        "Elevaciones frontales con polea",
        //espalda 8 a 11
        "Remo con polea alta",
        "Jalón al pecho",
        "Jalón al pecho con agarre estrecho",
        "Dominada asistida",
        //pecho  12 a 15
        "Pectoral en maquina ",
        "Press pectoral en maquina",
        "Aperturas con cable" ,
        "Press de pecho con cable",
        // brazo 16 a 19
        "Máquina de curl de bíceps con cable en alta",
        "Curl de bíceps con cable",
        "Extensión de tríceps con barra",
        "Máquina de extensión de tríceps con cable"
    };

    vector <string> pesolibre={
        //Pierna 0 a 5
        "Sentadillas",
        "Zancadas",
        "Peso muerto",
        "Sentadillas Bulgaras",
        "Peso muerto sumo",
        "Elevaciones de gemelos",
        //Hombro 6 a 11
        "Elevaciones frontales con mancuernas",
        "Elevaciones laterales con barra",
        "Press de hombros con mancuernas",
        "Press de hombros con barra",
        "Elevaciones laterales con mancuernas",
        "Press de hombros con mancuernas sentado",
        //Espalda 12 a 17
        "Remo con barra",
        "Remo con mancuernas",
        "Jalon al pecho",
        "Pullover con mancuerna",
        "Dominadas",
        "thruster",
        //pecho 18 a  23
        "Press de pecho con mancuernas",
        "Press de pecho banco inclinado con mancuerna",
        "Press de pecho banco inclinado con barra",
        "Press de pecho con barra",
        "Push up",
        "Aperturas con mancuernas",
        //brazo 24 a30
        "Curl de bíceps con mancuernas",
        "Curl de bíceps con barra",
        "Curl concentrado de bíceps",
        "Curl de biceps con barra Z",
        "Extensión de tríceps con mancuernas",
        "Extensión de tríceps con barra"};


    int day, a=6,b=0,i=0;
    char pref;
    bool flag;
    time_t now=time(0);
    tm * time=localtime(&now);
    day=time-> tm_wday;
    //day=3;
    //int a = rand() % 10;
    if(DiaSem(day)){
            system("cls");

        if(SiNo("Prefieres trabajar con peso libre? "))
        {
            Estiramiento();
            Calentamiento(id);

            if(TieneLesion(id))
            {

                switch(users[id].getLesiones())
                {
                case 49:
                        rutinapesolibre(pesolibre, 0, 6);
                    break;
                case 50:
                        rutinapesolibre(pesolibre, 6, 6);
                    break;
                    case 51:
                        rutinapesolibre(pesolibre, 12 , 6);
                    break;
                case 52:
                     rutinapesolibre(pesolibre, 18 , 6);
                    break;
                case 53:
                        rutinapesolibre(pesolibre, 24, 6);
                    break;
                }
            }
            else rutinapesolibre( pesolibre,0,6);
        }

        else{
            Estiramiento();
            Calentamiento(id);
            if(TieneLesion(id))
            {

                switch(users[id].getLesiones())
                {
                case 49:
                        rutinMachine(machine,pesolibre, 0, 6, 0,4);
                    break;
                case 50:
                        rutinMachine(machine,pesolibre, 6, 6, 4, 4);
                    break;
                    case 51:
                        rutinMachine(machine,pesolibre, 12, 6, 8,4);
                    break;
                case 52:
                        rutinMachine(machine,pesolibre, 18, 6, 12, 4);
                    break;
                case 53:
                        rutinMachine(machine,pesolibre, 24, 6, 16,4);
                    break;
                }
            }
            else rutinMachine(machine,pesolibre, 0, 6, 0, 4);
        }

    }
    else{
        system("cls");
        cout<<"\n \n         Recuerda que los dias de descanso tambien son importantes\n para que tu cuerpo se recupere,  y evitemos posibles lesiones  o se intensifiquen"<<endl;
        system("pause");
    }
}


//Registro de un usuario, donde pedira sus daros
//40 lineas de codigo
void Registro_User()
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
        if(altura>2)altura=altura/100;
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

//Funcion para que realice su loggin el usuario.
// 31 lineas de codigo
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
            system("cls");
            Cambios(i);
            system("pause");
            Gym_day(i);
            break;
        }
        if(i==users.size()-1)
        {
            cout<<"Usuario no encontrado"<<endl;
            system("pause");
        }
    }
}


//Muestra el menu de inicio
//14 lineas de codigo
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

//Funcion main del codigo, empieza a leer un archivo. da 3 opciones para el usuario, y una cuarta para hacer testeos del codgio, solo para el programador.
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

                    Gym_day(0);
                    //MostrarDatos(users[0]);
                    system("pause");

                }
                break;
            }
        }
        while(reps);
        return 0;
    }
