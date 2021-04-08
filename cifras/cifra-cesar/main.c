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
    // operação de codificação e decodificação + string de entrada
    char *op_e_chave = readline(stdin), *string;
    // multiplicador para facilitar transformação
    int op_mult = op_e_chave[0] == '2' ? -1 : 1;
    // Leitura da chave da cifra
    op_e_chave = readline(stdin);
    // Leitura da string 
    string = readline(stdin);
    //#endregion

    // Transformação com base na chave e operação
    for(int i = 0; i < strlen(string); i++) {
        // transforma o caractere em um número de 0 a 25, soma com a chave
        // multiplicado pela operação, considera o módulo pois não há valor
        // maior que 25, depois retorna novamente a um char na base ASCII
        // Verificação da entrada
        if(string[i] >= 'a' && string[i] <= 'z') {
            string[i] = (((string[i] - 'a') + (op_mult * (strtol(op_e_chave,NULL,10))) + 26) % 26) + 'a';
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = (((string[i] - 'A') + (op_mult * (strtol(op_e_chave,NULL,10))) + 26) % 26) + 'A';
        }
    }

    printf("%s",string);

    free(op_e_chave);
    free(string);

    return 0;
}




