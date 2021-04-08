#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

//#region CSV HEADER
//#region CSV HEADER
//header de um csv
typedef struct csvHeader {
    // qunatidade de itens de um csv
    short qnt;
    // headers do csv
    char **headers;
} CSVHeader;
//#endregion

//#region SHOW CSV HEADERS
/**
 * funçãopara apresentar os headers de um csv
 * @param header header a ser apresentado
 */
void showCSVHeaders(CSVHeader header) {
    printf("-------------------------------------------\n");
    for(char j = 0; j < header.qnt; j++) {
        printf("header %d: %s\n",j+1,header.headers[j]);
    }
    printf("-------------------------------------------\n");
    printf("digite o header ou o numero dele como base a ser ordenado:\n");
}
//#endregion

//#region GET CSV HEADERS
/**
 * lê, apresenta os headers de um arquivo csv
 * @param file aquivo a ser lido
 * @return retorna um array de strings com os headers
 */
CSVHeader getCSVHeaders(FILE *file) {
    // criando struct
    CSVHeader CSVHeaders;
    // iterador da quantidade de headers
    CSVHeaders.qnt = 0;
    // array de strings para conter as string do header
    // depois o executa a leitura da primeira linha e separa por ","
    CSVHeaders.headers = calloc(1, sizeof(char *));
    char *line = readline(file), *read =  strtok(line,",");
    // leitura, realocamento de memória e inserção do header
    while(read != NULL) {
        // realoca o array para conter o tamanho correto
        CSVHeaders.headers = realloc(CSVHeaders.headers,++CSVHeaders.qnt * sizeof(char *));
        CSVHeaders.headers[CSVHeaders.qnt-1] = calloc(strlen(read)+1,sizeof(char));
        // insere o header no array
        strcpy(CSVHeaders.headers[CSVHeaders.qnt-1],read);
        // lê o próximo header
        read = strtok(NULL,",");
    }
    free(line);
    // apresenta a quantidade de headers
    printf("encontrado %d headers\n",CSVHeaders.qnt);
    // apresenta os headers
    showCSVHeaders(CSVHeaders);
    // retorna o header lido
    return CSVHeaders;
}
//#endregion
//#endregion

//#region CONTAINS
//#region WORD CONTAINS NUMBERS
/**
 * verifica se string contém números
 * @param string string a ser verificada
 * @return 0 caso não contenha números, 1 caso contenha
 */
char containNumbers(char *string) {
    for(short i = 0; i < strlen(string); i++) {
        if(isdigit(string[i])) {
            return 1;
        }
    }
    return 0;
}
//#endregion

//#region CONTAINS STRING
/**
 * verifica se string é contida no array de strings
 * @param array array de strings
 * @param item string a ser procurada
 * @param arraysize tamanho do array
 * @return 1 quando encontrada, 0 caso não encontrada
 */
char containsString(char **array, char *item, int arraysize) {
    for(--arraysize; arraysize > -1; arraysize--) {
        if(!strcmp(array[arraysize],item)) {
            return 1;
        }
    }
    return 0;
}
//#endregion
//#endregion

//#region SORTS
//#region SORT BY NUMBER

//#endregion

//#endregion

//#region CMP
// comparador para qsort
int cmp(const void *a,const void *b){
    return strcmp(*(char**)a, *(char**)b);
}
//#endregion

int main() {
    //#region ENTRADA
    // nome do arquivo, extensão
    char *filename  = "samplecsv20k.csv", *rest = strrchr(filename,'.');
    //#endregion

    // Verifica se estensão é do tipo BMP
    if(!strcasecmp(rest,".csv")) {
        // Abre o arquivo para leitura com nome baseado na entrada
        FILE *file = fopen(filename, "r");
        // verifica se existe arquivo
        if (file != NULL) {
            //#region VARIABLES & ETC.
            // criação do CSV header
            CSVHeader headers = getCSVHeaders(file);
            // leitura do indice do header
            // (void *) permite ser string ou número caso necessário
            void *indice = (void *) 3;
            //#endregion

            /*//#region VERIFICAÇÃO DA ENTRADA
            while(1) {
                // leitura do indice a ser ordenado
                indice = (char *) readline(stdin);
                // verifica se entrada contém número
                if (containNumbers(indice)) {
                    // transforma indice para número
                    indice = (long *) atol(indice);
                    // verifica se indice está contido dentro da qunatidade de headers
                    if(headers.qnt >= (long) indice &&  (long) indice > 0) {
                        break;
                    } else {
                        printf("digite um valor contido entre 1 e %d ou um header contido!\n",headers.qnt);
                        showCSVHeaders(headers);
                    }
                } else {
                    // verifica se header está contido nos valores possíveis do array de headers
                    if(containsString(headers.headers,indice,headers.qnt)) {
                        break;
                    } else {
                        printf("digite um valor contido entre 1 e %d ou um header contido!\n",headers.qnt);
                        showCSVHeaders(headers);
                    }
                }
            }
            //#endregion*/

            //#region SORT POR INDICE
            short count = 0;
            char **lines = calloc(count,sizeof(char *));
            while(!feof(file)) {
            //for(int i = 0; i < 2; i++) {
                lines = realloc(lines, ++count * sizeof(char *));
                //#region LEITURA POR INDICE
                // leitura da linha e quebra por ','
                char *line = readline(file);/*, *format = strtok(line, ",");
                // limpa a linha
                line = calloc(1 + strlen(format), sizeof(char));
                // leitura dos itens e colocação do indice selecioando como primeiro
                for (short i = 0; i < headers.qnt; i++) {
                    // alocação de memória para strcpy e strcat
                    char *temp = calloc(1 + strlen(format), sizeof(char));
                    // copia as strings
                    strcpy(temp, format);
                    // verifica se é o indice selecionado
                    if (!(indice - i - 1)) {
                        // apendicia o item que tem indice selecionado ano começo da linha
                        line = strcat(strcat(temp, (!i ? "" : ",")), line);
                    } else {
                        // apendicia o item no final da linha
                        line = strcat(strcat(line, !i ? "" : ","), temp);
                    }
                    // lê o próximo item
                    format = strtok(NULL, ",");
                    free(temp);
                }
                //#endregion */
                printf("%s\n",line);
                lines[count-1] = line;
            }
            //#endregion

            qsort(lines,count,sizeof(lines),cmp);

            printf("\n");
            /*//#region ORGANIZAÇÃO POR INDICE
            for(int j = 0; j < count; j++) {
                // leitura da linha e quebra por ',' ,armazenando o valor usado como sort nela
                char *line = lines[j], *string = strtok(line, ",");
                // limpa a linha
                line = calloc(1, sizeof(char));
                // leitura dos itens e colocação do indice selecioando como primeiro
                for (short i = 0; i < headers.qnt - 1; i++) {
                    // lê o próximo item
                    char *format = strtok(NULL, ",");
                    // alocação de memória para strcpy e strcat
                    char *temp = calloc(1 + strlen(format), sizeof(char));
                    // copia as strings
                    strcpy(temp, format);
                    // verifica se é o indice selecionado
                    if (!(indice - i - 1)) {
                        // apendicia o item que tem indice selecionado na localização original dele
                        line = strcat(strcat(line, (!i ? "" : ",")), string);
                    }
                    // apendicia o item no final da linha
                    line = strcat(strcat(line, !i ? "" : ","), temp);
                }
                lines[j] = line;
                printf("%s\n",lines[j]);
            }
            //#endregion*/

            // fecha o arquivo
            fclose(file);
        } else {
            printf("Erro no arquivo ou arquivo danificado.\n");
        }
    } else {
        printf("Arquivo contém extensão incorreta.\n");
    }
    return 0;
}
