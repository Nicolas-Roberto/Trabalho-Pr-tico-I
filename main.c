#include <stdio.h>
#include <stdlib.h>

#include "formating.h"
#include "menu.h"
#include "MensagensErro.h"
#include "bibliotecaDict.h"
#include "distEuclidiana.h"
#include "bowTRA.h"

int main()
{
    int inputMenu;
    int tamanho;
    int *ContA, *ContB;
    int verEntrada;

    static char dict[300000][100];

    double dist;

    //Nomes Arquivos
    char nomeDicionario[50]; // Dicionario
    char nomeTRA[50]; // Referencia A
    char nomeTRB[50]; // Referencia B

    FILE *arqDict = NULL;
    FILE *referenciaA = NULL;
    FILE *referenciaB = NULL;
    FILE *bowTRA = NULL;
    FILE *bowTRB = NULL;

    do // Repete ate que o usuario opte por sair
    {
        menu(); // Mostra o Menu

        do // Selecao da opcao do menu
        {
            printf("Selecionar : ");
            scanf("%d", &inputMenu);

            erroOpcaoValida(inputMenu,0,5); // Mostra Erro se a opcao nao existir

        }
        while(inputMenu<0 || inputMenu>5) ;

        clear(); // Limpa Terminal

        switch(inputMenu)
        {
        case (1): // Ler Arquivo Dicionario
            printTitulo("Ler Arquivo Dicionario");

            do // Scan diretorio/nome do arquivo
            {
                printf("Informe o nome do arquivo de dicionario : ");
                scanf(" %[^\n]s", &nomeDicionario);
                arqDict = fopen(nomeDicionario, "r"); // Abertura do arquivo desejado
            }
            while(erroArquivoInvalido(arqDict)==true);

            tamanho = contaLinhas(arqDict); // Conta quatas linhas tem o arquivo que foi aberto
            criarDict(arqDict, dict); // Cria um dicionario (arquivo dict)

            // Alocacao de memoria
            ContA = (int *)calloc(tamanho,sizeof(int));
            ContB = (int *)calloc(tamanho,sizeof(int));

            separaTexto();
            printf("O Dicionario '%s' foi aberto com sucesso.",nomeDicionario);
            break;

        case (2): // Ler Texto de Referencia A (TRA)
            printTitulo("Ler Texto de Referencia A (TRA)");

            if (!arqDict) {
                printf("Abra um arquivo de dicionario antes de abrir um arquivo de referencia.");
                break;
            }

            free(ContA);
            ContA = (int *)calloc(tamanho,sizeof(int));

            do // Scan diretorio/nome do arquivo
            {
                printf("Informe o nome do Arquivo de Referencia A : ");
                scanf(" %[^\n]s", &nomeTRA);
                referenciaA = fopen(nomeTRA, "r"); // Abertura do arquivo desejado
            }
            while(erroArquivoInvalido(referenciaA)==true);


            bowTRA = fopen("bowA.txt", "w");
            gerarBow_Cont(bowTRA,ContA,referenciaA,dict,tamanho);
            fclose(bowTRA);

            separaTexto();
            printf("O Texto de Referencia '%s' foi aberto com sucesso.", nomeTRA);
            break;

        case (3): // Ler Texto de Referencia B (TRB)
            printTitulo("Ler Texto de Referencia B (TRB)");

            if (!arqDict) {
                printf("Abra um arquivo de dicionario antes de abrir um arquivo de referencia.");
                break;
            }

            free(ContB);
            ContB = (int *)calloc(tamanho,sizeof(int));

            do // Scan diretorio/nome do arquivo
            {
                printf("Informe o nome do Arquivo de Referencia B : ");
                scanf(" %[^\n]s", &nomeTRB);
                referenciaB = fopen(nomeTRB, "r"); // Abertura do arquivo desejado
            }
            while(erroArquivoInvalido(referenciaB)==true);

            bowTRB = fopen("bowB.txt", "w");
            gerarBow_Cont(bowTRB,ContB,referenciaB,dict,tamanho);
            fclose(bowTRB);

            separaTexto();
            printf("O Texto de Referencia '%s' foi aberto com sucesso.",nomeTRB);
            break;

        case (4): // Exibir BOWs de TRA e TRB
            printTitulo("Exibir BOWs de TRA e TRB ");

            if (!arqDict) {
                printf("Abra um arquivo de dicionario antes de prosseguir.");
                break;
            }

            if (!referenciaA || !referenciaB) {
                printf("Abra os arquivos de referencia antes de prosseguir.");
                break;
            }

            printaBOWs(ContA,ContB,dict,tamanho);

            break;

        case (5): // Mostrar similaridade entre TRA e TRB
            printTitulo("Exibir similaridade entre os dois textos");

            if (!arqDict) {
                printf("Abra um arquivo de dicionario antes de prosseguir.");
                break;
            }

            if (!referenciaA || !referenciaB) {
                printf("Abra os arquivos de referencia antes de prosseguir.");
                break;
            }


            dist = distEuclidiana(tamanho, ContA, ContB);
            printf("\nDistancia Euclidiana entre '%s' e '%s' = %f\n", nomeTRA, nomeTRB, dist);

            break;

        case (0): // Sair
            printf("Programa Encerrado");

            // Desalocacao de memoria
            free(ContA);
            free(ContB);

            // Fechando arquivo(s)
            if(!arqDict)
                fclose(arqDict);
            if(!referenciaA)
                fclose(referenciaA);
            if(!referenciaB)
                fclose(referenciaB);
            
            return 0; // Confirmacao de saida
        }

        retornaMenu(); // Pausa o terminar ate que o usuario aperte enter e volte ao menu
    }
    while(1);
}
