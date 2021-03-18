/**** Header exclusivo para controle do terminal ****/

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> // Para pausar o menu

void clear() // Limpa o Terminal
{
    #if defined(_linux) || defined(unix) || defined(APPLE_)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void separaTexto () // Imprime uma serie de - para separar o texto
{
    printf("\n------------------------------------------------------------\n");
}

void printEspacoMeio (int tamTexto, int tamDivisor) //imprime espaços ate que a palavra esteja ao centro
{

    // tamDivisor(separaTexto/* */)=60/104;
    int quantEspacos,i;
    quantEspacos = (tamDivisor-tamTexto)/2;

    for (i=0; i<quantEspacos; i++)
    {
        printf(" ");
    }

}

void printTitulo (char titulo[]) // Formata Titulo ao meio da pagina
{
    separaTexto();
    printEspacoMeio(strlen(titulo),60);
    printf("%s",titulo);
    separaTexto();
}

void retornaMenu() //Pausa o terminar ate que o usuario aperte enter e volte ao menu
{
    separaTexto();
    printf("Aperte ENTER para voltar ao menu.");
    _getch(); // Espera uma input do usuario e pausa o terminal
    clear();
}

void formatar(char str[])
{
    str[strcspn(str, ",.!?")] = 0;

    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

#endif

