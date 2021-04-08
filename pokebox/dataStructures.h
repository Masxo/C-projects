#include "utils.h"

#ifndef DICTIONARY_H
#define DICTIONARY_H

//#region ENUM DATA TYPE
/**
 * Tipos de dados possíveis no dicionário, ordenados por tamanho máximo
 */
typedef enum datatype {
    DATA_TYPE_CHAR    = 01,
    DATA_TYPE_INTEGER = 02,
    DATA_TYPE_FLOAT   = 03,
    DATA_TYPE_DOUBLE  = 04,
    DATA_TYPE_STRUCT  = 05,
    DATA_TYPE_STRING  = 00,
    DATA_TYPE_KEY     = 10,
    DATA_TYPE_VALUE   = 20
} DataType;
//#endregion

//#region DICTINARY
//#region DICTONARY STRUCTURE

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
    DataType keyType;
    // tipo dos valores
    DataType valueType;
    // tamanho do dicionário
    int size;
} Dictionary;
//#endregion
//#endregion

//#region DICTIONARY CRUD
//#region CREATE DICTIONARY
/**
 * Cria um dicionário baseado nos paramentros de entrada
 * @param keyType tipo da chave
 * @param valueType tipo dos valores/dados
 * @param key chave a ser inserida
 * @param value valor/dado a ser inserido
 * @return um dicionário recém criado
 */
Dictionary createDictionary(DataType keyType, DataType valueType);
//#endregion

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

//#region SEARCH DICTIONARY
/**
 * Procura um registro no dicionário
 * @param dict dicionário a ser procurado
 * @param key chave a ser encontrada
 * @return o valor que a chave continha, caso não encontre é nulo ou a chave é um struct
 */
void *searchDictionary(Dictionary dict, void *key);
//#endregion

//#region REMOVE DICTIONARY ENTRY
/**
 * Função para remover uma entrada do dicionário
 * @param dict dicionário a ser removido uma entrada
 * @param key chave a ser procurada no dicionário
 * @return dicionário com a entrada removida, não é removida a chave caso não encontre-a ou a chave é um struct
 */
Dictionary removeDictionaryEntry(Dictionary *dict, void *key);
//#endregion
//#endregion

//#region DICTIOANRY SORT
/**
 * Organiza um dicionário com qsort
 * @param dict dicionário a ser organizado
 * @param type organização por chave ou valor
 * @return dicionário organizado em ordem crescente, caso a ser ordenado o valor seja um struct, ele não é ordenado
 */
Dictionary sortDictionary(Dictionary *dict, DataType type);

void destroyDictionary(Dictionary *dict);
//#endregion
//#endregion

//#region LISTS
//#region NORMAL LIST
//#region NORMAL LIST STRUCTURE
typedef struct normalList {
    void **List;
    DataType listType;
    int size;
} NormalList;
//#endregion

//#region NORMAL LIST CRUD
//#region CREATE NORMAL LIST
/**
 * cria uma nova lista
 * @param type tipo da lista
 * @return lista recém criada
 */
NormalList createNL(DataType type);
//#endregion

//#region ADD NORMAL LIST ENTRY
/**
 * Adiciona um novo valor na lista
 * @param normalList lista a ser usada
 * @param value valor a ser inserido
 * @return lista com valor inserido
 */
NormalList addNLtEntry(NormalList *normalList, void *value);
//#endregion

//#region REMOVE NORMAL LIST BY INDEX
/**
 * remove o index na lista
 * @param normalList lista  a ser procurada
 * @param index index a ser usado
 * @return lista com index removido ou a lista original caso index seja inválido
 */

NormalList removeNLByIndex(NormalList *normalList, int index);
//#endregion

//#region SEARCH NORMAL LIST BY INDEX
/**
 * Procura o valor na lista baseado no index
 * @param normalList lista  a ser procurada
 * @param index index a ser usado
 * @return valor encontrado ou nulo caso index seja inválido
 */
void *searchNL(NormalList normalList, int index);
//#endregion
//#endregion
//#endregion

//#region LINKED LIST
//#region LINKED LIST
typedef struct linkedListNode {
    struct linkedListNode *next;
    struct linkedListNode *prev;
    void *item;
}LinkedListNode;

typedef struct linkedList {
    LinkedListNode *list;
    LinkedListNode *first;
    DataType type;
    int size;
}LinkedList;
//#endregion

//#region LINKED LIST CRUD

//#endregion
//#endregion
//#endregion
#endif
