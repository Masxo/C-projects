#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#region DICTIONARY
//#region DICTONARY STRUCTURE
//#region ENUM DATA TYPE
/**
 * Tipos de dados possíveis no dicionário, ordenados por tamanho máximo
 */
typedef enum datatype {
    DATA_TYPE_CHAR = sizeof(char),
    DATA_TYPE_INTEGER = sizeof(int),
    DATA_TYPE_FLOAT = sizeof(float),
    DATA_TYPE_DOUBLE = sizeof(double),
    DATA_TYPE_STRING = 0
} dataType;
//#endregion

//#region ENTRY
/**
 * Um registro do dicionário
 */
typedef struct entry {
    void *key;
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
Dictionary *addDictionaryEntry(Dictionary *dict, void *key, void *value) {
    dict->entries = realloc(dict->entries, ++dict->size * sizeof(Entry));
    dict->entries[dict->size - 1].key = key;
    dict->entries[dict->size - 1].key = key;
    return dict;
}
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
Dictionary createDictionary(dataType keyType, dataType valueType, void *key, void *value) {
    Dictionary dict = {.keyType = keyType, .valueType = valueType, .size = 0};
    dict.entries = calloc(dict.size, sizeof(Entry));
    addDictionaryEntry(&dict, key, value);
    return dict;
}
//#endregion

//#region SEARCH DICTIONARY
/**
 * Procura um registro no dicionário
 * @param dict dicionário a ser procurado
 * @param key chave a ser encontrada
 * @return o valor que a chave continha, caso não encontre é nulo
 */
void *searchDictionary(Dictionary dict, void *key) {
    for (int i = 0; i < dict.size; i++) {
        // verificação se foi encontrada a chave de acordo com o tipo da chave
        if (dict.keyType == DATA_TYPE_STRING && !strcmp(key, dict.entries[i].key)) {
            return dict.entries[i].value;
        } else if (dict.entries[i].key == key) {
            return dict.entries[i].value;
        }
    }
    return NULL;
}
//#endregion

//#region REMOVE DICTIONARY ENTRY
/**
 * Função para remover uma entrada do dicionário
 * @param dict dicionário a ser removido uma entrada
 * @param key chave a ser procurada no dicionário
 * @return dicionário com a entrada igual a chave, caso não encontre não é removida a chave
 */
Dictionary *removeDictionaryEntry(Dictionary *dict, void *key) {
    for (int i = 0; i < dict->size; i++) {
        // verificação se foi encontrada a chave de acordo com o tipo da chave
        if (dict->keyType == DATA_TYPE_STRING && !strcmp(key, dict->entries[i].key)) {
            for(int j = ++i; j < dict->size; j++) {
                dict->entries[j-1] = dict->entries[j];
            }
        } else if (dict->entries[i].key == key) {
            for(int j = ++i; j < dict->size; j++) {
                dict->entries[j-1] = dict->entries[j];
            }
        }
    }
    return dict;
}
//#endregion
//#endregion
//#endregion

//#region LITTLE ENDIANS, BYTE & BIT
//#region READ LITTLE ENDIANS BIT
/**
 * Leitura de um byte em little endians, bit por bit
 * @param file arquivo a ser lido
 * @return bits lidos em um array
 */
unsigned char *readLittleEndiansBits(FILE *file) {
    // buffer e bit array
    unsigned char buf[1], *bitArray = calloc(8, sizeof(char));;
    // leitura do arquivo, byte por byte, 1 byte por vez
    fread(buf, 1, 1, file);
    // transformação em bits
    for (int i = 0; i < 9; i++) {
        bitArray[i] = floor((double) buf[0] / pow(2, i));
    }

    return bitArray;
}
//#endregion

//#region BITS TO BYTE
/**
 * Transforma 8 bits em um byte
 * @param bitArray array dos bits, 0's e 1's
 * @return bit transformado para um byte
 */
unsigned char bitsToByte(unsigned char bitArray[8]) {
    unsigned char result = 0;
    for (int i = 0; i < 9; i++) {
        result += pow(2, i * bitArray[i]);
    }
    return result;
}
//#endregion

//#region BYTE TO BIT
/**
 * Transforma byte em 8 bits
 * @param Byte byte a ser transformado
 * @return array de 8 bits
 */
unsigned char *byteToBits(unsigned char Byte) {
    // bit array
    unsigned char *bitArray = calloc(8, sizeof(char));
    // transformação em bits
    for (int i = 0; i < 9; i++) {
        bitArray[i] = floor((double) Byte / pow(2, i));
    }
    return bitArray;
}
//#endregion

//#region READ LITTLE ENDIANS
/**
 * Leitura do arquivo em little endians
 * @param file arquivo a ser lido
 * @param qnt quantidade de bytes a serem lidos
 * @return bytes lidos transformados em número
 */
long long readLittleEndians(FILE *file, char qnt) {
    // buffer
    unsigned char buf[qnt];
    // resultado
    long long result = 0;
    // leitura do arquivo, byte por byte, 1 byte por vez
    fread(buf, 1, qnt, file);
    // transformação em número
    for (int i = qnt - 1; i >= 0; i--) {
        result = (result << 8) | (long long) buf[i];
    }

    return result;
}
//#endregion

//#region WRITE LITTLE ENDIANS
/**
 * Escrita do arquivo em little endians
 * @param file arquivo a ser escrito
 * @param qnt quantidade de bytes a serem escritos
 * @param fileWrite arquivo a ser escrito
 */
void writeLittleEndians(long long item, FILE *file, short qnt) {
    // buffer
    unsigned char buf[qnt];
    // transformação em byte
    for (int i = 0; i < qnt; i++) {
        buf[i] = (item >> (i * 8)) & 0xFF;
    }
    //escrita no arquivo byte por byte, 1 byte por vez
    fwrite(buf, 1, qnt, file);
}
//#endregion
//#endregion

//#region BASIC FUNCTIONS
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

//#region STRING SPLITS
//#region ENUM STRING SPLIT TYPE
/**
 * tipo de retorno do split
 */
typedef enum splittype {
    AFTER_SPLIT = 0,
    BEFORE_SPLIT = 1

} splitType;
//#endregion

//#region STRING SPLIT BY INDEX
char *strSplitIndex(char *string, int offset, int end, splitType type) {
    char *ret = calloc(strlen(string) - offset - end + 1,sizeof(char));
    if(type) {
        for (int i = offset; i < strlen(string) - end; i++) {
            ret[i - offset] = string[i];

        }
    } else {
        for(int i = 0; i < offset; i++) {
            ret[i] = string[i];
        }
    }
    ret[strlen(string) - offset - end] = '\0';
    return ret;
}
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
char *strSplitParam(char *string, const char *param, splitType type) {
    // variaveis de controle
    short i = 0,paramSize = 0;
    // string temporária de comparação
    char *tempString = calloc(strlen(param),sizeof(char));
    // execução para encontro do param
    while(i <= strlen(string)) {
        // verifica se a string temporária tem o tamanho do length
        if(paramSize == strlen(param)) {
            if(!strlen(param)) {
                break;
                // verifica se as strings são iguais
            }if(!strcmp(tempString,param)) {
                paramSize = -1;
                break;
                // muda a casa inicial da procura e reinicia o contador da string temporária
            } else {
                paramSize = 0;
                i++;
            }
            // adiciona a casa atual da string na string temporária
        }else {
            tempString[paramSize] = string[i+paramSize];
            paramSize++;
        }
    }
    //libera a string temporária
    free(tempString);
    // cria a string que conterá o split
    char *stringSplit;
    //retorna a string original caso nada tenha sido encontrado
    if(paramSize != -1) {
        return string;
    }
    // verifica o tipo de retorno do split
    if(type) {
        // retorna o que foi encontrado antes do split
        stringSplit = calloc(--i+1,sizeof(char));
        stringSplit[i+2] = '\0';
        for (; i > -1; i--) {
            stringSplit[i] = string[i];
        }
    } else {
        // retorna o que foi encontrado depois do split
        stringSplit = calloc( strlen(string) - (i+=strlen(param))+1, sizeof(char));
        for (int j = 0; j < strlen(string) - i; j++) {
            stringSplit[j] = string[j + i];
        }
        stringSplit[strlen(string) - i] = '\0';
    }
    // retorna o split da string
    return stringSplit;
}
//#endregion

//#region STRING SPLIT BY PARAM N TIMES
/**
 * quebra a string n vezes
 * <h3> <b> NÃO UTILIZA STRING INSERIDA </b> </h3>
 * @param string string a ser quebrada
 * @param param parametro a ser procurado
 * @param runs quantidade de vezes executada
 * @param type tipo do retorno da quebra
 * @return retorna a string n vezes quebrada de acordo com o tipo de retorno
 */
char *strSplitParamT(char *string, const char *param,int runs, splitType type) {
    char *tempString = strdup(string);
    for(int i = 0; i < runs; i++) {
        tempString = strSplitParam(tempString,param,AFTER_SPLIT);
    }
    return type ? strSplitParam(tempString,param,BEFORE_SPLIT) : tempString;
}
//#endregion
//#endregion
//#endregion

int main() {
    //printf("%.*s\n",9,strSplitParamT("Hello, this is a test module for the string splitting."," t",3,AFTER_SPLIT));
    //printf("%f",13);
    //printf("%s\n",strSplitParam("key-type: int",": ",AFTER_SPLIT));
    //char *a = strSplitParam("insert 4, \"Joao Mario\", 15, 324.54"," ",AFTER_SPLIT);
    //for (int i = 0; i < 4; i++) {
        //char *data = strSplitParamT(a, ", ", i, BEFORE_SPLIT);
        //printf("%s\n",data);
    //}

    printf("%g",2.52);
    return 0;
}
