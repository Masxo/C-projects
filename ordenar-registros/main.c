//#region INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#endregion

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

//#region CMP
// comparador para qsort
int cmp(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}
//#endregion

//#region MAIN
int main() {

    //#region VARIAVEIS & ETC.
    char **list = calloc(1,sizeof(char *));
    int i = 0;
    //#endregion

    //#region LEITURA DE DADOS
    while(!feof(stdin)) {
        list = realloc(list,sizeof(char *) * (i + 1));
        list[i] = readline(stdin);
        i++;
    }
    //#endregion

    //#region EXECUÇÃO SORT E ORGANIZAR STRING
    if(list[0][0] == '1') {
        //#region ORGANIZAÇÃO DO ARRAY
        // exclui a primeira casa da lista pois ela já foi utilizada e irá bagunçar o qsort
        for (int j = 1; j < i; ++j) {
            list[j - 1] = list[j];
        }
        // desaloca a casa já não mais utililizada
        list = realloc(list,--i *sizeof(char *));
        //#endregion

        //#region SORT
        // ordena de forma alfabética
        qsort(list,i,sizeof(list),cmp);
        //#endregion

        //#region ORGANIZAÇÃO DA STRING
        for(int j = 0; j < i; j++) {
            // inverte a string
            list[j] = strrev(list[j]);
            // pega o ano invertido
            char *c = strtok(list[j]," ");
            // concatena o ano invertido no final da string e inverte ela para o normal
            list[j] = strrev(strcat(strcat(strtok(NULL,"\0")," "),c));
        }
        //#endregion
    } else {
        //#region ORGANIZAÇÃO DO ARRAY E STRING
        for(int j = 1; j < i; j++) {
            // inverte a string
            list[j] = strrev(list[j]);
            // pega o ano invertido
            char *c = strtok(list[j]," ");
            // concatena o ano invertido no final da string e inverte ela para o normal
            list[j] = strrev(strcat(strcat(strtok(NULL,"\0")," "),c));
            // exclui a primeira casa da lista pois ela já foi utilizada e irá bagunçar o qsort
            list[j - 1] = list[j];
        }
        // desaloca a casa já não mais utililizada
        list = realloc(list,--i *sizeof(char *));
        //#endregion

        //#region SORT
        // ordena de forma alfabética
        qsort(list,i,sizeof(list),cmp);
        //#endregion
    }
    //#endregion

    //#region EXIBIÇÃO DOS DADOS
    for(int j = 0; j < i; j++) {
        // passa data para int pois é necessário
        int k = strtol(strtok(list[j]," "), NULL, 10);
        // re-insere resto da string na lista
        list[j] = strtok(NULL,"\0");
        //apresenta os dados
        printf("%d \t %s\n",k,list[j]);
    }
    //#endregion

    //#region LIBERAR MEMÓRIA
    free(list);
    //#endregion

    return 0;
}
//#endregion


