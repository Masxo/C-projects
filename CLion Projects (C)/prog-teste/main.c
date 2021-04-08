#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *readline(FILE *file) {
    char *string = 0;
    int pos = 0;
    do {
        string = (char *) realloc(string,(pos + 1)*sizeof(char));
        string[pos] = (char) fgetc(file);
        string[pos] = (string[pos]=='$')?'\n':string[pos];
    } while ((string[pos++] != '\n') && !feof(file));
    string[--pos] = '\0';
    return string;
}
char *substring(const char *string,int init,int end){
    char *storage = calloc(end - init + 1,sizeof(char));
    for (int i = 0; i <= end - init; ++i) {
        storage[i] = string[i + init];
    }
    return storage;
}
char ** surname(char *name){//gera uma matriz de char com a seguintes informacoes:
    // retorno[1] e` o nome sem o sobrenome
    // retorno[0] e` o sobrenome removido
    char **storage = calloc(2,sizeof(char *));
    int lastSpace = 0;
    int i;
    for(i = 0; name[i]!='\0';i++){
        if(name[i] == ' ')
            lastSpace = i;
    }
    storage[0] = substring(name,lastSpace,i+1);
    storage[1] = realloc(name, lastSpace+1);
    return storage;
}
int main() {
    char **names = calloc(1,sizeof(char));
    int i;
    for (i = 0;!feof(stdin);i++){//coleta todos os nomes
        names = (i != 0)?realloc(names,(i + 1) * sizeof(char)):names;
        names[i] = calloc(1,sizeof(char));
        names[i] = readline(stdin);
    }
    for(int j = 0; j < i; j++){//Este for faz a troca dos sobrenomes
        char *name1,*name2;
        strcpy(name1,names[j]);
        strcpy(name2,names[i-j]);
        char **infos1,**infos2;
        infos1 = surname(name1);
        infos2 = surname(name2);
        infos1[1] = realloc(infos1[1],(strlen(infos1[1])+strlen(infos2[0]))*sizeof(char));
        infos2[1] = realloc(infos2[1],(strlen(infos2[1])+strlen(infos1[0]))*sizeof(char));
        strcat(infos1[1],infos2[2]);
        strcat(infos2[1],infos1[2]);
        names[j] = infos1[1];
        names[i-j] = infos2[1];
    }
    for(int j = 0; j < i; j++){
        printf("%s\n",names[j]);
    }
}

