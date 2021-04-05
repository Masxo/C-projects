#include "utils.h"

#ifndef DICTIONARY_H
#define DICTIONARY_H

//#region DICTONARY STRUCTURE
//#region ENUM DATA TYPE
/**
 * Tipos de dados possíveis no dicionário, ordenados por tamanho máximo
 */
typedef enum datatype {
    DATA_TYPE_CHAR =    01,
    DATA_TYPE_INTEGER = 02,
    DATA_TYPE_FLOAT =   03,
    DATA_TYPE_DOUBLE =  04,
    DATA_TYPE_STRING =  00,
    DATA_TYPE_KEY =     10,
    DATA_TYPE_VALUE =   20
} dataType;
//#endregion

//#region ENTRY
/**
 * Um registro do dicionário
 */
typedef struct entry {
    // chave
    void *key;
    // valor
    void *value;
} Entry;
//#endregion

//#region DICTIONARY
/**
 * Dicionário de dados
 */
typedef struct dictionary {
    // registros do dicionário
    Entry *entries;
    // tipo da chave
    dataType keyType;
    // tipo dos valores
    dataType valueType;
    // tamanho do dicionário
    int size;
} Dictionary;
//#endregion
//#endregion

//#region DICTIONARY CRUD
//#region ADD DICTIONARY ENTRY
/**
 * Insere um registro no dicionário
 * @param dict dicionário a ser usado
 * @param key chave a ser inserida
 * @param value valor/dado a ser inserido
 * @return Um dicionário com um registro a mais
 */
Dictionary addDictionaryEntry(Dictionary *dict, void *key, void *value);
//#endregion

//#region CREATE DICTIONARY
/**
 * Cria um dicionário baseado nos paramentros de entrada
 * @param keyType tipo da chave
 * @param valueType tipo dos valores/dados
 * @param key chave a ser inserida
 * @param value valor/dado a ser inserido
 * @return um dicionário recém criado
 */
Dictionary createDictionary(dataType keyType, dataType valueType);
//#endregion

//#region SEARCH DICTIONARY
/**
 * Procura um registro no dicionário
 * @param dict dicionário a ser procurado
 * @param key chave a ser encontrada
 * @return o valor que a chave continha, caso não encontre é nulo
 */
void *searchDictionary(Dictionary dict, void *key);
//#endregion

//#region REMOVE DICTIONARY ENTRY
/**
 * Função para remover uma entrada do dicionário
 * @param dict dicionário a ser removido uma entrada
 * @param key chave a ser procurada no dicionário
 * @return dicionário com a entrada igual a chave, caso não encontre não é removida a chave
 */
Dictionary *removeDictionaryEntry(Dictionary *dict, void *key);
//#endregion
//#endregion

//#region DICTIOANRY SORT
/**
 * Organiza um dicionário com qsort
 * @param dict dicionário a ser organizado
 * @param type organização por chave ou valor
 * @return dicionário organizado em ordem crescente
 */
Dictionary sortDictionary(Dictionary *dict, dataType type);
//#endregion
#endif
