#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int chave;
    // Outros componentes
    struct Item *proximo; // Próximo elemento da lista
} Item;

typedef struct Lista {
    Item *cabeca;
    int tamanho;
} Lista;

void exibirLista(Lista *lista) {
    printf("Lista: ");
    Item *atual = lista->cabeca;

    while(atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

float calcularMedia(Lista* lista) {
    if (lista->tamanho == 0) {
        printf("Erro: Lista está vazia. Não foi possível calcular a média!\n");
        return 0.0;
    }

    Item* atual = lista->cabeca;
    int total = 0;

    while (atual != NULL) {
        total += atual->chave;
        atual = atual->proximo;
    }

    return (float) total / lista->tamanho;
}

Lista *criarListaVazia() {
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));

    if (novaLista == NULL) {
        printf("Erro ao alocar memória para lista. \n");
        exit(1);
    }

    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

void inserirNaPosicao(Lista *lista, int posicao, Item *item)
{
    if (posicao < 0 || posicao > lista->tamanho)
    {
        printf("Posição inválida para inserção.\n");
        return;
    }
    if (posicao == 0)
    {
        // Inserir na primeira posição
        item->proximo = lista->cabeca;
        lista->cabeca = item;
    }
    else
    {
        // Encontrar o nó na posição anterior
        Item *anterior = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++)
        {
            anterior = anterior->proximo;
        }
        item->proximo = anterior->proximo;
        anterior->proximo = item;
    }
    lista->tamanho++;
}

int main() {
    Lista *X = criarListaVazia();

    Item *I1 = (Item *) malloc(sizeof(Item));
    I1->chave = 10;
    Item *I2 = (Item *) malloc(sizeof(Item));
    I2->chave = 20;
    Item *I3 = (Item *) malloc(sizeof(Item));
    I3->chave = 30;

    inserirNaPosicao(X, 0, I1);
    inserirNaPosicao(X, 0, I2);
    inserirNaPosicao(X, 0, I3);

    printf("Media: %.2f\n", calcularMedia(X));

    printf("Tamanho: %d\n", X->tamanho);
    exibirLista(X);

    return 0;
}