#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    //#region VARIAVEIS & ETC.
    char *ent = readline(stdin);
    int sum = 0;
    //#endregion

    // transformação de binario para decimal
    for(int i = 0; i  < strlen(ent) ; i++) {
        // verifica se casa não é zero
        if (ent[i] == '1') {
            // soma valor de acordo com casa atual
            sum += pow(2,strlen(ent) - i - 1);
        }
    }

    printf("%i",sum);

    free(ent);

    return 0;
}
