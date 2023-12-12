#ifndef ANIMATIONS_H_INCLUDED
#define ANIMATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"windows.h"
#include <iostream>
#include"Date.h"

Date fecha;

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

void crearMarco(){
     gotoxy(92,1); cout << fecha.getDay() <<  "/" << fecha.getMonth() << "/" << fecha.getYear();
     gotoxy(3,1); cout << fecha.getHour() << ":" << fecha.getMinute();

    for(int i = 1; i < 119; i++){
        gotoxy(i,0); printf("%c",205); ///Barra superior
    }

    for(int i = 1; i < 119; i++){
        gotoxy(i,28); printf("%c",205); ///Barra inferior
    }

    for(int i = 1; i < 29; i++){
        gotoxy(1,i); printf("%c",186); ///Barra izquierda
    }

    for(int i = 1; i < 29; i++){
        gotoxy(118,i); printf("%c",186); ///Barra derecha
    }

    gotoxy(1,0); printf("%c",201); ///Esquina superior izquierda
    gotoxy(1,28); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(118,0); printf("%c",187); ///Esquina superior derecha
    gotoxy(118,28); printf("%c",188); ///Esquina inferior derecha

    gotoxy(0,0);
}

void inicio()
{
    crearMarco();
cout << "\n\n\n\n";
cout <<"\t\t     .----------------.  .----------------.  .----------------.  .----------------." << endl
<<"\t\t    | .--------------. || .--------------. || .--------------. || .--------------. |" << endl
<<"\t\t    | |   ______     | || |   _____      | || |     _____    | || | ____    ____ | |" << endl
<<"\t\t    | |  |_   _ \\    | || |  |_   _|     | || |    |_   _|   | || ||_   \\  /   _|| |" << endl
<<"\t\t    | |    | |_) |   | || |    | |       | || |      | |     | || |  |   \\/   |  | |"<< endl
<<"\t\t    | |    |  __'.   | || |    | |   _   | || |      | |     | || |  | |\\  /| |  | |"<< endl
<<"\t\t    | |   _| |__) |  | || |   _| |__/ |  | || |     _| |_    | || | _| |_\\/_| |_ | |"<< endl
<<"\t\t    | |  |_______/   | || |  |________|  | || |    |_____|   | || ||_____||_____|| |"<< endl
<<"\t\t    | |              | || |              | || |              | || |              | |"<< endl
<<"\t\t    | '--------------' || '--------------' || '--------------' || '--------------' |"<< endl
<<"\t\t    '----------------'  '----------------'  '----------------'  '----------------' '"<< endl;

cout << "\n\n\t\t\t\t\t\t\tCARGANDO... " << endl
     << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t      Programmed by Sam and Yazman" << endl;
///BARRA DE CARGA
    for (int i = 30; i < 90; i+=2){
            Sleep(55);
       gotoxy(i,20); printf("%c",254);
    }
}

void menu()
{
    system("cls");
    crearMarco();


    gotoxy(50,3); cout << " BIENVENIDO A BLIM";
    gotoxy(48,4); cout << "-----------------------";

    gotoxy(20,5); cout << "ADMINISTRADOR";
    gotoxy(91,5); cout << "USUARIO";

    gotoxy(21,22); cout << "OPCION 1";
    gotoxy(91,22); cout << "OPCION 2";

   /* gotoxy(50,7); cout << "SELECCIONA TU PEFIL" << endl;
    gotoxy(48,8); cout << "----------------------" << endl;*/

    ///MARCO IZQUIERDO
    for (int i = 80; i < 110; i++){
        gotoxy(i,6); printf("%c",205); //arriba
    }

    for (int i = 80; i < 110; i++){
        gotoxy(i,20); printf("%c",205); //abajo
    }

    for (int i = 7; i < 20; i++){
        gotoxy(79,i); printf("%c",186); //derecha
    }

    for (int i = 7; i < 20; i++){
        gotoxy(109,i); printf("%c",186); //izquierda
    }

    gotoxy(79,6); printf("%c",201); ///Esquina superior izquierda
    gotoxy(79,20); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(109,6); printf("%c",187); ///Esquina superior derecha
    gotoxy(109,20); printf("%c",188); ///Esquina inferior derecha


    ///MARCO DERECHO
    for (int i = 10; i < 40; i++){
        gotoxy(i,6); printf("%c",205); //arriba
    }

    for (int i = 10; i < 40; i++){
        gotoxy(i,20); printf("%c",205); //abajo
    }

    for (int i = 7; i < 20; i++){
        gotoxy(10,i); printf("%c",186); //derecha
    }

    for (int i = 7; i < 20; i++){
        gotoxy(40,i); printf("%c",186); //izquierda
    }

    gotoxy(10,6); printf("%c",201); ///Esquina superior izquierda
    gotoxy(10,20); printf("%c",200); ///Esquina inferior izquierda
    gotoxy(40,6); printf("%c",187); ///Esquina superior derecha
    gotoxy(40,20); printf("%c",188); ///Esquina inferior derecha

/*
gotoxy(18,9); cout << " ___________";
gotoxy(18,10);cout << "|  .----.  o|";
gotoxy(18,11);cout<<"| |      | o| ";
gotoxy(18,12);cout<<"| |      | o| ";
gotoxy(18,13);cout<<"|__`----`___| ";*/

gotoxy(12,9); cout << "     _______________";
gotoxy(12,10);cout<<"    |,----------. | \\ ";
gotoxy(12,11);cout<<"    ||           |=| |" ;
gotoxy(12,12);cout<<"    ||          || | |";
gotoxy(12,13);cout<<"    ||       . _o| | | __";
gotoxy(12,14);cout<<"    |`-----------' |/ /~/";
gotoxy(12,15);cout<<"     ~~~~~~~~~~~~~~~ / /";
gotoxy(12,16);cout<<"                     ~~";

gotoxy(91,11);cout << "  ^~^  ,";
gotoxy(91,12);cout << " ('Y') )";
gotoxy(91,13);cout << " /   \\/ ";
gotoxy(91,14);cout << "(\\|||/)" ;

gotoxy(48,24);
}





#endif // ANIMATIONS_H_INCLUDED
