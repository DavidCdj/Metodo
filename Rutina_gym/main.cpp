#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include "User.h"

using namespace std;



int main()
    {

        char login=0;
        int lm=0;
        bool rep= true;
        //User n= new n;
        //while por si no  dan una entrada valida
        do
            {
                system("cls");
                cout<<"--------Rutina de Gym--------\n\n\r"<<endl;
                cout<<"1.- Usuario existente\n"<< "2.- nuevo usuario\n"<<"3.-salir\n"<<endl;
                cin>> login;

                lm=(int)login;
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

        switch (login)
            {
                case 49:
                    {
                        system("cls");

                        cout<<"Indtroduce tu nombre o ID"<<endl;

                    }
                break;

                case 50:
                    {
                        system("cls");
                        cout<<"Para registrar un usuario"<<endl;
                    }

                break;

                case 51:
                        exit;
                break;
            }


    }














    /*void leer_archivo()
{
    ifstream fich("usuarios_gym.txt");
  if (!fich.is_open())
  {
    cout << "Error al abrir \n";
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 10; ++i)
    fich << i << endl;
}

void escribir_archivo
{
    ofstream fich("usuarios_gym.txt", ios::app);
    if (!fich)
        {
            cout << "Error al abrir ejemplo.dat\n";
            exit(EXIT_FAILURE);
        }
    fich<<User<<endl;

}

*/
