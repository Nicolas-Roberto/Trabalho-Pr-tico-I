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


void preencherPosicoes(Indice indices[], int *tamanhoArrayIndice, char dict[][100], int tamanhoDict)
    /*
    Percorre todo o dicionario e salva a posicao de inicio e fim de cada letra
    Complexidade - O(n), n = numero de elementos no dict.
    */
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


Indice resgatarIndiceAtual(char primeiraLetra, Indice indices[], int tamanhoIndices)
    /*
    Verifica se tem, no dicionario, alguma palavra que comeca com a letra da palavra que esta
    sendo analisada e pega a posicao de inicio e fim em que essas letras aparecem

    Complexidade - O(n), n = número de indices.
    Melhor caso - O(1)
    Pior caso - O(n)
    */
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


void gerarBow_Cont(FILE* bow, int cont[], FILE* referencia, char dict[][100], int tamanho)
    /*
    Complexidade - O(n + a), n = numero de palavras no dicionario, a = numero de palavras no arquivo de referencia
    */
{
    char palavraLida[100];

    Indice indices[100];
    Indice indiceAtual;
    int tamanhoArrayIndices = 0;

    preencherPosicoes(indices,&tamanhoArrayIndices,dict, tamanho); // O(n), n = palavras no dicionario

    while(fscanf(referencia, "%s", palavraLida) != EOF) // O(a), a = palavras no arquivo de referencia
    {
        fgetc(referencia);

        formatar(palavraLida);

        indiceAtual = resgatarIndiceAtual(palavraLida[0], indices, tamanhoArrayIndices); // O(b), b = numero de indices, b <= n

        if(indiceAtual.inicio != -1)
        {
            for(int i = indiceAtual.inicio; i <= indiceAtual.fim; i++) // O(c), c = numero de elementos no indice, c <= n
            {
                if(strcmp(palavraLida, dict[i]) == 0)
                {
                    cont[i]++;
                }
            }
        }
    }

    for(int i = 0; i < tamanho; i++) // O(n)
    {
        fprintf(bow,"%d %s\n", cont[i], dict[i]);
    }

    // Complexidade total = O(n + a(b + c) + n) = O(n + a)
}

void printaBOWs(int *ContA, int *ContB, char dict[][100], int tamanho)
/*
    Cria uma tabela com as palavras compativeis com o dicionario e a quantidade
    de vezes que aparecem emBOW A e BOW B

    Complexidade - O(n), n = tamanho do dict.
*/
{
    printf("\n                 Palavra               |BOW TRA |BOW TRB |");
    printf("\n------------------------------------------------------------");
    for(int i = 0; i < tamanho; i++)
    {
        if(ContA[i] + ContB[i] != 0)
        {
            printf("\n%s",dict[i]);
            printCaracter(strlen(dict[i]),strlen("                 Palavra               "),' ');
            printf("|");
            printNumCentralizado(ContA[i],8);
            printf("|");
            printNumCentralizado(ContB[i],8);
            printf("|");
        }
    }
}
#endif // BOWTRA_H_INCLUDED
