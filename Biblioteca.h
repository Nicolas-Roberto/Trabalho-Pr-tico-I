#ifndef Biblioteca_h
#define Biblioteca_h

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int menu(){
    char popc = '0', NomeArqui[30] = "";
    FILE *ArquiA = NULL;
    FILE *ArquiB = NULL;
    FILE *ArquiD = NULL;
    while(popc != 'S'){
    printf("\n################## MENU ##################");
    printf("\n");
    printf("\n1 - Ler arquivo de dicionario:");
    printf("\n2 - Ler arquivo contendo texto de referencia A:");
    printf("\n3 - Ler um arquivo contendo texto de referencia B:");
    printf("\n4 - Exibir BOWs de TRA e TRB:");
    printf("\n5 - Mostrar similaridade entre os dois textos:");
    printf("\n0 - Sair");
    printf("\n##########################################");
    printf("\nOpcao: ");
    scanf("\n%c", &popc);   //recepe o comando do usuario

    switch (popc) {
        case '1':   //Le o dicionario

            printf("Dicionario: ");
            scanf("%s",NomeArqui);
            if(ArquiD != NULL)
                fclose(ArquiD);
            ArquiD = AbreArquivo(NomeArqui);
            if(ArquiD == NULL){
                printf("Erro 1: Arquivo nao pode ser aberto\n");
                break;
            }
            printf("%s !!!aberto!!!\n", NomeArqui);
                break;
        case '2':   // Le o arquivo A

            printf("Arquivo de Referencia A: ");
            scanf("%s",NomeArqui);
            if(ArquiA != NULL)
                fclose(ArquiA);
            ArquiA = AbreArquivo(NomeArqui);
            if(ArquiA == NULL){
                printf("Erro 1: Arquivo nao pode ser aberto\n");
                break;
            }
            printf("%s !!!aberto!!!\n", NomeArqui);
            break;
        case '3':   // Le o arquivo B

            printf("Arquivo de Referencia B: ");
            scanf("%s",NomeArqui);
            if(ArquiB != NULL)
                fclose(ArquiB);
            ArquiB = AbreArquivo(NomeArqui);
            if(ArquiB == NULL){
                printf("Erro 1: Arquivo nao pode ser aberto\n");
                break;
            }
            printf("%s !!!aberto!!!\n", NomeArqui);
            break;

        case '4':

            break;

        case '5':

            break;

        case '0':

            break;

        default :
            printf("!!!COMANDO INVALIDO!!!");
            break;
        }
    if(popc == '0')
        break;
    fclose(ArquiA);
    fclose(ArquiB);
    fclose(ArquiD);
    Limpatela();//Limpa a tela

    }
    return 0;
}



#endif


