#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#region LEITOR ENTRADA
//copy paste
/**
 * Leitor FUNCIONAL DE STDIN OU ARQUIVO
 * @param file entrada
 * @return string lida
 */
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
//#endregion

int main()
{
    //#region VARIÁVEIS & ETC.
    char *qnt = readline(stdin),*val = readline(stdin);
    // Vetor para guardar os valores inseridos
    double *barras = calloc(strtol(qnt,NULL,10),sizeof(double));
    // Quantidade de dados
    val = strtok(readline(stdin)," ");
    //#endregion

    // Repetição para os n dados
    for(int i = 0; val != NULL; i++) {
        // Incrementado valor de acordo com indice do vetor
        barras[strtol(val,NULL,10)]++;
        // obtenção do próximo dado
        val = strtok(NULL, " ");
    }

    free(val);

    // Repetição para apresentação
    for(int i = 0; i < strtol(qnt, NULL, 10); i++) {
        // Dado do vetor
        printf("%i - ",i);
        // Qnt de vezes que o dado apareceu no vetor
        for(int j = 0; j < barras[i]; j++) {
            printf("#");
        }
        // Quebra de linha
        printf("\n");
    }

    free(qnt);
    free(barras);

    return 0;
}

