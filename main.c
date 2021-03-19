#include <stdio.h>
#include <stdlib.h>

#include "menu.h" // Contem os cases
#include "formating.h"

/*
    Grupo :
    - 200056981_Arthur Ferreira Rodrigues
    - 190086521_Eduardo Rodrigues de Farias
    - 200019015_Guilherme Puida Moreira
    - 200042360_Nícolas Roberto de Queiroz
    - 200025937_Paulo Maciel Torres Filho

    README @ https://github.com/Nicolas-Roberto/Trabalho-Pr-tico-I/blob/main/README.md
*/

int main()
{
    int inputMenu; // Entrada do usuario para ver a escolha da opcao do menu
    int tamanho_dict; // Tamanho do Dicionario
    int *ContA, *ContB; //Contador de palavras do TRA e do TRB, respectivamente

    // f == false / t == false
    char existeDict = 'f';
    char existeTRA = 'f';
    char existeTRB = 'f';

    static char dict[300000][100];//Dict e uma Array de Strings, armazena todas as palavras do dicionario

    //Declaracao dos arquivos
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
                  // O(n), n = palavras no dicionario
            case1(arqDict, &tamanho_dict, dict, &existeDict);

            // Alocacao de memoria
            ContA = (int *)calloc(tamanho_dict,sizeof(int));
            ContB = (int *)calloc(tamanho_dict,sizeof(int));
            break;

        case (2): // Ler Texto de Referencia A (TRA)
                  // O(n + a), n = palavras no dicionario, a = palavras no arquivo de referencia A
            case2_3(referenciaA, bowTRA, tamanho_dict, ContA, dict, existeDict, &existeTRA,'A');
            break;

        case (3): // Ler Texto de Referencia B (TRB)
                  // O(n + b), n = palavras no dicionario, b = palavras no arquivo de referencia B
            case2_3(referenciaB, bowTRB, tamanho_dict, ContB, dict, existeDict, &existeTRB,'B');
            break;

        case (4): // Exibir BOWs de TRA e TRB
                  // O(n), n = palavras no dicionario
            case4(tamanho_dict, ContA, ContB, dict, existeDict, existeTRA, existeTRB);
            break;

        case (5): // Mostrar similaridade entre TRA e TRB
                  // O(n), n = palavras no dicionario
            case5(tamanho_dict, ContA, ContB, existeDict, existeTRA, existeTRB);
            break;

        /*

        Complexidade total do programa: O(n + (n + a) + (n + b) + n + n) = O(n + a + b)
        Melhor caso: O(n + a + b)
        Pior caso: O(n + a + b)

        n = numero de palavras no dicionario,
        a = numero de palavras no arquivo de referencia A,
        b = numero de palavras no arquivo de referencia B.

        */



        case (0): // Sair
            separaTexto();
            printf("Programa Encerrado");
            separaTexto();

            // Desalocacao de memoria
            free(ContA);
            free(ContB);

            // Fechando arquivo(s)
            if(existeDict == 'f')
                fclose(arqDict);
            if(existeTRA == 'f')
                fclose(referenciaA);
            if(existeTRB == 'f')
                fclose(referenciaB);

            return 0; // Confirmacao de saida
        }
        retornaMenu(); // Pausa o terminar ate que o usuario aperte enter e volte ao menu
    }while(1);
}
