#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int quantidade;
} produto;

typedef struct {
    char localizacao[10]; // Aumentei o tamanho para evitar estouro
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

int main() {
    produto Produto_inicial;
    Produto_inicial.quantidade = 1;
    strcpy(Produto_inicial.nome, "Nulo");

    prateleira Prateleira_Inicial;
    strcpy(Prateleira_Inicial.localizacao, "00");
    Prateleira_Inicial.Produto_armazenado = Produto_inicial;

    corredor corredor_inicial;
    corredor_inicial.Superior_Direita = Prateleira_Inicial;
    corredor_inicial.Inferior_Direita = Prateleira_Inicial;
    corredor_inicial.Inferior_Esquerda = Prateleira_Inicial;
    corredor_inicial.Superior_Esquerda = Prateleira_Inicial;

    Mercado estoque;
    estoque.corredor_A = corredor_inicial;
    estoque.corredor_B = corredor_inicial;
    estoque.corredor_C = corredor_inicial;
    estoque.corredor_D = corredor_inicial;
    estoque.corredor_E = corredor_inicial;
    estoque.corredor_F = corredor_inicial;
    estoque.corredor_G = corredor_inicial;

    char Letras[14] = "ABCDEFG";

    for (int i = 0; i < 7; i++) {
    char numero_loque = i + '0'; // Converte o inteiro i para o caractere correspondente

    Prateleira_Inicial.localizacao[0] = Letras[i]; // Modifica o primeiro caractere
    Prateleira_Inicial.localizacao[1] = numero_loque; // Define o segundo caractere como número convertido
    Prateleira_Inicial.localizacao[2] = '\0'; // Garante que seja uma string válida (terminada em '\0')

    // Exibe o valor atualizado
    printf("Localização: %s\n", Prateleira_Inicial.localizacao);
    
    }

    return 0;
}