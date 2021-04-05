#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
    DATA_TYPE_STRING = 0,
    DATA_TYPE_KEY = 10,
    DATA_TYPE_VALUE = 11
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
Dictionary addDictionaryEntry(Dictionary *dict, void *key, void *value) {
    dict->entries = realloc(dict->entries, ++dict->size * sizeof(Entry));
    dict->entries[dict->size - 1].key = key;
    dict->entries[dict->size - 1].value = value;
    return *dict;
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
Dictionary createDictionary(dataType keyType, dataType valueType) {
    Dictionary dict = {.keyType = keyType, .valueType = valueType, .size = 0};
    dict.entries = calloc(dict.size, sizeof(Entry));
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
            for (int j = ++i; j < dict->size; j++) {
                dict->entries[j - 1] = dict->entries[j];
            }
        } else if (dict->entries[i].key == key) {
            for (int j = ++i; j < dict->size; j++) {
                dict->entries[j - 1] = dict->entries[j];
            }
        }
    }
    return dict;
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
/**
 * Organiza um dicionário com qsort
 * @param dict dicionário a ser organizado
 * @param type organização por chave ou valor
 * @return dicionário organizado em ordem crescente
 */
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

                //#region DATA TYPE INTEGER/FLOAT
            case DATA_TYPE_FLOAT | DATA_TYPE_INTEGER:
                if (strchr(dict->entries[0].key, ".") == NULL) {
                    qsort(dict->entries, dict->size, sizeof(Entry), compIKey);
                } else {
                    qsort(dict->entries, dict->size, sizeof(Entry), compFKey);
                }
                break;
                //#endregion

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

                //#region DATA TYPE INTEGER/FLOAT
            case DATA_TYPE_FLOAT | DATA_TYPE_INTEGER:
                if (strchr(dict->entries[0].value, ".") == NULL) {
                    qsort(dict->entries, dict->size, sizeof(Entry), compIVal);
                } else {
                    qsort(dict->entries, dict->size, sizeof(Entry), compFVal);
                }
                break;
                //#endregion

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

//#region DB DAT & FIELD
//#region DATA
typedef struct data {
    Entry data;
    int dataSize;
} Data;
//#endregion

//#region FIELD
typedef struct field {
    Data *fieldData;
    Data key;
    int dataSize;
    int fieldSize;
} Field;
//#endregion
//#endregion

//#region FUNCTIONS
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
/**
 * Quebra a string de acordo com offset e end
 * @param string string a ser quebrada
 * @param offset offset de caracteres a partir do início da string
 * @param end offset de caracteres a partir do final da string
 * @param type tipo do retorno da quebra
 * @return string quebrada de acordo com offset e end
 */
char *strSI(char *string, int offset, int end, splitType type) {
    // alocação da memória necessária
    char *ret = calloc(strlen(string) - offset - end + 1, sizeof(char));
    if (type) {
        for (int i = offset; i < strlen(string) - end; i++) {
            ret[i - offset] = string[i];

        }
    } else {
        for (int i = 0; i < offset; i++) {
            ret[i] = string[i];
        }
    }
    // adição de terminador nulo
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
char *strSP(char *string, const char *param, splitType type) {
    // variaveis de controle
    short i = 0, paramSize = 0;
    // string temporária de comparação
    char *tempString = calloc(strlen(param), sizeof(char));
    // execução para encontro do param
    while (i <= strlen(string)) {
        // verifica se a string temporária tem o tamanho do length
        if (paramSize == strlen(param)) {
            if (!strlen(param)) {
                break;
                // verifica se as strings são iguais
            }
            if (!strcmp(tempString, param)) {
                paramSize = -1;
                break;
                // muda a casa inicial da procura e reinicia o contador da string temporária
            } else {
                paramSize = 0;
                i++;
            }
            // adiciona a casa atual da string na string temporária
        } else {
            tempString[paramSize] = string[i + paramSize];
            paramSize++;
        }
    }
    //libera a string temporária
    free(tempString);
    // cria a string que conterá o split
    char *stringSplit;
    //retorna a string original caso nada tenha sido encontrado
    if (paramSize != -1) {
        return strdup(string);
    }
    // verifica o tipo de retorno do split
    if (type) {
        // retorna o que foi encontrado antes do split
        stringSplit = calloc(--i + 1, sizeof(char));
        // adição de terminador nulo
        stringSplit[i + 2] = '\0';
        for (; i > -1; i--) {
            stringSplit[i] = string[i];
        }
    } else {
        // retorna o que foi encontrado depois do split
        stringSplit = calloc(strlen(string) - (i += strlen(param)) + 1, sizeof(char));
        for (int j = 0; j < strlen(string) - i; j++) {
            stringSplit[j] = string[j + i];
        }
        // adição de terminador nulo
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
char *strSPT(char *string, const char *param, int runs, splitType type) {
    char *tempString = strdup(string);
    for (int i = 0; i < runs; i++) {
        tempString = strSP(tempString, param, AFTER_SPLIT);
    }
    return type ? strSP(tempString, param, BEFORE_SPLIT) : tempString;
}
//#endregion
//#endregion
//#endregion

//#region DATA READ & WRITE BINARY FUNCTIONS
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
 * @param item item a ser escrito
 * @param file arquivo a ser escrito
 * @param qnt quantidade de bytes a serem escritos
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

//#region PROJECT UNIQUE FUNCTIONS
//#region DATA SIZE
/**
 * descobre o tamanho do dado do param
 * @param param string que contém nome do tipo do dado
 * @return tamanho do dado em bytes
 */
short dataSize(char *param) {
    if (!strcmp(param, "char")) {
        return DATA_TYPE_CHAR;
    } else if (!strcmp(param, "int")) {
        return DATA_TYPE_INTEGER;
    } else if (!strcmp(param, "float")) {
        return DATA_TYPE_FLOAT;
    } else if (!strcmp(param, "double")) {
        return DATA_TYPE_DOUBLE;
    } else {
        char c = strlen(param) - 6, *num = calloc(c, sizeof(char));
        for (char i = 0; i < c; i++) {
            num[i] = param[i + 5];
        }
        return atoi(num);
    }
}
//#endregion

//#region READ BASE FIELD
/**
 * Leitura do campo base
 * @param file arquivo que contém o campo base
 * @param field estrutura do campo base
 * @return estrutura do campo base preenchida com dados do campo base
 */
Field *readBasefield(FILE *file, Field *field) {
    char dataset = 0;
    while (!feof(file)) {
        // leitura da linha
        char *line = readline(file);

        //#region CASES
        // caso seja key-name
        if (!strcmp(strSP(line, ":", BEFORE_SPLIT), "key-name")) {
            // adiciona a string ao campo referido
            field->key.data.key = strSP(line, ": ", AFTER_SPLIT);
            // caso seja key-type
        } else if (!strcmp(strSP(line, ":", BEFORE_SPLIT), "key-type")) {
            // adiciona a string ao campo referido
            field->key.data.value = strSP(line, ": ", AFTER_SPLIT);
            // obtém o tamanho em bytes do typo
            field->key.dataSize = dataSize(field->key.data.value);
            // adiciona o tamanho ao tamanho total
            field->dataSize += field->key.dataSize;
            // caso seja field-name
        } else if (!strcmp(strSP(line, ":", BEFORE_SPLIT), "field-name")) {
            // adiciona a string ao campo referido
            field->fieldData[field->fieldSize - 1].data.key = strSP(line, ": ", AFTER_SPLIT);
            // caso seja field-type
        } else if (!strcmp(strSP(line, ":", BEFORE_SPLIT), "field-type")) {
            // adiciona a string ao campo referido
            field->fieldData[field->fieldSize - 1].data.value = strSP(line, ": ", AFTER_SPLIT);
            // valor inicial
            field->fieldData[field->fieldSize - 1].dataSize = 0;
            // obtém o tamanho em bytes do typo
            field->fieldData[field->fieldSize - 1].dataSize +=
                    dataSize(field->fieldData[field->fieldSize - 1].data.value);
            // adiciona o tamanho ao tamanho total
            field->dataSize += field->fieldData[field->fieldSize - 1].dataSize;
        }
        //#endregion

        //#region DATASIZE
        // verifica se é necessário aumentar o tamanho do fielddata
        if (++dataset == 2) {
            field->fieldData = realloc(field->fieldData, ++field->fieldSize * sizeof(Data));
            dataset = 0;
        }
        //#endregion

        free(line);
    }
}
//#endregion

//#region WRITE FIELD DATA
/**
 * Escreve um dado da coluna de acordo com seu tipo
 * @param field field base
 * @param data dado a ser escrito
 * @param file arquivo a escrito o dado
 * @param row coluna do field
 */
void fieldDataWrite(Field field, void *data, FILE *file, int row, char *filename) {
    switch (!row ? field.key.dataSize : field.fieldData[--row].dataSize) {
        //#region CASE DATA TYPE CHAR
        case DATA_TYPE_CHAR:
            fprintf(file, "%c,", ((char *) data)[0]);
            break;
            //#endregion

        //#region CASE DATA TYPE INTEGER/FLOAT
        case DATA_TYPE_INTEGER | DATA_TYPE_FLOAT: {
            char *c = strchr(data, '.');
            if (c == NULL) {
                int i = atoi(data);
                fwrite(&i, DATA_TYPE_INTEGER, 1, file);
            } else {
                float f = atof(data);
                fwrite(&f, DATA_TYPE_INTEGER, 1, file);
            }
            free(c);
            break;
        }
            //#endregion

        //#region CASE DATA TYPE DOUBLE
        case DATA_TYPE_DOUBLE: {
            double d = atof(data);
            fwrite(&d, DATA_TYPE_DOUBLE, 1, file);
            break;
        }
            //#endregion

        //#region CASE DATA TYPE STRING
        default:
            if (field.fieldData[row].dataSize > strlen(data)) {
                fwrite(data, DATA_TYPE_CHAR, strlen(data), file);
                for (int i = 0; i < field.fieldData[row].dataSize - strlen(data); i++) {
                    fprintf(file, "%c", 0);
                }
            } else {
                fwrite(data, DATA_TYPE_CHAR, field.fieldData[row].dataSize, file);
            }
            break;
            //#endregion
    }
}
//#endregion

//#region WRITE .IDX FILE
/**
 * Escreve os dados do dicionário no arquivo a ser escrito
 * @param file arquivo a ser escrito
 * @param dict dicionário a ser escrito
 */
void writeIdx(FILE *file, Dictionary dict) {
    // escrita do tipo da chave
    writeLittleEndians(dict.keyType, file, 1);
    // escrita dos valores do dicionário
    for (int i = 0; i < dict.size; i++) {
        // escrita da chave
        switch (dict.keyType) {
            //#region DATA TYPE CHAR
            case DATA_TYPE_CHAR:
                fwrite(dict.entries[i].key, dict.keyType, 1, file);
                break;
                //#endregion

                //#region DATA TYPE INTEGER/FLOAT
            case DATA_TYPE_FLOAT | DATA_TYPE_INTEGER:
                if (strchr(dict.entries[0].key, ".") == NULL) {
                    int i = atoi(dict.entries[i].key);
                    fwrite(&i, dict.keyType, 1, file);
                } else {
                    float f = atof((char *) dict.entries[i].key);
                    fwrite(&f, dict.keyType, 1, file);
                }
                break;
                //#endregion

                //#region DATA TYPE DOUBLE
            case DATA_TYPE_DOUBLE: {
                double d = atof((char *) dict.entries[i].key);
                fwrite(&d, dict.keyType, 1, file);
                break;
            }
                //#endregion

                //#region DATA TYPE STRING
            default:
                if (dict.keyType > strlen(dict.entries[i].key)) {
                    fwrite(dict.entries[i].key, DATA_TYPE_CHAR, strlen(dict.entries[i].key), file);
                    for (int i = 0; i < dict.keyType - strlen(dict.entries[i].key); i++) {
                        fprintf(file, "%c", 0);
                    }
                    fprintf(file, ",");
                } else {
                    fwrite(dict.entries[i].key, DATA_TYPE_CHAR, dict.keyType, file);
                }
                break;
                //#endregion
        }
        // escrita do offset
        fwrite(&dict.entries[i].value, dict.valueType, 1, file);
    }
}
//#endregion

//#region FIND OFFSET
/**
 * Encontra o offset da chave no arquivo idx
 * @param file arquivo a ser lido
 * @param key chave a ser encontrada
 * @return offset encontrado ou -1 caso não encontre algo
 */
int findOffset(FILE *file, void *key) {
    // leitura do tipo da chave
    dataType keyType = readLittleEndians(file, 1);
    while (!feof(file)) {
        // switch de verificação do tipo da chave
        // lê e compara o valor com o do parametro
        // retorna o offset caso encontre
        switch (keyType) {
            //#region DATA TYPE CHAR
            case DATA_TYPE_CHAR: {
                long long keyInternal = readLittleEndians(file, keyType);
                if (keyInternal == ((char *) key)[0]) {
                    return readLittleEndians(file, 4);
                }
                break;
            }
                //#endregion

                //#region DATA TYPE INTEGER/FLOAT
            case DATA_TYPE_FLOAT | DATA_TYPE_INTEGER: {
                long long keyInternal = readLittleEndians(file, keyType);
                if (strchr((char *) key, ".") == NULL && keyInternal == atoi((char *) key)) {
                    return readLittleEndians(file, 4);
                } else if (keyInternal == atof((char *) key)) {
                    return readLittleEndians(file, 4);
                }
                break;
            }
                //#endregion

                //#region DATA TYPE DOUBLE
            case DATA_TYPE_DOUBLE: {
                long long key = readLittleEndians(file, keyType);
                if (key == atof((char *) key)) {
                    return readLittleEndians(file, 4);
                }
                break;
            }
                //#endregion

                //#region DATA TYPE STRING
            default: {
                char *c;
                fread(c, DATA_TYPE_CHAR, keyType, file);
                if (!strcmp(c, (char *) key)) {
                    return readLittleEndians(file, 4);
                }
                free(c);
                break;
            }
                //#endregion
        }
        readLittleEndians(file, 4);
    }
    return -1;
}
//#endregion
//#endregion
//#endregion

int main() {
    //#region VARIABLES & ETC.
    // criação do campo base
    Field field = {.fieldSize = 0, .dataSize = 0, .fieldData = malloc(field.fieldSize * sizeof(Data))};
    // leitura da entrada"
    char *fileName = readline(stdin);
    // abertura do arquivo para escrita
    FILE *file = fopen(fileName, "r+");
    //#endregion

    if (file != NULL) {
        //#region VARIABLES & ETC. 2
        // leitura do nome do arquivo .idx
        char *fileIdxName = strcat(strSP(strSP(readline(file), ": ", AFTER_SPLIT), ".", BEFORE_SPLIT), ".idx");
        // criação do arquivo idx
        FILE *fileIdx;
        // leitura dos campos
        readBasefield(file, &field);
        // criação de dicionário que contém chave e offset
        Dictionary dict = createDictionary((dataType) field.key.dataSize, (dataType) dataSize(field.key.data.value));
        // tamanho original do arquivo
        long datasize = ftell(file);
        //#endregion

        while (1) {
            // leitura da ação
            char *line = readline(stdin), *action = strSP(line, " ", BEFORE_SPLIT);
            if (!strcmp(action, "insert")) {
                //#region INSERT VALUES
                //#region VARIABLES & ETC. 3
                // remoção da ação
                line = strSP(line, " ", AFTER_SPLIT);
                // criação dos valores que contám a chave e o valor da entrada do dicionário
                void *value = (dict.size * field.dataSize), *key;
                //#endregion

                //#region ESCRITA CAMPOS INSERT
                // escrita por campo no arquivo de forma binária
                for (int i = 0; i < field.fieldSize; i++) {
                    // leitura do campo
                    void *data = strSPT(line, ", ", i, BEFORE_SPLIT);
                    // remoção das aspas
                    data = strSP(strSP(data,"\"",AFTER_SPLIT),"\"",BEFORE_SPLIT);
                    // escrita do campo
                    fieldDataWrite(field, data, file, i, fileName);
                    // inserção do primero valor no local que contém a chave do dicionário
                    if (!i) {
                        key = data;
                    }
                }
                //#endregion

                //#region ESCRITA DICIONÁRIO
                dict = addDictionaryEntry(&dict, key, value);
                //#endregion
                //#endregion
            } else if (!strcmp(action, "index")) {
                //#region INDEX SORT & PRINT
                // verificação se há a necessidade da escrita do index
                if (dict.size > 0) {
                    // abre o arquivo .idx para escrita do dicionário
                    fileIdx = fopen(fileIdxName, "wb+");
                    // organiza o dicionário que contém o index
                    dict = sortDictionary(&dict, DATA_TYPE_KEY);
                    // escreve o dicionário no arquivo .idx
                    writeIdx(fileIdx, dict);
                    // fecha o arquivo idx
                    fclose(fileIdx);
                } else {
                    printf("sem dados");
                }
                //#endregion
            } else if (!strcmp(action, "search")) {
                //#region SEARCH FOR KEY
                // verificação se há a necessidade da escrita do index
                if (dict.size > 0) {
                    //#region INDEX
                    // abre o arquivo .idx para escrita do dicionário
                    fileIdx = fopen(fileIdxName, "wb+");
                    // organiza o dicionário que contém o index
                    dict = sortDictionary(&dict, DATA_TYPE_KEY);
                    // escreve o dicionário no arquivo .idx
                    writeIdx(fileIdx, dict);
                    // fecha o arquivo idx
                    fclose(fileIdx);
                    //#endregion

                    //#region SEARCH
                    // volta ao inicio do arquivo e apenas lê ele
                    fileIdx = fopen(fileIdxName, "rb");
                    // remoção da ação
                    int offset = findOffset(fileIdx, strSP(line, " ", AFTER_SPLIT));
                    //verificação da exitencia da chave
                    if (offset > -1) {
                        // setando local de leitura
                        fseek(file, datasize+offset, SEEK_SET);
                        // alloca memória do campo
                        void *data = malloc(field.key.dataSize);
                        // apresentação de que tipo é o dado
                        printf("%s: ", field.key.data.key);
                        // verificação de que tipo é o dado
                        if (!strcmp(field.key.data.value, "char")) {
                            // lê o campo
                            fread(data, field.key.dataSize, 1, file);
                            printf("%c\n", *((char **) &data)[0]);
                        } else if (!strcmp(field.key.data.value, "int")) {
                            // lê o campo
                            data = readLittleEndians(file,field.key.dataSize);
                            printf("%d\n", *((int *) &data));
                        } else if (!strcmp(field.key.data.value, "float")) {
                            float f;
                            // lê o campo
                            fread(&f, field.key.dataSize, 1, file);
                            printf("%g\n", f);
                        } else if (!strcmp(field.key.data.value, "double")) {
                            double d;
                            // lê o campo
                            fread(&d, field.key.dataSize, 1, file);
                            printf("%lg\n", d);
                        } else {
                            // lê o campo
                            fread(data, field.key.dataSize, 1, file);
                            printf("%s\n", *((char **) &data));
                        }
                        // lendo os campos
                        for (int i = 0; i < field.fieldSize - 1; i++) {
                            // alloca memória do campo
                            data = malloc(field.key.dataSize);
                            // apresentação de que tipo é o dado
                            printf("%s: ", field.fieldData[i].data.key);
                            // verificação de que tipo é o dado
                            if (!strcmp(field.fieldData[i].data.value, "char")) {
                                // lê o campo
                                fread(data, field.fieldData[i].dataSize, 1, file);
                                printf("%c\n", *((char **) &data)[0]);
                            } else if (!strcmp(field.fieldData[i].data.value, "int")) {
                                // lê o campo
                                data = readLittleEndians(file,field.fieldData[i].dataSize);
                                printf("%d\n", *((int *) &data));
                            } else if (!strcmp(field.fieldData[i].data.value, "float")) {
                                float f;
                                // lê o campo
                                fread(&f, field.fieldData[i].dataSize, 1, file);
                                printf("%g\n", f);
                            } else if (!strcmp(field.fieldData[i].data.value, "double")) {
                                double d;
                                // lê o campo
                                fread(&d, field.fieldData[i].dataSize, 1, file);
                                printf("%lg\n", d);
                            } else {
                                // lê o campo
                                fread(data, field.fieldData[i].dataSize, 1, file);
                                printf("%s\n", *((char **) &data));
                            }
                        }
                        printf("\n");
                        //libera a data
                        free(data);
                        // retorna ao final do arquivo
                        fseek(file, 0, SEEK_END);
                        // fecha o arquivo .idx
                        fclose(fileIdx);
                    } else {
                        printf("chave não encontrada\n");
                    }
                    //#endregion
                } else {
                    printf("sem dados");
                }
                //#endregion
            } else if (!strcmp(action, "exit")) {
                break;
            }
            free(line);
            free(action);
        }
        fclose(file);
        free(fileIdxName);
    }

    return 0;
}