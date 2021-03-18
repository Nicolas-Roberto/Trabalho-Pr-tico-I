#ifndef BOWTRA_H_INCLUDED
#define BOWTRA_H_INCLUDED

#include <ctype.h>
#include <string.h>
#include "formating.h"

/*
exemplo de arquivo bow:

    (Arquivo de referencia)
        Esse e um teste como esse.

    (Arquivo dicionario)
        esse
        teste
        como
        nada

    (Arquivo bow)
        2 esse
        1 teste
        1 como
        0 nada
*/

typedef struct
{
    char letra;
    int inicio;
    int fim;
} Indice;

/*

*/
void preencherPosicoes(Indice indices[], int *tamanhoArrayIndice, char dict[][100], int tamanhoDict)
{
    char primeiraLetraAtual = dict[0][0];

    Indice indiceAtual;

    indiceAtual.letra = primeiraLetraAtual;
    indiceAtual.inicio = 0;

    for(int i = 1; i < tamanhoDict; i++)
    {
        primeiraLetraAtual = dict[i][0];

        if(primeiraLetraAtual != indiceAtual.letra)
        {
            indiceAtual.fim = i - 1;
            indices[*tamanhoArrayIndice] = indiceAtual;
            *tamanhoArrayIndice = (*tamanhoArrayIndice) + 1;

            indiceAtual.letra = primeiraLetraAtual;
            indiceAtual.inicio = i;
        }
        else if(i == tamanhoDict - 1)
        {
            indiceAtual.fim = i;
            indices[*tamanhoArrayIndice] = indiceAtual;
            *tamanhoArrayIndice = (*tamanhoArrayIndice) + 1;
        }
    }
}

/*

*/
Indice resgatarIndiceAtual(char primeiraLetra, Indice indices[], int tamanhoIndices)
{
    Indice indiceAtual = {' ',-1,-1};

    for(int i = 0; i < tamanhoIndices; i++)
    {
        indiceAtual = indices[i];
        if(indiceAtual.letra == primeiraLetra)
        {
            break;
        }
    }

    return indiceAtual;
}

/*

*/
void gerarBow_Cont(FILE* bow, int cont[], FILE* referencia, char dict[][100], int tamanho)
{
    char palavraLida[100];

    Indice indices[100];
    Indice indiceAtual;
    int tamanhoArrayIndices = 0;

    preencherPosicoes(indices,&tamanhoArrayIndices,dict, tamanho);

    while(fscanf(referencia, "%s", palavraLida) != EOF)
    {
        fgetc(referencia);

        formatar(palavraLida);

        indiceAtual = resgatarIndiceAtual(palavraLida[0], indices, tamanhoArrayIndices);

        if(indiceAtual.inicio != -1)
        {
            for(int i = indiceAtual.inicio; i <= indiceAtual.fim; i++)
            {
                if(strcmp(palavraLida, dict[i]) == 0)
                {
                    cont[i]++;
                }
            }
        }
    }

    for(int i = 0; i < tamanho; i++)
    {
        fprintf(bow,"%d %s\n", cont[i], dict[i]);
    }
}

/*

*/
void printaBOWs(int *ContA, int *ContB, char dict[][100], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(ContA[i] + ContB[i] != 0)
        {
            printf("\nPalavra: %s\n", dict[i]);
            printf("bowA\tbowB\n");
            printf("%d\t%d\n", ContA[i], ContB[i]);
        }
    }
}
#endif // BOWTRA_H_INCLUDED

