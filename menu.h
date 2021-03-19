#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>

#include "formating.h"
#include "MensagensErro.h"
#include "bibliotecaDict.h"
#include "distEuclidiana.h"
#include "bibliotecaBOW.h"

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

void case1(FILE *arqDict, int *tamanho_dict, char dict[][100], char *existeDict) /* Le o dicionario
        Complexidade total case1 - O(n), n = numero de palavras no dicionario.

*/
{
    char nomeDicionario[50]; // Dicionario

    printTitulo("Ler Arquivo Dicionario");

    do // Scan diretorio/nome do arquivo
    {
        printf("Informe o nome do arquivo de dicionario : ");
        scanf(" %[^\n]s", &nomeDicionario);
        arqDict = fopen(nomeDicionario, "r"); // Abertura do arquivo desejado
    } while (erroArquivoInvalido(arqDict));

    *tamanho_dict = contaLinhas(arqDict); // Conta quantas linhas tem o arquivo que foi aberto
    criarDict(arqDict, dict);            // Cria um dicionario (arquivo dict), complexidade O(n), n = palavras no dicionario.
    *existeDict = 't';

    separaTexto();
    printf("O Dicionario '%s' foi aberto com sucesso.", nomeDicionario);
}

void case2_3(FILE *referencia, FILE *bowTR, int tamanho_dict, int *Cont, /*Le o arquivo de referencia*/
        char dict[][100], char existeDict, char *existeTR,char carac)

        /*
        Complexidade total Case2_3 - O(n + a), n = numero de palavras no dicionario,
                                               a = numero de palavras no arquivo de referencia. */
{
    char nomeTR[50]; // Texto de Referencia A

    if(carac == 'A')
    {
        printTitulo("Ler Texto de Referencia A (TRA)");
    }
    else
    {
        printTitulo("Ler Texto de Referencia B (TRB)");
    }

    if (existeDict == 'f')
    {
        printf("Leia um dicionario antes de ler um Texto de Referencia!");
        return ;
    }

    if (*existeTR == 't')
    {
        printf("Texto de Referencia ja foi cadastrado.");
        return;
    }

    do // Scan diretorio/nome do arquivo
    {
        printf("Informe o nome do Arquivo de Referencia %c : ",carac);
        scanf(" %[^\n]s", &nomeTR);
        referencia = fopen(nomeTR, "r"); // Abertura do arquivo desejado
    }while(erroArquivoInvalido(referencia)==true);

    separaTexto();
    printf("O Texto de Referencia '%s' foi aberto com sucesso.\n",nomeTR);
    printf("Contagem sendo efetuada, aguarde.");

    // Contagem das palavras contidas no dicionario
    if(carac == 'A')
    {
        bowTR = fopen("bowA.txt", "w");
    }
    else
    {
        bowTR = fopen("bowB.txt", "w");
    }
    gerarBow_Cont(bowTR,Cont,referencia,dict,tamanho_dict); // O(n + a), n = palavras no dicionario, a = palavras no arquivo de referencia
    fclose(bowTR);

    *existeTR = 't';

    separaTexto();
    printf("Contagem efetuada com sucesso.");
}

void case4(int tamanho_dict, int *ContA, int *ContB, /* Exibir BOWs*/
        char dict[][100], char existeDict, char existeTRA, char existeTRB)

        // Complexidade total Case 4 - O(n), n = número de palavras no dicionário.
{
    printTitulo("Exibir BOWs de TRA e TRB ");

    if (existeDict == 'f')
    {
        printf("Erro: Nenhum dicionario escolhido!");
        return;
    }
    if (existeTRA == 'f')
    {
        printf("\nErro: Texto de Referencia A nao encontrado!");
        return;
    }
    if (existeTRB == 'f')
    {
        printf("\nErro: Texto de Referencia B nao encontrado!");
        return;
    }

    printaBOWs(ContA,ContB,dict,tamanho_dict);
}

void case5(int tamanho_dict, int *ContA, int *ContB, char existeDict, char existeTRA, char existeTRB)
/* Distancia Euclidiana (quanto mais proximo de 0, mais similares sao os arquivos)

   Complexidade total Case 5 - O(n), n = número de palavras no dicionario.
*/
{
    double distanciaEuclidiana;

   printTitulo("Exibir similaridade entre os dois textos");

    if (existeDict == 'f')
    {
        printf("Abra um arquivo de dicionario antes de prosseguir.");
        return;
    }

    if (existeTRA == 'f' || existeTRB == 'f')
    {
        printf("Abra os arquivos de referencia antes de prosseguir.");
        return;
    }

    distanciaEuclidiana = distEuclidiana(tamanho_dict, ContA, ContB);
    printf("\nDistancia Euclidiana entre TRA e TRB = %f\n", distanciaEuclidiana);
}

#endif
