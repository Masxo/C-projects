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

int main() {
    //#region VARIABLES & ETC.
    // palavra a ser encontrada
    char *find = readline(stdin),
    // palavra que substitui
    *rep = readline(stdin),
    // string de leitura
    *string = readline(stdin);
    //quantidade de letras e palavras iguais encontradas
    int found  = 0;
    //#endregion

    //#region STRING SUBSTITUTION
    for (int i  = 0; i < strlen(string); i++) {
        // caracteres da ordem x batem?
        if(string[i] == find[found])
            found++;
        // senão caracteres encotrados são maiores que 0 ?
        else if(found > 0) {
            // escreve os caracteres que deram falso positivo
            for (int j = i - found; j < i; i++)
                printf("%c",string[j]);
            found = 0;
        // não foi encontrado caractere?
        // escreve caractere atual
        } else if (found == 0)
            printf("%c", string[i]);
        // encontrado a palavra?
        if (found == strlen(find)) {
            // escreve a palavra
            for (int j = 0; j < strlen(rep); j++)
                printf("%c", rep[j]);
            found = 0;
        }
    }
    //#endregion

    //#region FREE
    free(find);
    free(rep);
    free(string);
    //#endregion

    return 0;
}
