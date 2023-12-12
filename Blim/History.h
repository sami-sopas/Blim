#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

class Historial
{
public:
    int indxContent = 0;
    int indhistorialContent = 0;
    char userID[15];
    char tipo[50];
    char content[50][10];
    char delimitador = '\n';

    void setList(char _userID[15]);
    void setContent(char _id[15], char _content[10], char tipo);
    void capturar();
    void mostrar();
    void getHistorial(char _id[15]);
    void buscar();
    void Modificar();
    void Eliminar();
    int hAdmin();
    void hUser(char _id[15], bool _ad);
} historial;

void Historial::setList(char _userID[15])
{
    strcpy(userID, _userID);
}

void Historial::setContent(char _id[15], char _content[10], char _tipo)
{
    bool band = false;
    ifstream datos("History.bin");
    ofstream c("temp.bin", ios::binary);
    if (!datos.good())
    {
        cout << "No ehistorialiste el archivo";
    }
    else
    {
        while (!datos.eof())
        {
            datos.read((char *)&historial, sizeof(historial));
            if (datos.eof())
            {
                break;
            }
            if (strcmp(historial.userID, _id) == 0 && !band)
            {
                band = true;
                cout << "HISTORIAL" << historial.userID << endl;
                if (indxContent == 50)
                {
                    cout << "NO SE PUEDEN INGRESAR MAS ID's" << endl;
                }
                else
                {
                    strcpy(content[indxContent], _content);
                    tipo[indxContent] = _tipo;
                    indxContent++;
                }
                c.write((char *)&historial, sizeof(historial));
            }
            else
            {
                c.write((char *)&historial, sizeof(historial));
            }
        }
        if (band == false)
        {
            datos.close();
            c.close();
            remove("History.bin");
            rename("temp.bin", "History.bin");
            //cout << "Debug entro al if por no haber registro previo" << endl;
            historial.setList(_id);
            indxContent = 0;
            //cout << historial.userID << endl;
            ofstream b("History.bin", ios::binary | ios::app);
            b.write((char *)&historial, sizeof(historial));
            b.close();
            //historial.mostrar();
            historial.setContent(_id, _content, _tipo);
            return;
        }
    }
    c.close();
    datos.close();
    remove("History.bin");
    rename("temp.bin", "History.bin");
    return;
}

void Historial::capturar()
{
    ofstream b("History.bin", ios::binary | ios::app);
    indxContent = 0;
    char _userID[15];

    cout << "    AGREGAR HISTORIAL" << endl;
    cout << "------------------------------------" << endl;
    cout << "Id del usuario:" << endl;
    cin.getline(_userID, 14);
    setList(_userID);
    cout << "------------------------------------" << endl;
    b.write((char *)&historial, sizeof(historial));
    b.close();
    cout << "*********************************" << endl;
    cout << "       GUARDANDO CAMBIOS.....    " << endl
         << " POR FAVOR NO CIERRE EL PROGRAMA " << endl;
    cout << "*********************************" << endl;
}

void Historial::mostrar()
{
    ifstream a("History.bin");
    if (!a.good())
        cout << "No existe el archivo" << endl;
    else
    {
        cout << "HISTORIALES EXISTENTES" << endl
             << "----------------------------------" << endl;
        while (!a.eof())
        {
            a.read((char *)&historial, sizeof(historial));
            if (a.eof())
                break;
            cout << "ID:" << historial.userID << endl;
            cout << "N : Tipo / ID" << endl;
            for (int i = 0; i < indxContent; i++)
            {
                cout << "#" << i + 1 << ": " << historial.tipo[i] << " / " << historial.content[i] << endl;
            }
            cout << "------------------------------------" << endl;
        }
    }
    a.close();
}

void Historial::getHistorial(char _id[15])
{
    int band = 0;
    ifstream a("History.bin");
    if (!a.good())
    {
        cout << "No existe el archivo" << endl;
    }
    else
    {
        while (!a.eof())
        {
            a.read((char *)&historial, sizeof(historial));
            if (a.eof())
            {
                break;
            }
            if (strcmp(historial.userID, _id) == 0)
            {
                cout << "  HISTORIAL DEL ID #"<< historial.userID << endl
                     << "------------------------------------" << endl;
                cout << "N : Tipo / ID" << endl;
                for (int i = 0; i < indxContent; i++)
                {
                    cout << "#" << i + 1 << ": " << historial.tipo[i] << " / " << historial.content[i] << endl;
                }
                cout << "------------------------------------" << endl;
                band = 1;
                break;
            }
        }
        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO....." << endl;
        }
    }
    a.close();
}

void Historial::buscar()
{
    char userIDbus[14];
    int band = 0;
    ifstream a("History.bin");
    if (!a.good())
    {
        cout << "NO EXISTE EL ARCHIVO" << endl;
    }
    else
    {
        cout << "\tBUSCAR" << endl
             << "----------------------------------" << endl;
        cout << "\nID DE HISTORIAL (*ES EL MISMO DEL USUARIO*)" << endl;
        cin.getline(userIDbus, 14);
        while (!a.eof())
        {
            a.read((char *)&historial, sizeof(historial));
            if (a.eof())
            {
                break;
            }
            if (strcmp(historial.userID, userIDbus) == 0)
            {
                cout << "  HISTORIAL DEL ID #" << historial.userID << " ENCONTRADO" << endl
                     << "------------------------------------" << endl;
                cout << "N : Tipo / ID" << endl;
                for (int i = 0; i < indxContent; i++)
                {
                    cout << "#" << i + 1 << ": " << historial.content[i] << endl;
                }
                cout << "------------------------------------" << endl;
                band = 1;
                break;
            }
        }
        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO....." << endl;
        }
    }
    a.close();
}

void Historial::Modificar()
{
    char userIDmod[15];
    int band = 0;
    int opc;
    ifstream datos("History.bin");
    ofstream c("temp.bin", ios::binary);
    if (!datos.good())
    {
        cout << "NO EXISTE EL ARCHIVO";
    }
    else
    {
        cout << "             MODIFICAR" << endl
             << "----------------------------------" << endl;
        cout << "\nID DE HISTORIAL A MODIFICAR" << endl;
        cin.getline(userIDmod, 14);
        while (!datos.eof())
        {
            datos.read((char *)&historial, sizeof(historial));
            if (datos.eof())
            {
                break;
            }
            if (strcmp(historial.userID, userIDmod) == 0 && band == 0)
            {
                cout << " HISTORIAL ENCONTRADO" << endl
                     << "------------------------------------" << endl;
                cout << "ID:" << historial.userID << endl;
                for (int i = 0; i < indxContent; i++)
                {
                    cout << "#" << i + 1 << ": " << historial.content[i] << endl;
                }
                cout << "DESEAS MODIFICARLO?\n"
                     << "1.-SI   2.-NO" << endl
                     << "DIGITE LA OPCION->";
                cin >> opc;
                cout << "------------------------------------" << endl;
                cin.ignore();
                band = 1;
                if (opc == 1)
                {
                    int mod;
                    do
                    {
                        cout << "------------------------------------" << endl;
                        cout << "QUE DESEAS HACER :" << endl
                             << "1.- INSERTAR   2.- MODIFICAR 3.- ELIMINAR 4.-SALIR" << endl
                             << "Digite la opcion-> ";
                        cin >> mod;
                        cout << "------------------------------------" << endl;
                        cin.ignore();
                        switch (mod)
                        {
                        case 1:
                        {
                            char temp[10];
                            if (indxContent == 50)
                            {
                                cout << "NO SE PUEDEN INGRESAR MAS ID's" << endl;
                            }
                            else
                            {
                                cout << "CUAL ES EL NUEVO ID: ";
                                cin.getline(temp, 10);
                                strcpy(content[indxContent], temp);
                                indxContent++;
                            }
                        }
                        break;
                        case 2:
                        {
                            if (!indxContent)
                            {
                                cout << "NO HAY DATOS" << endl;
                            }
                            else
                            {
                                int line;
                                char temp[10];
                                for (int i = 0; i < indxContent; i++)
                                {
                                    cout << "POS[" << i << "] = " << historial.content[i] << endl;
                                }
                                cout << "------------------------------------" << endl;
                                cout << "QUE POSICION DESEA MODIFICAR: ";
                                cin >> line;
                                cin.ignore();
                                cout << "ID NUEVA: ";
                                cin.getline(temp, 10);
                                strcpy(content[line], temp);
                            }
                        }
                        break;
                        case 3:
                        {
                            if (!indxContent)
                            {
                                cout << "NO HAY DATOS" << endl;
                            }
                            else
                            {
                                int line;
                                for (int i = 0; i < indxContent; i++)
                                {
                                    cout << "POS[" << i << "] = " << historial.content[i] << endl;
                                }
                                cout << "------------------------------------" << endl;
                                cout << "QUE POSICION DESEA ELIMINAR: ";
                                cin >> line;
                                cin.ignore();
                                if (indxContent < 10)
                                {
                                    for (int i = line; i < indxContent; i++)
                                    {
                                        strcpy(content[i], content[i + 1]);
                                    }
                                }
                                indxContent--;
                            }
                        }
                        break;
                        }
                    } while (mod != 4);
                }
            }
            c.write((char *)&historial, sizeof(historial));
        } // while archivo
        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO....." << endl;
        }
    } // else
    c.close();
    datos.close();
    cout << "*********************************" << endl;
    cout << "       GUARDANDO CAMBIOS.....    " << endl
         << " POR FAVOR NO CIERRE EL PROGRAMA " << endl;
    cout << "*********************************" << endl;
    remove("History.bin");
    rename("temp.bin", "History.bin");
}

void Historial::Eliminar()
{
    char userIDeli[15];
    bool band = false;
    //long int tempPos;
    ifstream a("History.bin");
    ofstream temp("TempHistory.bin", ios::binary);

    if (!a.good())
    {
        cout << "No existe el archivo" << endl;
    }
    else
    {
        cout << "             ELIMINAR             " << endl
             << "----------------------------------" << endl;
        cout << " ID de Lista de Reproduccion a eliminar!" << endl;
        cin.getline(userIDeli, 14);
        while (!a.eof())
        {
            int opc = 0;
            a.read((char *)&historial, sizeof(historial));
            if (a.eof())
            {
                break;
            }
            if (strcmp(historial.userID, userIDeli) == 0)
            {
                if (a.eof())
                    break;
                cout << "  Lista de Reproduccion a Eliminar  " << endl
                     << "------------------------------------" << endl;
                cout << "ID:" << historial.userID << endl;
                for (int i = 0; i < indxContent; i++)
                {
                    cout << "#" << i + 1 << ": " << historial.content[i] << endl;
                }
                cout << "Deseas eliminarla" << endl
                     << "1.-Si   2.-No" << endl
                     << "Digite la opcion-> ";
                cin >> opc;
                band = true;

            } // if de comparacion
            if (opc == 1)
            {
                //   cont--;
            }
            else
            {
                temp.write((char *)&historial, sizeof(historial));
            }
        } // while

        if (!band)
        {
            cout << "\n NO EXISTE REGISTRO....." << endl;
        }
    } // else
    a.close();
    temp.close();
    remove("History.bin");
    rename("TempHistory.bin", "History.bin");
    cout << "*********************************" << endl;
    cout << "       GUARDANDO CAMBIOS.....    " << endl
         << " POR FAVOR NO CIERRE EL PROGRAMA " << endl;
    cout << "*********************************" << endl;
}

int Historial::hAdmin()
{
    int opc;
    do
    {
        system("cls");
        cout << "   MENU DEL HISTORIAL    " << endl
             << "------------------------------------" << endl;
        cout << "Selecciona una de la siguientes opciones:" << endl
             << "1.- Agregar" << endl
             << "2.- Buscar" << endl
             << "3.- Mostrar todas listas" << endl
             << "4.- Modificar" << endl
             << "5.- Eliminar" << endl
             << "6.- Salir" << endl
             << "Digite la opcion-> ";
        cin >> opc;
        cin.ignore();
        cout << "------------------------------------" << endl;
        switch (opc)
        {
        case 1:
            historial.capturar();
            break;
        case 2:
            historial.buscar();
            break;
        case 3:
            return 3;
            break;
        case 4:
            historial.Modificar();
            break;
        case 5:
            historial.Eliminar();
            break;
        }
       // _sleep(600);
        system("Pause");
    } while (opc != 6);
    return 0;
}

void Historial::hUser(char _id[15], bool _ad)
{
    getHistorial(_id);
    system("Pause");
}
