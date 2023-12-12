#include <iostream>
#include "User.h"
#include "Animations.h"


using namespace std;

void displayMenu(); //Menu principal
void Recovery(); //Para recuperar todos los registros


int main(){
    system("Title Blim");
    displayMenu();
    return 0;
}

void displayMenu()
{
    int opc,opc2;
    string pass;

    Recovery();
    inicio(); //Pantalla de carga al compilar

    do{
        menu();
        cout << "Seleccione una opcion: "; cin >> opc;

        switch(opc)
        {
            case 1:
                cout << "\n \t \t \t \t \tIngrese la contrasenia: "; cin.ignore(); getline(cin,pass);

                if(checkAdminPassword(pass) == true)
                {
                    cin.clear();
                    typeLog = true;
                    OrdCom.menuAdmin();
                }
                else
                {
                    cout << "\t\tContrasenia invalida, intente de nuevo" << endl;
                    system("pause");
                }

                break;

            case 2:
                system("cls");
                cout << "  MENU DE USUARIOS" << endl;
                cout << "--------------------" << endl;
                cout << "Que desea realizar" << endl
                     << "1)Iniciar sesion" << endl
                     << "2)Registrarse" << endl
                     << "3)Salir" << endl
                     << "Seleccione una opcion -> "; cin >>opc2;

                if(opc2==1)
                {
                    OrdCom.LogIn();
                }else
                {
                    OrdCom.Agregar();
                    cout << "\n\n USUARIO AGREGADO CON EXITO !" << endl;
                    system("pause");
                }


                break;

        }

    }while(opc!=3);


}

void Recovery(){
    Pago recovery;
    listR.Recovery();
    recovery.genera();
    system("cls");
}
