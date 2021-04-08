#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    long long int numero;
    char * nome;
    struct No *esq, *dir, *pai;
} No;

typedef No * p_no;

// cria uma árvore nula.
p_no criar_arvore(){
    return NULL;
}

void imprimir_arvore(p_no raiz){
    if(raiz != NULL){
        imprimir_arvore(raiz->esq);
        printf("%s\n", raiz->nome);
        imprimir_arvore(raiz->dir);
    }
}

// insere o numero na raíz em questão.
p_no inserir(p_no raiz, long long int numero, char * nome){
    p_no novo;
    if(raiz == NULL){
        novo = malloc(sizeof(No)); // aloca e define os dados.
        novo->pai = NULL; // pai é nulo, e continua sendo se for inserir no primeiro elemento da raiz.
        novo->esq = novo->dir = NULL;
        novo->numero = numero;
        novo->nome = nome;
        return novo;
    }
    if(numero < raiz->numero){
        raiz->esq = inserir(raiz->esq, numero, nome); // chama a inserir na esquerda até chegar na posição nula.
        raiz->esq->pai = raiz; // define o pai da esquerda como a raiz.
    } else {
        raiz->dir = inserir(raiz->dir, numero, nome); // chama a inserir na direita até chegar na posição nula.
        raiz->dir->pai = raiz; // define o pai da direita como a raiz.
    }
    return raiz;
}

p_no minimo(p_no raiz){
    while(raiz != NULL && raiz->esq != NULL){
        printf("1");
        raiz = raiz->esq;
    }
    return raiz;
}

p_no maximo(p_no raiz){
    while(raiz != NULL && raiz->dir != NULL){
        printf("2");
        raiz = raiz->dir;
    }
    return raiz;

}

void remover_sucessor(p_no raiz){
    p_no min = minimo(raiz->dir);
    if(min->pai->esq == min){ // caso em que o minimo não é filho da raiz
        min->pai->esq = min->dir;
        if(min->dir != NULL) // se a direita do minimo nao for nula, define o pai dela como o pai do minimo
            min->dir->pai = min->pai;
    }
    else{ // caso em que o mínimo é filho da raiz
        min->pai->dir = min->dir;
        if(min->dir != NULL) // se a esquerda do minimo nao for nula, define o pai dela como o pai do minimo
            min->dir->pai = min->pai;
    }
    raiz->numero = min->numero; // define os valores da raiz como os do minimo
    free(raiz->nome);
    raiz->nome = min->nome;
    free(min); // libera o minimo

}

// remove e limpa o no em questao da arvore.
p_no remover(p_no raiz, int numero){
    if(raiz == NULL)
        return NULL;
    if(numero < raiz->numero){
        raiz->esq = remover(raiz->esq, numero); // remove na subarvore esquerda se o valor tiver nela.
        if(raiz->esq != NULL) // se houver elementos na raiz esquerda, defino o pai dela como a raiz anterior.
            raiz->esq->pai = raiz;
    } else if(numero > raiz->numero) {
        raiz->dir = remover(raiz->dir, numero); // remove na subarvore direita se o valor tiver nela.
        if(raiz->dir != NULL) // se houver elementos na raiz direita, defino o pai dela como a raiz anterior.
            raiz->dir->pai = raiz;
    } else if(raiz->esq == NULL) { // se o valor for igual ao da raiz e a esquerda for nula,
        p_no aux = raiz->dir;
        free(raiz->nome);
        free(raiz); // libera o nó e o nome;
        return aux; // retorna a raiz direita
    } else if(raiz->dir == NULL) { // se o valor for igual ao da raiz e a direita for nula,
        p_no aux = raiz->esq;
        free(raiz->nome);
        free(raiz); // libera o nó e o nome
        return aux; // retorna a raiz esquerda
    } else { // se o valor for o mesmo e nem a direita nem a esquerda for nula, remove o sucessor e troca os valores do sucessor pela raiz;
        remover_sucessor(raiz);
    }
    return raiz;
}


// busca o numero em questão na árvore.
p_no buscar(p_no raiz, int numero){
    while(raiz != NULL && numero != raiz->numero){
        printf("3");
        if(numero < raiz->numero)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    return raiz;
}


p_no ancestral_a_direita(p_no x) {
    if (x == NULL)
        return NULL;
    if (x->pai == NULL || x->pai->esq == x) // retorna o pai se o filho da esquerda do pai for o próprio x.
        return x->pai;
    else
        return ancestral_a_direita(x->pai); // se não, continua a recursão com o pai.
    
}

p_no ancestral_a_esquerda(p_no x) {
    if(x->numero == 389356){
            printf("é aqui 1");
    }
    if (x == NULL){
        printf("é aqui 2");
        return NULL;
    }
    if (x->pai == NULL || x->pai->dir == x){ // retorna o pai se o filho da direita do pai for o próprio x.
        printf("é aqui 3");
        return x->pai;
    }
    else{
        printf("é aqui 4");
        printf("%s %lld REPETINDO", x->nome, x->numero);
        return ancestral_a_esquerda(x->pai); // se não, continua a recursão com o pai.
    }
}

// acha o próximo nó da sequência.
p_no sucessor(p_no x){
    if (x->dir != NULL)
        return minimo(x->dir); // se houver nós a direita, o minimo desses nós vai ser o sucessor.
    else
        return ancestral_a_direita(x); // se não, o sucessor vai ser o ancestral a direita.
}



// acha o nó anterior da sequência.
p_no antecessor(p_no x){
    if (x->esq != NULL){  
        return maximo(x->esq); // se houver nós a esquerda, o maximo desses nós vai ser o antecessor.
    } else{
        return ancestral_a_esquerda(x); // se não, o antecessor vai ser o ancestral a esquerda.
    }
}


p_no buscar_concatenar_triade_r(p_no raiz, long long int valor, long long int mensageiro, int ordem, char ** string){
    if(ordem == 3){
        printf("foi pra ordem 3");
        p_no atual = maximo(raiz);
        int i, j;
        while(atual != NULL){ // circula pelos nós restantes
            printf("4");
            if((valor + atual->numero) == mensageiro){ // até achar um em que a soma dê o valor do mensageiro
                printf("ENCONTREI UM CORNO");
                char * string_nova = malloc((strlen(*string) + strlen(atual->nome) + 1)*sizeof(char)); // copia a concatenação da string antiga e a atual para um novo malloc
                for(i = 0; atual->nome[i] != '\0'; i++){
                    string_nova[i] = atual->nome[i];
                }
                for(j = 0; (*string)[j] != '\0'; j++){
                    string_nova[i+j] = (*string)[j];
                }
                string_nova[i+j] = '\0';
                

                raiz = remover(raiz, atual->numero); // remove o ultimo nó da raiz
                raiz = inserir(raiz, mensageiro, string_nova); // adiciona o nó concatenado e devolve
                
                free(*string); // libera a string antiga
                return raiz;
            }
            printf("\n %s %lld \n", atual->nome, atual->numero);
            atual = antecessor(atual);
        }
    }
    else {
        p_no atual = maximo(raiz), resultado, aux = criar_arvore();
        char * nome;
        char * string_anterior = NULL;
        char * string_nova = NULL;
        int i, j;
        while(atual != NULL){
            printf("5");
            if(atual->numero < mensageiro){
                nome = malloc((strlen(atual->nome)+1)*sizeof(char)); // cria um novo nome para a auxiliar
                for(i = 0; atual->nome[i] != '\0'; i++){ // copia o nome para o novo nome da auxiliar
                    nome[i] = atual->nome[i];
                }
                nome[i] = atual->nome[i];

                aux = inserir(aux, atual->numero, nome); // cria uma auxiliar com os dados do atual
                

                if(*string != NULL){
                    string_anterior = malloc((strlen(*string)+1)*sizeof(char)); // copia a string atual para a anterior, caso o backtracking dê errado.
                    for(i = 0; (*string)[i] != '\0'; i++){
                        string_anterior[i] = (*string)[i];
                    }
                    string_anterior[i] = '\0';
                    string_nova = malloc((strlen(*string) + strlen(atual->nome) + 1)*sizeof(char)); // copia a concatenação da string antiga e a atual para um novo malloc
                    for(i = 0; atual->nome[i] != '\0'; i++){
                        string_nova[i] = atual->nome[i];
                    }
                    for(j = 0; (*string)[j] != '\0'; j++){
                        string_nova[i+j] = (*string)[j];
                    }
                    string_nova[i+j] = '\0';
                    
                    free(*string); // libera a string antiga
                    *string = string_nova; // associa a string à string nova, para ser usada na recursão.

                }
                else{
                    string_nova = malloc((strlen(atual->nome) + 1)*sizeof(char)); // copia a concatenação da string antiga e a atual para um novo malloc
                    for(j = 0; atual->nome[j] != '\0'; j++){
                        string_nova[j] = atual->nome[j];
                    }
                    string_nova[j] = '\0';
                    *string = string_nova; // associa a string à string nova, para ser usada na recursão.
                }
                
                raiz = remover(raiz, atual->numero); // remove da arvore para fazer o backtracking
                resultado = buscar_concatenar_triade_r(raiz, valor+aux->numero, mensageiro, ordem+1, string); // executa o backtracking, continua se não for nulo, tenta novamente se for;

                if(resultado != NULL){ // retorna o nó se a função não retornar nulo, tenta novamente se for;
                    aux = remover(aux, aux->numero); // remove e limpa o auxiliar
                    if(string_anterior != NULL){
                        free(string_anterior); // libera a string anterior, já que a nova já foi liberada pela ordem 3;
                    }
                    return resultado;
                }
                free(*string); // limpa a string concatenada que não deu certo
                *string = string_anterior; // define a string como a anterior novamente, para continuar no backtracking.


                nome = malloc((strlen(aux->nome) + 1)*sizeof(char)); // cria um novo nome para a atual
                for(i = 0; aux->nome[i] != '\0'; i++){ // copia o nome para o novo nome da atual
                    nome[i] = aux->nome[i];
                }
                nome[i] = aux->nome[i];

                raiz = inserir(raiz, aux->numero, nome); // insere os dados da aux novamente na raiz para continuar o backtracking
                atual = buscar(raiz, aux->numero); // associa atual ao valor dentro da raiz novamente.
                aux = remover(aux, aux->numero); // remove os dados da aux.
            }
            atual = antecessor(atual);
        }
    }
    return NULL; // se não existir, vai retornar NULL.
}


// busca a tríade que coincide com o valor do mensageiro e depois concatena. Devolve a raíz da árvore com o cartão concatenado.
p_no buscar_concatenar_triade(p_no raiz, long long int mensageiro){
    int ordem = 1;
    char * string = NULL;
    return buscar_concatenar_triade_r(raiz, 0, mensageiro, ordem, &string); // chama a funçao recursiva com a ordem = 1.

}


// retorna a árvore após a leitura dos nós.
p_no le_mensagens(p_no raiz, int m){
    char * nome;
    long long int numero;
    for(int i = 0; i < m; i++){
        nome = malloc(6 * sizeof(char));
        scanf("%lld %*c%[^\"]%*c ", &numero, nome);
        raiz = inserir(raiz, numero, nome);
    }
    return raiz;
}

// imprime a arvore restante em ordem crescente e limpa-a.
void imprime_limpa_arvore(p_no raiz){
    p_no atual;
    while (raiz != NULL){
        printf("6");
        atual = minimo(raiz);
        printf("%s", atual->nome);
        raiz = remover(raiz, atual->numero);
    }
    printf("\n");
}

int main(){
    int m, n;
    long long int mensageiro;
    p_no arvore;
    while(scanf("%d %d\n", &m, &n) != EOF){ // enquanto a leitura de m e n não chegar no final do arquivo, execute:
        printf("7");
        arvore = criar_arvore();
        arvore = le_mensagens(arvore, m);
        for(int i = 0; i < n; i++){ // lê os mensageiros um por um e vai executando as buscas e concatenações de tríades.
            scanf("%lld ", &mensageiro);
            arvore = buscar_concatenar_triade(arvore, mensageiro);
        }
        imprime_limpa_arvore(arvore); // imprime a árvore restante e limpa tudo.
    }
}
