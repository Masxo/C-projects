#include "dataStructures.h"

#include <stdlib.h>
#include <string.h>

//#region DICTIONARY
//#region EXTRA FUNCTIONS
//#region SORTER
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

//#region COMPARE INT BY VALUE
/**
 * Comparador para qsort a partir de valor e int
 */
int compIVal(const void *e1, const void *e2) {
    return atoi(((Entry *) e1)->value == NULL ? "0" : ((Entry *) e1)->value) -
           atoi(((Entry *) e2)->value == NULL ? "0" : ((Entry *) e2)->value);
}
//#endregion

//#region COMPARE FLOAT BY VALUE
/**
 * Comparador para qsort a partir de valor e float/double
 */
int compFVal(const void *e1, const void *e2) {
    return atof(((Entry *) e1)->value == NULL ? "0" : ((Entry *) e1)->value) -
           atof(((Entry *) e2)->value == NULL ? "0" : ((Entry *) e2)->value);
}
//#endregion

//#region COMPARE STRING BY VALUE
/**
 * Comparador para qsort a partir de valor e string
 */
int compSVal(const void *e1, const void *e2) {
    return strcmp((char *) ((Entry *) e1)->value, (char *) ((Entry *) e2)->value);
}
//#endregion
//#endregion

//#region SORT
Dictionary sortDictionary(Dictionary *dict, DataType type) {
    // verificação do tipo de valor como base
    if (dict->keyType != DATA_TYPE_STRUCT && dict->valueType != DATA_TYPE_STRUCT) {
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
    }
    return *dict;
}
//#endregion
//#endregion

//#region DESTROYER
void destroyDictonaryEntry(Dictionary *dict, int index) {
    // libera cada ponteiro dentro do dicionário
    free(dict->entries[index].value);
    free(dict->entries[index].key);
}

void destroyDictionary(Dictionary *dict) {
    // libera cada entrada do dicionário
    for(int i = 0; i < dict->size; i++)
        destroyDictonaryEntry(dict,i);
    // libera o vetor de entradas
    free(dict->entries);
}
//#endregion
//#endregion

//#region CRUD
//#region CREATE
Dictionary createDictionary(DataType keyType, DataType valueType) {
    // cria o dicionário
    Dictionary dict = {
            .keyType = keyType,
            .valueType = valueType,
            .size = 0
    };
    return dict;
}
//#endregion

//#region ADD ENTRY
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

//#region REMOVE BY ENTRY
Dictionary removeDictionaryEntry(Dictionary *dict, void *key) {
    int i;
    // verificação se a chave não é um struct
    for (i = 0; i < dict->size && dict->keyType != DATA_TYPE_STRUCT; i++) {
        // verificação se foi encontrada a chave de acordo com o tipo da chave
        switch (dict->keyType) {
            case DATA_TYPE_CHAR:
                if (*((char *) (&dict->entries[i].key)) == *((char *) &key)) {
                    goto found;
                }
                break;
            case DATA_TYPE_INTEGER:
                if (*((int *) (&dict->entries[i].key)) == *((int *) &key)) {
                    goto found;
                }
                break;
            case DATA_TYPE_FLOAT:
                if (*((float *) (&dict->entries[i].key)) == *((float *) &key)) {
                    goto found;
                }
                break;
            case DATA_TYPE_DOUBLE:
                if (*((double *) (&dict->entries[i].key)) == *((double *) &key)) {
                    goto found;
                }
                break;
            case DATA_TYPE_STRING:
                if (strcmp((char *) (dict->entries[i].key), (char *) key)) {
                    goto found;
                }
                break;
        }
    }
    end :
        return *dict;
    found: {
        // sobreescreve o valor encontrado com o valor posterior
        for (int j = ++i; j < dict->size; j++)
            dict->entries[j - 1] = dict->entries[j];
        // libera a entrada do dicionário e decrementa o seu tamanho
        destroyDictonaryEntry(dict, --dict->size);
        goto end;
    }
}
//#endregion

//#region SEARCH
void *searchDictionary(Dictionary dict, void *key) {
    for (int i = 0; i < dict.size && dict.keyType != DATA_TYPE_STRUCT; i++) {
        // verificação se foi encontrada a chave de acordo com o tipo da chave
        switch (dict.keyType) {
            case DATA_TYPE_CHAR:
                if (*((char *) (&dict.entries[i].key)) == *((char *) &key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_INTEGER:
                if (*((int *) (&dict.entries[i].key)) == *((int *) &key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_FLOAT:
                if (*((float *) (&dict.entries[i].key)) == *((float *) &key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_DOUBLE:
                if (*((double *) (&dict.entries[i].key)) == *((double *) &key))
                    return dict.entries[i].value;
                break;
            case DATA_TYPE_STRING:
                if (strcmp((char *) (dict.entries[i].key), (char *) key))
                    return dict.entries[i].value;
                break;
        }
    }
    return NULL;
}
//#endregion
//#endregion
//#endregion

//#region LISTS
//#region CIRCULAR DOUBLE LINKED LIST
//#region EXTRA FUNCTIONS

//#region DESTROYER
void destroyDLLNode(DoubleLinkedListNode *node) {
    free(node->item);
}

void destroyDLL(DoubleLinkedList *dlinkedList) {
    for(DoubleLinkedListNode *dlln  = dlinkedList->first->next; dlln->next == dlinkedList->first; ) {
        DoubleLinkedListNode *next = dlln->next;
        free(dlln);
        dlln = next;
    }
}
//#endregion
//#endregion

//#region LINKED LIST CRUD

//#region ADD NODE
DoubleLinkedListNode* createDLLNode() {
    DoubleLinkedListNode *lln = malloc(sizeof(DoubleLinkedListNode));
    lln[0] = (DoubleLinkedListNode) {
            .item = 0,
            .next = 0,
            .prev = 0
    };
    return lln;
}

DoubleLinkedList addDLLNode(DoubleLinkedList *linkedList, void *value) {
    // adiciona o nó
    DoubleLinkedListNode *dllNode = createDLLNode();
    dllNode->item = value;
    dllNode->prev = linkedList->first->prev;
    dllNode->next = linkedList->first;
    linkedList->first->prev = dllNode;
    return *linkedList;
}
//#endregion

//#region CREATE
DoubleLinkedList createDLL(DataType type) {
    DoubleLinkedListNode *dllnode = createDLLNode();
    DoubleLinkedList dlinkedList = {
            .type = type,
            .size = 0,
            .first = dllnode
    };
    dlinkedList.first->prev = dlinkedList.first;
    dlinkedList.first->next = dlinkedList.first;
    return dlinkedList;
}
//#endregion

//#region REMOVE NODE
DoubleLinkedList removeDLLN(DoubleLinkedList *linkedList, void *value, int(*comp)(const void *, const void *)) {}
//#endregion

//#region SEARCH NODE
void *searchDLLN(DoubleLinkedList linkedList, void *value, int(*comp)(const void *, const void *)) {}
//#endregion
//#endregion
//#endregion
//#endregion

