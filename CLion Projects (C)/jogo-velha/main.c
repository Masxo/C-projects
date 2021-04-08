#include <stdio.h>
#include <stdlib.h>

#define rows 3
#define collumns 3

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

// Apresenta a matriz do jogo
void show(char **mat) {
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < collumns; j++) {
            // Verifica se o indice já foi jogado
            if(mat[i][j] == 'X' || mat[i][j] == 'O') {
                printf("%c   |",mat[i][j]);
            } else {
                printf("%i   |", i * 3 + j + 1);
            }
        }
        printf("\n----+----+----\n");
    }
}

// Recebe a entrada
void getInput(char **mat, int rounds) {
    // String q recebe a entrada
    char *ent;

    readInput:
    // Recebe a entrada
    ent = readline(stdin);
    for(int j = 0; j < rows; j++) {
        for(int k = 0; k < collumns; k++) {
            // Verifica se é o indice jogado
            if(j * 3 + k + 1 == strtol(ent,NULL,10)) {
                // Verifica se o indice já foi jogado
                if(mat[j][k] == 'X' || mat[j][k] == 'O') {
                    printf("Jogada inválida! Escolha outra casa.\n");
                    goto readInput;
                    // Verifica qual jogador é a vez
                } else if(rounds % 2 == 0) {
                    mat[j][k] = 'O';
                } else {
                    mat[j][k] = 'X';
                }
            }
        }
    }
    free(ent);
}

// Verifica se ocorreu uma vitória
char isWin(char **mat) {
    // Verifica se a linha contém o mesmo caractére
    for(int i = 0; i < rows; i++) {
        if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) {
            return mat[i][0];
        }
    }
    // Verifica se a coluna contém o mesmo caractére
    for(int i = 0; i < collumns; i++) {
        if(mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]) {
            return mat[0][i];
        }
    }

    // Verifica se a diagonal contém o mesmo caractére
    if(mat[0][0] == mat[1][1] && mat[2][2] == mat[1][1]) {
        return mat[0][0];
    } else if(mat[0][2] == mat[1][1] && mat[2][0] == mat[1][1]) {
        return mat[0][2];
        // Caso não ocorreu vitória retorna caractére \n
    } else {
        return '\n';
    }
}

// Executa cada rodada de jogo
int playRounds(char **mat) {
    // Quantidade de jogadas possíveis
    for(int i = 1; i < 10; i++) {
        // Verifica qual jogador é a vez
        if(i % 2 != 0) {
            printf("Escolha um número para jogar, jogador X!\n");
        } else {
            printf("Escolha um número para jogar, jogador O!\n");
        }
        // Realiza a leitura da input
        getInput(mat,i);
        // Apresenta o estado do jogo
        show(mat);
        // Verificação para não verificar o fim de jogo
        // pois o mínimo de jogads para um fim de jogo é 5
        if (i > 4) {
            // Executa a verificação da vitória, caso não exista
            // continua para o próximo turno
            switch(isWin(mat)) {
                case 'X':
                    return 0;
                    break;
                case 'O':
                    return 1;
                    break;
                default:
                    break;
            }
            // Verifica se é a ultima jogada
            // como está após a verificação de vitória,
            // apenas há o caso de velha (empate)
            if(i == 9) {
                return 2;
            }
        }
    }
}

int main() {
    // Criação e inicialização da matriz do jogo da velha
    char **mat = calloc(rows,sizeof(char *));
    for(int i = 0; i < rows; i++) {
        mat[i] = calloc(collumns,sizeof(char));
    }

    // Primeira apresentação
    show(mat);

    printf("Jogo da Velha!\n");

    // Executa o jogo, quando obtido a resposta de acordo com o caso
    // demonstra a resposta
    switch(playRounds(mat)) {
        case 0:
            printf("Fim do jogo! O jogador X venceu!\n");
            break;
        case 1:
            printf("Fim do jogo! O jogador O venceu!\n");
            break;
        case 2:
            printf("Deu velha!\n");
            break;
    }

    // Libera a memória associada a matriz
    free(mat);

    return 0;
}

