#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//copy paste
char *readline(FILE *file) {
    // string base
    char *string = 0;
    // tamanho da string
    int pos = 0;
    // leitura de
    do {
        // alocação da memória
        string = (char *) realloc(string, (pos + 1) * sizeof(char));
        // leitura do caractére
        string[pos] = (char) fgetc(file);
        // verificação se é o fim da leitura ou da linha
    } while ((string[pos++] != '\n') && ! feof(file));
    // adiciona terminador nulo
    string[--pos] = '\0';
    // retorna a string lida
    return string;
}

int main() {

    // linhas e colunas
    int rows, collumns;

    // entrada de valores
    rows = strtol(readline(stdin),NULL,10);

    collumns = strtol(readline(stdin),NULL,10);

    // verificação da ordem da matriz
    if(rows > 3 || rows < 1 || collumns > 3 || collumns < 1) {
        printf("Entradas invalidas!\n");
    // verificação se é matriz quadrada
    } else if (rows != collumns) {
        printf("A matriz de entrada nao possui determinante!\n");
    } else {
        // criação da matriz
        double **matrix = (double **) malloc(rows * sizeof(double *)), det = 0;
        // criação de alocação de informação temporária
        char *temp;
        for(int i = 0; i < rows; i++) {
            //alocação de tamanho em cada indice da matriz
            matrix[i] = (double *) malloc(collumns * sizeof(double));
            // leitura da entrada
            temp = readline(stdin);
            // separação da entrada
            temp = strtok(temp," ");
            for(int j = 0; j < collumns; j++) {
                // adição da entrada a a matriz
                matrix[i][j] = strtol(temp, NULL, 10);
                temp = strtok(NULL," ");
            }
        }

        // determinante da matriz de ordem 1
        if(rows == 1) {
            det = matrix[0][0];
        // determinate da matriz de ordem 2
        } else if(rows == 2) {
            det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        // determinante de ordem 3, lapalce, leibniz, sarrus qlq um serve
        } else {
            det = matrix[0][0] * matrix[1][1] * matrix[2][2] + //
                    matrix[0][1] * matrix[1][2] * matrix[2][0] +//
                    matrix[0][2] * matrix[1][0] * matrix[2][1] -
                    matrix[0][2] * matrix[1][1] * matrix[2][0] -
                    matrix[0][1] * matrix[1][0] * matrix[2][2] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1];
        }

        // desalocação da memória
        free(temp);
        free(matrix);
        // apresentação dos resultados
        printf("O determinante da matriz de entrada equivale a %.0f e tem ordem %d\n",det,rows);
    }
    return 0;
}
