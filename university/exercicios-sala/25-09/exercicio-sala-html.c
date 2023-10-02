#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 1000

void limparLinha(char *linha, char *novaLinha) {
    int esta_dentro_tag = 0, j = 0;

    for(int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            esta_dentro_tag = 1;
        } else if (linha[i] == '>') {
            esta_dentro_tag = 0;
        } else if (!esta_dentro_tag) {
            novaLinha[j++] = linha[i];
        }
    }
    novaLinha[j] = '\0';
}

int main() {
    FILE *entrada, *saida;
    char novaLinha[MAX_LINHA] = "";

    entrada = fopen("teste.html", "r");
    saida = fopen("saida.txt", "w");

    if (entrada == NULL || saida == NULL ) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    char linha[MAX_LINHA];

    while (fgets(linha, sizeof(linha), entrada)) {
        limparLinha(linha, novaLinha);
        fprintf(saida, "%s", novaLinha);
        novaLinha[0] = '\0';
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}

