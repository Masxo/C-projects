#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

//#region READLINE

/**
 * Leitor FUNCIONAL DE STDIN OU ARQUIVO
 * @param file entrada
 * @return string lida
 */
char *readline(FILE *file);
//#endregion

//#region STRING SPLITS

//#region ENUM & STRUCT
//#region STRING BUILDER
/**
 * construtor de strings
 * contém um vetor de strings e um int do tamanho do vetor
 */
typedef struct stringBuilder {
    int size;
    char **strings;
}StringBuilder;

/**
 * libera o StringBuilder
 * @param s StringBuilder a ser liberado
 */
void freeStringBuilder(StringBuilder s);
//#endregion

//#region STRING SPLIT TYPE
/**
 * tipo de retorno do split
 */
typedef enum splittype {
    SPLIT_AFTER = 0,
    SPLIT_BEFORE = 1,

} splitType;
//#endregion
//#endregion

//#region STRING SPLIT BY PARAM
/**
 * Quebra a string de acordo com o parametro
 * <h3> <b> NÃO UTILIZA STRING INSERIDA </b> </h3>
 * @param string string a ser quebrada
 * @param param parametro a ser procurado
 * @param type tipo do retorno da quebra
 * @return retorna a string quebrada caso encontre examente o parametro inserido
 */
char *strSP(char *string, const char *param, splitType type);
//#endregion

//#region STRING SPLIT BY PARAM N TIMES
/**
 * quebra a string n vezes
 * <h3> <b> NÃO UTILIZA STRING INSERIDA </b> </h3>
 * @param string string a ser quebrada
 * @param param parametro a ser procurado
 * @param runs quantidade de vezes executada ou 0 para todas as vezes possíveis
 * @return retorna o stringBuilder contendo as strings quebradas
 */
StringBuilder strSPT(char *string, const char *param, int runs);
//#endregion

void freeStringBuilder(StringBuilder s);
//#endregion

#endif