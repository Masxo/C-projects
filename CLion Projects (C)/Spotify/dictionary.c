#include "dictionary.h"

#include <stdlib.h>
#include <string.h>

//#region DICTIONARY
//#region DICTIONARY CRUD
//#region ADD DICTIONARY ENTRY
Dictionary addDictionaryEntry(Dictionary *dict, void *key, void *value) {
    // aumenta o tamanho do dicionário
    dict->entries = realloc(dict->entries, ++dict->size * sizeof(Entry));
    // insere a chave
    dict->entries[dict->size - 1].key = key;
    // insere o valor
    dict->entries[dict->size - 1].value = value;
    return *dict;
}
//#endregion

//#region CREATE DICTIONARY
Dictionary createDictionary(dataType keyType, dataType valueType) {
    // cria o dixionário
    Dictionary dict = {.keyType = keyType, .valueType = valueType, .size = 0};
    // atualiza o tamanho das entradas
    dict.entries = calloc(dict.size, sizeof(Entry));
    return dict;
}
//#endregion

//#region SEARCH DICTIONARY
void *searchDictionary(Dictionary dict, void *key) {
    for (int i = 0; i < dict.size; i++) {
        // verificação se foi encontrada a chave de acordo com o tipo da chave
        switch (dict.keyType) {
            case DATA_TYPE_CHAR:
                if(*((char *)(dict.entries[i].key)) == *((char *) key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_INTEGER:
                if(*((int *)(dict.entries[i].key)) == *((int *) key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_FLOAT:
                if(*((float *)(dict.entries[i].key)) == *((float *) key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_DOUBLE:
                if(*((double *)(dict.entries[i].key)) == *((double *) key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_STRING:
                if(strcmp(*((char **)(dict.entries[i].key)),*((char **) key)))
                    return dict.entries[i].value;
                break;
        }
    }
    return NULL;
}
//#endregion

//#region REMOVE DICTIONARY ENTRY
Dictionary *removeDictionaryEntry(Dictionary *dict, void *key) {
    for (int i = 0; i < dict->size; i++) {
        // verificação se foi encontrada a chave de acordo com o tipo da chave
        switch (dict->keyType) {
            case DATA_TYPE_CHAR:
                if(*((char *)(dict->entries[i].key)) == *((char *) key)) {
                    for (int j = ++i; j < dict->size; j++)
                        dict->entries[j - 1] = dict->entries[j];
                    return dict;
                }
                break;
            case DATA_TYPE_INTEGER:
                if(*((int *)(dict->entries[i].key)) == *((int *) key)) {
                    for (int j = ++i; j < dict->size; j++)
                        dict->entries[j - 1] = dict->entries[j];
                    return dict;
                }
                break;
            case DATA_TYPE_FLOAT:
                if(*((float *)(dict->entries[i].key)) == *((float *) key)) {
                    for (int j = ++i; j < dict->size; j++)
                        dict->entries[j - 1] = dict->entries[j];
                    return dict;
                }
                break;
            case DATA_TYPE_DOUBLE:
                if(*((double *)(dict->entries[i].key)) == *((double *) key)) {
                    for (int j = ++i; j < dict->size; j++)
                        dict->entries[j - 1] = dict->entries[j];
                    return dict;
                }
                break;
            case DATA_TYPE_STRING:
                if(strcmp(*((char **)(dict->entries[i].key)),*((char **) key))) {
                    for (int j = ++i; j < dict->size; j++)
                        dict->entries[j - 1] = dict->entries[j];
                    return dict;
                }
                break;
        }
    }
    return NULL;
}
//#endregion
//#endregion

//#region DICTIONARY EXTRA FUNCTIONS
//#region DICTIONARY SORTER
//#region COMAPARATORS
//#region COMPARE CHAR BY KEY
/**
 * Comparador para qsort a partir de chave e char
 */
int compCKey(const void *e1, const void *e2) {
    return ((Entry *) e1)->key - ((Entry *) e2)->key;
}
//#endregion

//#region COMPARE INT BY KEY
/**
 * Comparador para qsort a partir de chave e int
 */
int compIKey(const void *e1, const void *e2) {
    return atoi(((Entry *) e1)->key == NULL ? "0" : ((Entry *) e1)->key) -
           atoi(((Entry *) e2)->key == NULL ? "0" : ((Entry *) e2)->key);
}
//#endregion

//#region COMPARE FLOAT BY KEY
/**
 * Comparador para qsort a partir de chave e float/double
 */
int compFKey(const void *e1, const void *e2) {
    return atof(((Entry *) e1)->key == NULL ? "0" : ((Entry *) e1)->key) -
           atof(((Entry *) e2)->key == NULL ? "0" : ((Entry *) e2)->key);
}
//#endregion

//#region COMPARE STRING BY KEY
/**
 * Comparador para qsort a partir de chave e string
 */
int compSKey(const void *e1, const void *e2) {
    return strcmp((char *) ((Entry *) e1)->key, (char *) ((Entry *) e2)->key);
}
//#endregion

//#region COMPARE CHAR BY VALUE
/**
 * Comparador para qsort a partir de valor e char
 */
int compCVal(const void *e1, const void *e2) {
    return ((Entry *) e1)->value - ((Entry *) e2)->value;
}
//#endregion

//#region COMPARE INT BY KEY
/**
 * Comparador para qsort a partir de valor e int
 */
int compIVal(const void *e1, const void *e2) {
    return atoi(((Entry *) e1)->value == NULL ? "0" : ((Entry *) e1)->value) -
           atoi(((Entry *) e2)->value == NULL ? "0" : ((Entry *) e2)->value);
}
//#endregion

//#region COMPARE FLOAT BY KEY
/**
 * Comparador para qsort a partir de valor e float/double
 */
int compFVal(const void *e1, const void *e2) {
    return atof(((Entry *) e1)->value == NULL ? "0" : ((Entry *) e1)->value) -
           atof(((Entry *) e2)->value == NULL ? "0" : ((Entry *) e2)->value);
}
//#endregion

//#region COMPARE STRING BY KEY
/**
 * Comparador para qsort a partir de valor e string
 */
int compSVal(const void *e1, const void *e2) {
    return strcmp((char *) ((Entry *) e1)->value, (char *) ((Entry *) e2)->value);
}
//#endregion
//#endregion

//#region DICTIOANRY SORT
Dictionary sortDictionary(Dictionary *dict, dataType type) {
    // verificação do tipo de valor como base
    if (type == DATA_TYPE_KEY) {
        // verificação do tipo da chave
        switch (dict->keyType) {
            //#region DATA TYPE CHAR
            case DATA_TYPE_CHAR:
                qsort(dict->entries, dict->size, sizeof(Entry), compCKey);
                break;
                //#endregion

                //#region DATA TYPE INTEGER
            case DATA_TYPE_INTEGER:
                qsort(dict->entries, dict->size, sizeof(Entry), compIKey);
                break;
                //#endregion

                //#region DATA TYPE FLOAT
            case DATA_TYPE_FLOAT:
                qsort(dict->entries, dict->size, sizeof(Entry), compFKey);
                break;
                //endregion

                //#region DATA TYPE DOUBLE
            case DATA_TYPE_DOUBLE:
                qsort(dict->entries, dict->size, sizeof(Entry), compFKey);
                break;
                //#endregion

                //#region DATA TYPE STRING
            default:
                qsort(dict->entries, dict->size, sizeof(Entry), compSKey);
                break;
                //#endregion
        }
    } else if (type == DATA_TYPE_VALUE) {
        // verificação do tipo do valor
        switch (dict->valueType) {
            //#region DATA TYPE CHAR
            case DATA_TYPE_CHAR:
                qsort(dict->entries, dict->size, sizeof(Entry), compCVal);
                break;
                //#endregion

                //#region DATA TYPE INTEGER
            case DATA_TYPE_INTEGER:
                qsort(dict->entries, dict->size, sizeof(Entry), compIVal);
                break;
                //#endregion

                //#region DATA TYPE FLOAT
            case DATA_TYPE_FLOAT:
                qsort(dict->entries, dict->size, sizeof(Entry), compFVal);
                break;
                //endregion

                //#region DATA TYPE DOUBLE
            case DATA_TYPE_DOUBLE:
                qsort(dict->entries, dict->size, sizeof(Entry), compFVal);
                break;
                //#endregion

                //#region DATA TYPE STRING
            default:
                qsort(dict->entries, dict->size, sizeof(Entry), compSVal);
                break;
                //#endregion
        }
    }

    return *dict;
}
//#endregion
//#endregion
//#endregion
//#endregion

