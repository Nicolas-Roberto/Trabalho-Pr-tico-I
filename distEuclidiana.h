
#ifndef DISTEUCLIDIANA_H_INCLUDED
#define DISTEUCLIDIANA_H_INCLUDED

#include <math.h>

/*
distEuclidiana - O(n), n = numero de elementos no dicionario.
*/

double distEuclidiana(int tamanho, int *ContA, int *ContB) // Calcular a similaridade entre os dois BOW's
{

    double soma = 0;
    int i;

    // Adiciona a soma o quadrado da diferenca da quantidade de vezes que certa palavra apareceu
    for(i = 0; i < tamanho; i++)
    {
        soma += pow(ContA[i] - ContB[i], 2);
    }
    return pow(soma, 0.5);
}

#endif // DISTEUCLIDIANA_H_INCLUDED
