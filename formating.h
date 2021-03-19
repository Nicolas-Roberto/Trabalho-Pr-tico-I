/**** Header exclusivo para controle do terminal ****/

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void printCaracter(int tamanho, int ondeParar, char carat) // Printa um caracter ate  
{
    int quantidade = ondeParar-tamanho;
    int i;
    if (quantidade>0)
    {    
        for (i=1; i<=quantidade;i++)
        {
            printf("%c",carat);
        }
    }
}

void printTitulo (char titulo[]) // Formata Titulo ao meio da pagina
{
    separaTexto();
    printEspacoMeio(strlen(titulo),60);
    printf("%s",titulo);
    separaTexto();
}

void printNumCentralizado (int n, int espaco) // Formata Titulo ao meio da pagina
{
    char num[10];
    int pular;
    int tamanhoStr;

    sprintf(num, "%d", n); // Iguala a string "Num" ao numero inteiro
    
    tamanhoStr = strlen(num);
    
    if(tamanhoStr%2 != 0)
    {
        espaco++;
    }

    pular = espaco - tamanhoStr;

    if(pular>0) // Evita erros na funcao printEspacoMeio
    {    
        printEspacoMeio(tamanhoStr,espaco);
        printf("%s",num);
        if(tamanhoStr%2 != 0)
        {
            espaco--;
        }
        printEspacoMeio(tamanhoStr,espaco);
    }
    else
    {
        printf("%s",num);
    }
}

void retornaMenu() //Pausa o terminal ate que o usuario aperte enter e volte ao menu
{
    separaTexto();
    printf("Aperte ENTER para voltar ao menu.");
    
    // Espera uma input do usuario e pausa o terminal
    getchar();
    getchar();
    clear();
}

void formatar(char str[]) // Retira pontuacao e deixa tudo minusculo
{
    str[strcspn(str, ",.!?;:")] = 0;

    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

#endif
