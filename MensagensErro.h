#ifndef MENSAGENSERRO
#define MENSAGENSERRO

#include <stdio.h>
#include <stdbool.h>
#include "formating.h"

void erroOpcaoValida(int input,int menor,int maior) // "Erro: Selecione uma opcao valida !"
{
    if (input<menor || input>maior)
    {
        separaTexto();
        printf("Erro: Selecione uma opcao valida!"); 
        separaTexto();
    }
}

bool erroArquivoInvalido(FILE *arquivo) // "Erro: Digite um Arquivo Invalido !"
{// Retorna true se o arquivo digitado for invalido
    if(arquivo==NULL)
    {
        separaTexto();
        printf("Erro: Arquivo Invalido !"); 
        separaTexto();

        return true;
    }
    else
    {
        return false;
    }
}

#endif