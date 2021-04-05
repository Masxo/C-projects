#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#region LEITOR ENTRADA
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

//#region STRING SPLITS

//#region STRING SPLIT BY PARAM
char *strSP(char *string, const char *param, splitType type) {
    // variáveis de indice do parametro e da sting, além do tamanho de ambas
    int paramIndex = 0, paramsize = strlen(param), stringsize = strlen(string);
    // verifica se o tamanho de uma das duas é 0 ou se ambas são iguais
    if(!paramsize || paramsize == stringsize || !stringsize) {
        goto end;
    }
    // procura o parametro na sting
    for(int stringIndex = 0; stringIndex < stringsize; stringIndex++) {
        // verifica se encontrou a n casa do parametro
        if(string[stringIndex] == param[paramIndex]) {
            // verifica se encontrou o parametro inteiro
            if(++paramIndex == paramsize) {
                // diminui o index da string
                stringIndex--;
                // verifica que tipo de operação é para dar os valoes de acordo para min e max
                int min = (type ? 0 : stringIndex+paramsize), max = (type ? stringIndex : stringsize-stringIndex);
                // aloca espaço na memória para a string
                char *tempString = calloc(max+1,sizeof(char));
                // copia a quantidade de caracteres necessários
                strncpy(tempString,string+min,max);
                // adição de terminador nulo
                tempString[max] = '\0';
                // retorna a string encontrada
                return tempString;
            }
        // pula pra próxima casa
        } else {
            paramIndex = 0;
        }
    }
    // retorna nada
    end:
        return "";
}
//#endregion

//#region STRING SPLIT INTERNAL
/**
 * splitter recursivo interno das strings
 * @param string string a ser usada
 * @param param parametro de procura
 * @param times vezes que deve ser separada
 * @param split struct de resposta
 * @return split com as strings dentro
 */
StringBuilder strSPTInternal(char *string, const char *param,int times,StringBuilder split) {
    // verifica se a string está vazia ou se chegou ao número de execuções
    if(split.size < (times == -1 ? split.size+1 : times) && strcmp(string,"")) {
        // aumenta tamanho do vetor de strings
        split.strings = realloc(split.strings, sizeof(char *) * (++split.size));
        // insere a string necessária na casa certa
        split.strings[split.size-1] = strSP(string, param, SPLIT_BEFORE);
        // retira da string a string obtida
        string = strSP(string, param, SPLIT_AFTER);
        // chama recursivamente o splitter
        split = strSPTInternal(string,param,times,split);
        // libera a string
        free(string);
    }
    // retorna o string builder
    return split;
}
//#endregion

//#region STRING SPLIT BY PARAM N TIMES
StringBuilder strSPT(char *string, const char *param,int times) {
    // copia a string original
    char *tempstring = strdup(string);
    // cria um novo stringBuilder de tamanho 0
    StringBuilder split = { .size = 0 };
    // chama a função interna recursiva
    split = strSPTInternal(tempstring,param,times,split);
    // libera a tempstring
    free(tempstring);
    // retorn o stringBuilder
    return split;
}
//#endregion

void freeStringBuilder(StringBuilder s) {
    // libera cada string do stringBuilder
    for (int i = 0; i < s.size; i++) {
        free(s.strings[i]);
    }
    // libera o vetor das strings
    free(s.strings);
}

//#endregion