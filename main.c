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

    static char dict[300000][100];

    double dist;

    //Nomes Arquivos
    char nomeDicionario[50]; // Dicionario
    char nomeTRA[50]; // Referencia A
    char nomeTRB[50]; // Referencia B

    FILE *arqDict;
    FILE *referenciaA;
    FILE *referenciaB;
    FILE *bowTRA;
    FILE *bowTRB;

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

            do // Scan diretorio/nome do arquivo
            {
                printf("Informe o nome do Arquivo de Referencia A : ");
                scanf(" %[^\n]s", &nomeTRA);
                referenciaA = fopen(nomeTRA, "r"); // Abertura do arquivo desejado
            }
            while(erroArquivoInvalido(referenciaA)==true);

            //contaPalavras(referenciaA,dict,ContA,tamanho,index,qtde,letras);
            //criaBOW(dict,ContA,tamanho,"bowA.txt");

            bowTRA = fopen("bowA.txt", "w");
            gerarBow_Cont(bowTRA,ContA,referenciaA,dict,tamanho);
            fclose(bowTRA);

            separaTexto();
            printf("O Texto de Referencia '%s' foi aberto com sucesso.",nomeTRA);
            break;

        case (3): // Ler Texto de Referencia B (TRB)
            printTitulo("Ler Texto de Referencia B (TRB)");

            do // Scan diretorio/nome do arquivo
            {
                printf("Informe o nome do Arquivo de Referencia B : ");
                scanf(" %[^\n]s", &nomeTRB);
                referenciaB = fopen(nomeTRB, "r"); // Abertura do arquivo desejado
            }
            while(erroArquivoInvalido(referenciaB)==true);

            //contaPalavras(referenciaB,dict,ContB,tamanho,index,qtde,letras);
            //criaBOW(dict,ContB,tamanho,"bowB.txt");

            bowTRB = fopen("bowB.txt", "w");
            gerarBow_Cont(bowTRB,ContB,referenciaB,dict,tamanho);
            fclose(bowTRB);

            separaTexto();
            printf("O Texto de Referencia '%s' foi aberto com sucesso.",nomeTRB);
            break;

        case (4): // Exibir BOWs de TRA e TRB
            printTitulo("Exibir BOWs de TRA e TRB "); // Formatar

            printaBOWs(ContA,ContB,dict,tamanho);

            //gerarBow_Cont(bowTRA,ContA,referenciaA,dict,tamanho);

            break;

        case (5): // Mostrar similaridade entre TRA e TRB
            distEuclidiana(tamanho, ContA, ContB);
            //"distEuclidiana.h"

            break;

        case (0): // Sair
            printf("saindo...");

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
            if(!bowTRA)
                fclose(bowTRA);
            if(!bowTRB)
                fclose(bowTRB);

            exit(0); // Confirmacao de saida
        }

        retornaMenu(); // Pausa o terminar ate que o usuario aperte enter e volte ao menu
    }
    while(1);

    return 0;
}
