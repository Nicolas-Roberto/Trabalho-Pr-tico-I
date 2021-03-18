# Trabalho-Prático-I
Trabalho Prático I EDA

[![Build Status](https://travis-ci.org/condessalovelace/mavenquickstart.svg?branch=master)](https://travis-ci.org/condessalovelace/mavenquickstart) ![Quality Gate](https://sonarcloud.io/api/project_badges/measure?project=br.com%3Amavenquickstart&metric=alert_status)

### Programa em C que avalia a similaridade entre dois textos, atraves de cálculos de [BOWs](https://en.wikipedia.org/wiki/Bag-of-words_model), com base em um dicionário de palavras comum.

## Alunos


Nome                            | Matrícula  |
--------------------------------|------------|
Eduardo Rodrigues de Farias     | 190086521  |
Guilherme Puida Moreira         | 200019015  |
Paulo Maciel Torres Filho       | 200025937  |
Nícolas Roberto de Queiroz      | 200042360  |
Arthur Ferreira Rodrigues       | 200056981  |



## Começando

Para executar o projeto, será necessário instalar os seguintes programas:

- [CodeBlocks: Necessário para executar o projeto em C](https://www.codeblocks.org/downloads/)
- [Mingw: Necessário para compilar o projeto em C](https://sourceforge.net/projects/mingw-w64/)

## Desenvolvimento

Para iniciar o desenvolvimento, é necessário clonar o projeto do [GitHub](https://github.com/Nicolas-Roberto/Trabalho-Pr-tico-I.git) num diretório de sua preferência:

```
cd "diretorio de sua preferencia"
git clone https://github.com/Nicolas-Roberto/Trabalho-Pr-tico-I.git
```


## Características

O projeto pode ler arquivos de texto, um dicionário que será a base para a comparação e dois textos que serão comparados, calcular e exportar suas BOWs , a comparação
consiste em verificar se cada palavra do texto esta no dicionário e quantas vezes ela repete, e calcula e mostre a [Distância Euclidiana](https://pt.wikipedia.org/wiki/Dist%C3%A2ncia_euclidiana) do texto e dicionário.

## Complexidade 

O(n(a + b)), onde n = número de palavras no dicionário / a = número de palavras no arquivo de referência A / b = número de palavras no arquivo de referência de B.

O pior e melhor caso são equivalentes ao caso médio, portanto Θ(n(a + b)) e  Ω(n(a + b))

