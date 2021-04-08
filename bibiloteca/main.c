#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char *name;
    int days;
    int rented;
    int rentedTime;
} Book;

typedef struct library {
    Book *books;
    int qntBooks;
    int rentSum;
} Library;

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

//#region RENT BOOK
/**
 * Função para ver se exite o livro na biblioteca
 * @param bookName nome do livro
 * @param library bibiloteca inserida
 * @return string de resultado da procura
 */
char *rentBook(char *bookName, Library *library) {
    // verifica se o usuário pode ou não alugar livros
    if(library->rentSum > 9) {
        printf("Voce ja tem 10 livros alugados\n");
    } else {
        for (int i = 0; i < library->qntBooks; i++) {
            // verifica o nome pesquisado e o nome do livro
            if (strcmp(library->books[i].name, bookName) == 0) {
                // verifica se já foi alugado
                if (library->books[i].rented == 0) {
                    // marca o livro como alugado
                    library->books[i].rented = 1;
                    // marca o valor do aluguel e aumenta a quantidade de livros alugados
                    library->books[i].rentedTime = ++library->rentSum;
                    // faz a mudança do livro i para o livro mais recente segundo ordem de aluguel
                    Book placehoder = library->books[library->rentSum - 1];
                    library->books[library->rentSum - 1] = library->books[i];
                    library->books[i] = placehoder;
                    // escreve o nome do livro
                    printf(bookName);
                    // libera o espaço do livro e retorna string
                    free(bookName);
                    return " alugado com sucesso\n";
                } else {
                    // libera o espaço do livro e retorna string
                    free(bookName);
                    return "Livro ja alugado\n";
                }
            }
        }
    }
    // caso não encontre o livro
    // libera o espaço do livro e retorna string
    free(bookName);
    return "Livro nao encontrado na biblioteca\n";
}
//#endregion

//#region SEARCH BOOK
/**
 * Função para procura de livros
 * @param library biblioteca inserida
 */
void searchBooks(Library *library) {
    // verifica se há livros alugados
    if(library->rentSum == 0) {
        printf("Voce nao tem livros alugados\n");
    } else {
        // apresenta quantos livros alugados há
        printf("Voce tem %d livros alugados\n",library->rentSum);
        for(int j = 0; j < library->rentSum; j++) {
            // apresenta o livro e su "data" de devolução
            printf("Livro nome: %s\n",library->books[j].name);
            printf("Devolve-lo daqui %d dias\n",library->books[j].days);
        }
    }
}
//#endregion

//#region RETURN BOOK
/**
 * procura o livro a ser retornado
 * @param bookName nome do livro
 * @param library bibiloteca inserida
 * @return string de resultado da devolução
 */
char *returnBook(char *bookName, Library *library) {
    for(int i = 0; i < library->qntBooks; i++) {
        // verifica nome do livro e se está alugado
        if(strcmp(library->books[i].name,bookName) == 0 && library->books[i].rented == 1) {
            // reseta o estado de aluguel do livro
            library->books[i].rented = 0;
            library->books[i].rentedTime = 0;
            // decrementa a soma do livro
            --library->rentSum;
            // escreve o nome do livro
            printf(bookName);
            // libera o espaço do livro e retorna string
            free(bookName);
            return " foi devolvido com sucesso\n";
        }
    }
    // libera o espaço do livro e retorna string
    free(bookName);
    return "Voce nao possui esse livro\n";
}
//#endregion

int main() {
    //#region VARIABLES & ETC.
    Library library = {
            .qntBooks = strtol(readline(stdin), NULL, 10),
            .books = calloc(library.qntBooks,sizeof(Book)),
            .rentSum = 0
    };
    //#endregion

    // alocação de valores da biblioteca com base na entrada
    for(int i = 0; i < library.qntBooks; i++) {
        library.books[i].name = readline(stdin);
        library.books[i].days = strtol(readline(stdin), NULL, 10);
        library.books[i].rented = 0;
        library.books[i].rentedTime = 0;
    }

    while (1) {
        switch (readline(stdin)[0]) {
            case '1':
                printf("Digite o livro que voce procura:\n");
                printf(rentBook(readline(stdin),&library));
                break;
            case '2':
                searchBooks(&library);
                break;
            case '3':
                printf("Digite o livro que deseja devolver:\n");
                printf(returnBook(readline(stdin),&library));
                break;
            case '4':
                printf("Programa finalizado\n");
                for(int i = 0; i < library.qntBooks; i++) {
                    free(library.books[i].name);
                }
                free(library.books);
                return 0;
        }
    }
}
