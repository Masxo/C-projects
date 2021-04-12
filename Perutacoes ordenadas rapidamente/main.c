#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// qsort comparator
int comp(const void *a, const void *b) {
    return (*(char *) a - *(char *) b);
}

//troca as variaveis
void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

// encontra o indice do segundo maior caractere
int findsecondchar(char arr[], char firstchar, int pos, int max) {
    int index = pos;
    for (int i = pos + 1; i <= max; i++) {
        // verifica se o caractere é maior que o primeiro e menor que o resto
        if (arr[i] > firstchar && arr[i] < arr[index])
            index = i;
    }
    return index;
}

// printer em ordem lexicográfica
void printlex(char arr[], int max) {
    int pos = 1;
    while (pos > -1) {
        // apresenta a palavra
        printf("%s\n", arr);
        // encontra o menor caractere se estiver em ordem lexicográfica
        for (pos = max - 2; pos > -1; pos--)
            if (arr[pos] < arr[pos + 1]) break;
        if (pos == -1) break;
        // encontra o indice do segundo menor caractere
        int index = findsecondchar(arr, arr[pos], pos + 1, max - 1);
        // troca o primeiro e o segundo caractere de lugar
        swap(&arr[pos], &arr[index]);
        // inverte o resto da string
        qsort(arr + pos + 1, max - pos  - 1, sizeof(arr[0]),comp);
    }
}


int main() {
    // leitura 1
    char str[10];
    int num;
    scanf("%d", &num);
    for (char c = 0; c < num; c++) {
        //leituras restantes
        scanf("%s", str);
        // vê tamanho da palavra
        int i = strlen(str);
        // ordena as letras
        qsort(str, i, sizeof(char), comp);
        // escreve lexicográficamente
        printlex(str, i);
        // escreve linha extra
        printf("\n");
    }
    return 0;
}