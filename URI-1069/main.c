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
    } while ((string[pos++] != '\n') && !feof(file));
    // adiciona terminador nulo
    string[--pos] = '\0';
    // retorna a string lida
    return string;
}
//#endregion

//#REGION FIND DIAMONDS
int findDiamond(char *string) {
    int start = 0, end = 0, diamond = 0;
    for(int i = 0; i < strlen(string);  i++) {
        if(string[i] == '<') {
            start++;
        } else if (string[i] == '>' && start) {
            end++;
        }
        if(start && end) {
            diamond++;
            start--;
            end--;
        }
    }
    return diamond;
}
//#endregion

int main() {
    int qnt = atoi(readline(stdin));
    for (int i = 0; i < qnt; ++i) {
        printf("%i\n",findDiamond(readline(stdin)));
    }
    return 0;
}
