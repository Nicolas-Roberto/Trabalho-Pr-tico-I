#include <stdio.h>
#include <stdlib.h>

FILE *AbreArquivo(char *NomeArqui){
    return fopen(NomeArqui, "r");   // Le o arquivo passado como parametro
}

void Limpatela(){
    #if defined(_linux) || defined(unix) || defined(APPLE_)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
