/**** Header exclusivo para imprimir o menu ****/

#ifndef MENU
#define MENU

#include "formating.h"

void menu() // Imprime o menu
{
    // Titulo da Pagina
    printTitulo("Menu");

    // Opcoes do menu
    printf(".1 - Ler Arquivo Dicionario\n");
    printf(".2 - Ler Texto de Referencia A (TRA)\n");
    printf(".3 - Ler Texto de Referencia B (TRB)\n");
    printf(".4 - Exibir BOWs de TRA e TRB \n");
    printf(".5 - Mostrar Similaridade entre TRA e TRB\n");
    printf(".0 - Sair");

    separaTexto();
}

#endif
