#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
class Movie
{
public:
    char codigo[10], nombre[100], descripcion[200], time[15], publicObj[15];
    char delim = '\n';
    void Capturar();
    bool checkID(char *);
    void Imprimir();
    void Buscar();
    void Eliminar();
    void Modificar();
    string getMovie(char _id[10]);
    void setters(char *, char *, char *, char *, char *);
    void adminMovies();
}movies;

void Movie::setters(char *_codigo, char *_nombre, char *_descripcion, char *_time, char *_publicObj)
{
    strcpy(this->codigo, _codigo);
    strcpy(this->nombre, _nombre);
    strcpy(this->descripcion, _descripcion);
    strcpy(this->time, _time);
    strcpy(this->publicObj, _publicObj);
}
void Movie::Capturar()
{
    bool verified = false;
    char _codigo[10], _nombre[100], _descripcion[200], _time[15], _publicObj[15];
    do
    {
        cout << "\nCodigo: ";
        cin.getline(_codigo, 10);
        verified = checkID(_codigo);
        if(verified)
            cout << "Se encontraron coincidencias por favor intente con otro codigo"<< endl;
    } while (verified);
    cout << "\nNombre: ";
    cin.getline(_nombre, 100);
    cout << "\nDescripcion: ";
    cin.getline(_descripcion, 200);
    cout << "\nTime: ";
    cin.getline(_time, 15);
    cout << "\nClasificacion: ";
    cin.getline(_publicObj, 15);
    setters(_codigo, _nombre, _descripcion, _time, _publicObj);
    ofstream archivo("Movies.txt", ios::app);
    archivo.write((char *)&movies, sizeof(movies));
    archivo.close();
}
bool Movie::checkID(char *_codigo)
{
    bool band = false;
    string buffer1;
    string buffer2;
    buffer1 = _codigo;
    ifstream arc("Movies.txt");
    if (!arc.good()){
    }else
    {
        while (!arc.eof())
        {
            arc.read((char *)&movies, sizeof(movies));
            buffer2 = codigo;
            if (arc.eof())
                break;
            if (buffer1 == buffer2)
                band = true;
        }
    }
    arc.close();
    return band;
}
void Movie::Imprimir()
{
    //int i;
    ifstream Lectura("Movies.txt");
    if (!Lectura.good())
    {
        cout << "No existe el archivo\n";
    }
    else
    {
        cout << "PELICULAS EXISTENTES" << endl;
        while (!Lectura.eof())
        {
            Lectura.read((char *)&movies, sizeof(movies));
            if (Lectura.eof())
                break;
            cout << endl
                 << "Codigo: " << codigo << endl
                 << "Nombre: " << nombre << endl
                 << "Descripcion: " << descripcion << endl
                 << "Duracion: " << time << endl
                 << "Clasificacion: " << publicObj << endl;
        }
    }
    Lectura.close();
}
void Movie::Buscar()
{
    char ref[10];// prev[10];
    int band = 1;
    cout << "\nEscribe el codigo de la Pelicula a buscar \n";
    cin.getline(ref, 10);
    ifstream arc("Movies.txt");
    if (!arc.good())
        cout << "\nEl archivo no existe";
    else
    {
        while (!arc.eof() && band == 1)
        {
            arc.read((char *)&movies, sizeof(movies));
            if (arc.eof())
                break;
            if (strcmp(codigo, ref) == 0)
            {
                cout << "\nCodigo: " << codigo;
                cout << "\nNombre: " << nombre;
                cout << "\nDescripcion: " << descripcion;
                cout << "\nDuracion: " << time;
                cout << "\nClasificaion: " << publicObj << endl;
                band = 0;
            }
        }
        if (band)
            cout << "\nNo se encontro el Movie";
    }
    arc.close();
}

string Movie::getMovie(char _id[10]){
    string movie;
    bool band = false;
    ifstream arc("Movies.txt");
    if (!arc.good())
        cout << "\nEl archivo no existe";
    else
    {
        while (!arc.eof() && !band)
        {
            arc.read((char *)&movies, sizeof(movies));
            if (arc.eof())
                break;
            if (strcmp(codigo, _id) == 0)
            {
                movie = nombre;
                band = true;
            }
        }
    }
    arc.close();
    return movie;
}

void Movie::Eliminar()
{
    //int i;
    //int opcion;
    char prodMod[10];
    bool b;
    int resp;
    ifstream arc("Movies.txt");
    ofstream arcTemp("TempMovies.txt", ios::app);
    if (!arc.good())
        cout << "\n EL REGISTRO NO EXISTE \n ";
    else
    {
        cout << "\n Introduce el codigo a Eliminar  :  " << endl;
        cin.getline(prodMod, 10);
        b = false;
        while (!arc.eof())
        {
            arc.read((char *)&movies, sizeof(movies));
            if (arc.eof())
                break;
            if (strcmp(codigo, prodMod) == 0 && !b)
            {
                cout << "Se encontro una coincidencia" << endl;
                cout << "\nCodigo: " << codigo;
                cout << "\nNombre: " << nombre;
                cout << "\nDescripcion: " << descripcion;
                cout << "\nDuracion: " << time;
                cout << "\nClasificaion: " << publicObj << endl;
                cout << "Quiere eliminarlo?" << endl;
                cout << "(1) SI   (2) NO" << endl
                     << "-> ";
                cin >> resp;
                cin.ignore();
                if (resp == 2)
                {
                    arcTemp.write((char *)&movies, sizeof(movies));
                }
                else
                {
                    cout << "Se ha eliminado correctamente" << endl;
                    b = true;
                }
            }
            else
            {
                arcTemp.write((char *)&movies, sizeof(movies));
            }
        }
        arc.close();
        arcTemp.close();
        if (!b)
            cout << "\n No se encontro arhcivo ";
        remove("Movies.txt");
        rename("TempMovies.txt", "Movies.txt");
    }
}
void Movie::Modificar()
{
    //int i;
    int opcion;
    char prodMod[10];
    bool b;
    ifstream arc("Movies.txt");
    ofstream arcTemp("TempMovies.txt", ios::app);
    if (!arc.good())
        cout << "\n EL REGISTRO NO EXISTE \n ";
    else
    {
        cout << "\n Introduce el codigo a modificar :  ";
        cin.getline(prodMod, 10);
        b = false;
        while (!arc.eof())
        {
            arc.read((char *)&movies, sizeof(movies));
            if (arc.eof())
                break;
            if (strcmp(codigo, prodMod) == 0 && !b)
            {
                do
                {
                    cout << endl
                         << "Codigo : " << codigo << endl
                         << "Nombre : " << nombre << endl
                         << "Descripcion : " << descripcion << endl
                         << "Duracion : " << time << endl
                         << "Clasificacion : " << publicObj << endl
                         << "   Que desea realizar ? " << endl
                         << "(1) Modificar Nombre: " << endl
                         << "(2) Modificar Descripcion: " << endl
                         << "(3) Modificar Duracion: " << endl
                         << "(4) Modificar Clasificacion: " << endl
                         << "(5) Regresar: " << endl
                         << "Elige la opcion a realizar: ";
                    cin >> opcion;
                    cin.ignore();
                    switch (opcion)
                    {
                    case 1: //////Nombre
                        cout << "\n Nombre : ";
                        cin.getline(nombre, 100);
                        break;
                    case 2: /// Descripcion
                        cout << "\n Descripcion : ";
                        cin.getline(descripcion, 200);
                        break;
                    case 3: /// Duracion
                        cout << "\n Duracion : ";
                        cin.getline(time, 15);
                        break;
                    case 4: /// Clasificacion
                        cout << "\n Clasificacion : ";
                        cin.getline(publicObj, 15);
                        break;
                    case 5:
                        b = true;
                        break;
                    default:
                        cout << "\n No se encontro la opcion ";
                    }
                    if (opcion != 5)
                        b = true;
                } while (opcion != 5);
            }
            arcTemp.write((char *)&movies, sizeof(movies));
        }
        arc.close();
        arcTemp.close();
        if (!b)
            cout << "\n No se encontro arhcivo ";
        remove("Movies.txt");
        rename("TempMovies.txt", "Movies.txt");
    }
}
void Movie::adminMovies()
{
    int op;
    do
    {
        cout << "\nIngresa el numero de la opcion: \n1.Capturar \n2.Imprimir todo \n3.Buscar \n4.Eliminar \n5.Modificar \n6.Salir\n";
        cin >> op;
        cin.ignore();
        switch (op)
        {
        case 1:
            movies.Capturar();
            system("pause");
            system("cls");
            break;
        case 2:
            movies.Imprimir();
            system("pause");
            system("cls");
            break;
        case 3:
            movies.Buscar();
            system("pause");
            system("cls");
            break;
        case 4:
            movies.Eliminar();
            system("pause");
            system("cls");
            break;
        case 5:
            movies.Modificar();
            system("pause");
            system("cls");
        }
    } while (op != 6);
    return;
}
