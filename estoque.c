#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int quantidade;
} produto;

typedef struct {
    char localizacao[10];
    produto Produto_armazenado;
} prateleira;

typedef struct {
    prateleira Superior_Esquerda;
    prateleira Inferior_Esquerda;
    prateleira Superior_Direita;
    prateleira Inferior_Direita;
} corredor;

typedef struct {
    corredor corredor_A;
    corredor corredor_B;
    corredor corredor_C;
    corredor corredor_D;
    corredor corredor_E;
    corredor corredor_F;
    corredor corredor_G;
} Mercado;

void exibirLocalizacoes(Mercado estoque) {
    // Função para exibir todas as localizações do mercado
    corredor corredores[7] = {
        estoque.corredor_A, estoque.corredor_B, estoque.corredor_C,
        estoque.corredor_D, estoque.corredor_E, estoque.corredor_F,
        estoque.corredor_G
    };

    char nomes_corredores[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    for (int i = 0; i < 7; i++) {
        printf("Corredor %c:\n", nomes_corredores[i]);

        printf("  Superior Direita: %s | Produto: %s | Quantidade: %d\n",
               corredores[i].Superior_Direita.localizacao,
               corredores[i].Superior_Direita.Produto_armazenado.nome,
               corredores[i].Superior_Direita.Produto_armazenado.quantidade);

        printf("  Inferior Direita: %s | Produto: %s | Quantidade: %d\n",
               corredores[i].Inferior_Direita.localizacao,
               corredores[i].Inferior_Direita.Produto_armazenado.nome,
               corredores[i].Inferior_Direita.Produto_armazenado.quantidade);

        printf("  Superior Esquerda: %s | Produto: %s | Quantidade: %d\n",
               corredores[i].Superior_Esquerda.localizacao,
               corredores[i].Superior_Esquerda.Produto_armazenado.nome,
               corredores[i].Superior_Esquerda.Produto_armazenado.quantidade);

        printf("  Inferior Esquerda: %s | Produto: %s | Quantidade: %d\n",
               corredores[i].Inferior_Esquerda.localizacao,
               corredores[i].Inferior_Esquerda.Produto_armazenado.nome,
               corredores[i].Inferior_Esquerda.Produto_armazenado.quantidade);
    }
}

int main() {
    produto Produto_inicial;
    Produto_inicial.quantidade = 0;
    strcpy(Produto_inicial.nome, "Nulo");

    prateleira Prateleira_Inicial;
    strcpy(Prateleira_Inicial.localizacao, "00");
    Prateleira_Inicial.Produto_armazenado = Produto_inicial;

    corredor corredor_inicial;
    Mercado estoque;

    char Letras[7] = "ABCDEFG";

    for (int i = 0; i < 7; i++) {
        for (int a = 0; a < 4; a++) {
            char numero_loque = (a+1) + '0'; // Converte o índice para caractere
            Prateleira_Inicial.localizacao[0] = Letras[i];
            Prateleira_Inicial.localizacao[1] = numero_loque;
            Prateleira_Inicial.localizacao[2] = '\0'; // Garante que a string seja válida

            if (a == 0) corredor_inicial.Superior_Direita = Prateleira_Inicial;
            if (a == 1) corredor_inicial.Inferior_Direita = Prateleira_Inicial;
            if (a == 2) corredor_inicial.Superior_Esquerda = Prateleira_Inicial;
            if (a == 3) corredor_inicial.Inferior_Esquerda = Prateleira_Inicial;
        }

        if (i == 0) estoque.corredor_A = corredor_inicial;
        if (i == 1) estoque.corredor_B = corredor_inicial;
        if (i == 2) estoque.corredor_C = corredor_inicial;
        if (i == 3) estoque.corredor_D = corredor_inicial;
        if (i == 4) estoque.corredor_E = corredor_inicial;
        if (i == 5) estoque.corredor_F = corredor_inicial;
        if (i == 6) estoque.corredor_G = corredor_inicial;
    }

    // Exibir todas as localizações
    exibirLocalizacoes(estoque);

    return 0;
}