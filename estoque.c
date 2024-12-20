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
} Estoque;



void ExibirEstoque(Estoque Mercado) {
    // Função para exibir todas as localizações do mercado
    corredor corredores[7] = {
        Mercado.corredor_A, Mercado.corredor_B, Mercado.corredor_C,
        Mercado.corredor_D, Mercado.corredor_E, Mercado.corredor_F,
        Mercado.corredor_G
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

void PesquisarEstoque(Estoque Mercado) {
    char input[50];
    int verificador = 0;
    int opcao = 0;

    corredor corredores[7] = {
        Mercado.corredor_A, Mercado.corredor_B, Mercado.corredor_C,
        Mercado.corredor_D, Mercado.corredor_E, Mercado.corredor_F,
        Mercado.corredor_G
    };

    printf("Você deseja buscar por nome ou endereço?\n");
    printf("1-Nome\n2-Endereço\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Qual produto deseja pesquisar?\n");
        getchar();
        fgets(input, sizeof(input), stdin);

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        for (int i = 0; i < 7; i++) {
            if (strcmp(corredores[i].Superior_Direita.Produto_armazenado.nome, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Superior_Direita.localizacao,
                       corredores[i].Superior_Direita.Produto_armazenado.nome,
                       corredores[i].Superior_Direita.Produto_armazenado.quantidade);
                verificador = 1;
            }
            if (strcmp(corredores[i].Inferior_Direita.Produto_armazenado.nome, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Inferior_Direita.localizacao,
                       corredores[i].Inferior_Direita.Produto_armazenado.nome,
                       corredores[i].Inferior_Direita.Produto_armazenado.quantidade);
                verificador = 1;
            }
            if (strcmp(corredores[i].Superior_Esquerda.Produto_armazenado.nome, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Superior_Esquerda.localizacao,
                       corredores[i].Superior_Esquerda.Produto_armazenado.nome,
                       corredores[i].Superior_Esquerda.Produto_armazenado.quantidade);
                verificador = 1;
            }
            if (strcmp(corredores[i].Inferior_Esquerda.Produto_armazenado.nome, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Inferior_Esquerda.localizacao,
                       corredores[i].Inferior_Esquerda.Produto_armazenado.nome,
                       corredores[i].Inferior_Esquerda.Produto_armazenado.quantidade);
                verificador = 1;
            }
        }

        if (verificador == 0) {
            printf("Produto não encontrado em Mercado!\n");
        }
    } else if (opcao == 2) {
        printf("Qual a localização que deseja pesquisar?\n");
        getchar();
        fgets(input, sizeof(input), stdin);

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        for (int i = 0; i < 7; i++) {
            if (strcmp(corredores[i].Superior_Direita.localizacao, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Superior_Direita.localizacao,
                       corredores[i].Superior_Direita.Produto_armazenado.nome,
                       corredores[i].Superior_Direita.Produto_armazenado.quantidade);
                verificador = 1;
            }
            if (strcmp(corredores[i].Inferior_Direita.localizacao, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Inferior_Direita.localizacao,
                       corredores[i].Inferior_Direita.Produto_armazenado.nome,
                       corredores[i].Inferior_Direita.Produto_armazenado.quantidade);
                verificador = 1;
            }
            if (strcmp(corredores[i].Superior_Esquerda.localizacao, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Superior_Esquerda.localizacao,
                       corredores[i].Superior_Esquerda.Produto_armazenado.nome,
                       corredores[i].Superior_Esquerda.Produto_armazenado.quantidade);
                verificador = 1;
            }
            if (strcmp(corredores[i].Inferior_Esquerda.localizacao, input) == 0) {
                printf("Localização: %s | Produto: %s | Quantidade: %d\n",
                       corredores[i].Inferior_Esquerda.localizacao,
                       corredores[i].Inferior_Esquerda.Produto_armazenado.nome,
                       corredores[i].Inferior_Esquerda.Produto_armazenado.quantidade);
                verificador = 1;
            }
        }

        if (verificador == 0) {
            printf("Nenhum produto encontrado para a localização fornecida!\n");
        }
    } else {
        printf("Opção inválida!\n");
    }
}

void InserirProduto(Estoque *Mercado) {
    produto Newproduto;
    char Endereco[10];

    printf("Nome do produto: ");
    getchar(); // Limpa o buffer
    fgets(Newproduto.nome, sizeof(Newproduto.nome), stdin);

    // Remove o '\n' do final da string
    size_t len = strlen(Newproduto.nome);
    if (len > 0 && Newproduto.nome[len - 1] == '\n') {
        Newproduto.nome[len - 1] = '\0';
    }

    printf("Quantidade: ");
    scanf("%d", &Newproduto.quantidade);
    getchar(); // Limpa o buffer

    printf("Em qual prateleira deseja inserir o produto? ");
    fgets(Endereco, sizeof(Endereco), stdin);
    len = strlen(Endereco);
    if (len > 0 && Endereco[len - 1] == '\n') {
        Endereco[len - 1] = '\0';
    }

    // Determinar o corredor com base em Endereco[0]
    corredor *corredor_selecionado = NULL;
    switch (Endereco[0]) {
        case 'A': corredor_selecionado = &Mercado->corredor_A; break;
        case 'B': corredor_selecionado = &Mercado->corredor_B; break;
        case 'C': corredor_selecionado = &Mercado->corredor_C; break;
        case 'D': corredor_selecionado = &Mercado->corredor_D; break;
        case 'E': corredor_selecionado = &Mercado->corredor_E; break;
        case 'F': corredor_selecionado = &Mercado->corredor_F; break;
        case 'G': corredor_selecionado = &Mercado->corredor_G; break;
        default:
            printf("Corredor inválido!\n");
            return;
    }

    // Determinar a prateleira com base em Endereco[1]
    if (corredor_selecionado) {
        prateleira *prateleira_selecionada = NULL;

        if (Endereco[1] == '1') {
            prateleira_selecionada = &corredor_selecionado->Superior_Direita;
        } else if (Endereco[1] == '2') {
            prateleira_selecionada = &corredor_selecionado->Inferior_Direita;
        } else if (Endereco[1] == '3') {
            prateleira_selecionada = &corredor_selecionado->Superior_Esquerda;
        } else if (Endereco[1] == '4') {
            prateleira_selecionada = &corredor_selecionado->Inferior_Esquerda;
        } else {
            printf("Prateleira inválida!\n");
            return;
        }

        // Verificar se a prateleira é uma Zona De Peking
        if (strcmp(prateleira_selecionada->Produto_armazenado.nome, "Zona De Peking") == 0) {
            printf("A localização %s é uma Zona De Peking e não pode ser alterada!\n", Endereco);
            return;
        }

        // Inserir o produto na prateleira selecionada
        prateleira_selecionada->Produto_armazenado = Newproduto;
        printf("Produto %s inserido na localização %s com sucesso!\n", Newproduto.nome, Endereco);
    }
}


void RemoverProduto(Estoque *Mercado) {
    char produtoRemover[50];
    int verificador = 0;
    produto ProdutoInicial;
    ProdutoInicial.quantidade = 0;
    strcpy(ProdutoInicial.nome, "Nulo");

    printf("Qual o nome do produto que você deseja remover: ");
    getchar();
    fgets(produtoRemover, sizeof(produtoRemover), stdin);

    size_t len = strlen(produtoRemover);
    if (len > 0 && produtoRemover[len - 1] == '\n') {
        produtoRemover[len - 1] = '\0';
    }

    corredor *corredores[7] = {
        &Mercado->corredor_A, &Mercado->corredor_B, &Mercado->corredor_C,
        &Mercado->corredor_D, &Mercado->corredor_E, &Mercado->corredor_F,
        &Mercado->corredor_G
    };

    for (int i = 0; i < 7; i++) {
        if (strcmp(corredores[i]->Superior_Direita.Produto_armazenado.nome, produtoRemover) == 0) {
            printf("Produto removido da localização: %s\n", corredores[i]->Superior_Direita.localizacao);
            corredores[i]->Superior_Direita.Produto_armazenado = ProdutoInicial;
            verificador = 1;
        }

        if (strcmp(corredores[i]->Inferior_Direita.Produto_armazenado.nome, produtoRemover) == 0) {
            printf("Produto removido da localização: %s\n", corredores[i]->Inferior_Direita.localizacao);
            corredores[i]->Inferior_Direita.Produto_armazenado = ProdutoInicial;
            verificador = 1;
        }

        if (strcmp(corredores[i]->Superior_Esquerda.Produto_armazenado.nome, produtoRemover) == 0) {
            printf("Produto removido da localização: %s\n", corredores[i]->Superior_Esquerda.localizacao);
            corredores[i]->Superior_Esquerda.Produto_armazenado = ProdutoInicial;
            verificador = 1;
        }

        if (strcmp(corredores[i]->Inferior_Esquerda.Produto_armazenado.nome, produtoRemover) == 0) {
            printf("Produto removido da localização: %s\n", corredores[i]->Inferior_Esquerda.localizacao);
            corredores[i]->Inferior_Esquerda.Produto_armazenado = ProdutoInicial;
            verificador = 1;
        }
    }

    if (verificador == 0) {
        printf("Produto não encontrado no mercado!\n");
    }
}


int Menu_Replay(int opcao){
    
    int num=0;
    while (num!=1 || num!=2){
        printf("\nDeseja selecinar outra opção:");
        printf("\n1-Sim\n2-Não");
        printf("\nInsira o número correspondente a opção desejada: ");
        scanf("%d", &num);

        if (num==1){
            return 0;     
        };
        if (num==2){
            return opcao;
        }
    }
 }

void Menu(Estoque Mercado){
    int opcao= 0;
    while (opcao<1 || opcao>4){
        while (opcao<1 || opcao>4){
                    printf("\n------MENU DO GERENCIADOR DE ESTOQUE------\n");
            printf("      1-Exibir todos os produtos do estoque.\n");
            printf("      2-Pesquisar produto.\n");
            printf("      3-Inserir produto\n");
            printf("      4-Remover produto\n");

            printf("Insira o número correspondente a opção desejada: ");
            scanf("%d", &opcao);
        };

        if (opcao==1){
            ExibirEstoque(Mercado);
            opcao = Menu_Replay(opcao);
        };
        
        if (opcao==2){
            PesquisarEstoque(Mercado);
            opcao = Menu_Replay(opcao);
        };
        if (opcao==3){
            InserirProduto(&Mercado);
            opcao = Menu_Replay(opcao);
        };
        if (opcao==4){
            RemoverProduto(&Mercado);
            opcao = Menu_Replay(opcao);
        };
    }
}

int main() {
    produto Produto_inicial;
    Produto_inicial.quantidade = 0;
    strcpy(Produto_inicial.nome, "Nulo");

    produto ZonaDePeking;
    ZonaDePeking.quantidade = 10; // Quantidade exemplo
    strcpy(ZonaDePeking.nome, "Zona De Peking");

    prateleira Prateleira_Inicial;

    corredor corredor_inicial;
    Estoque Mercado;

    char Letras[7] = "ABCDEFG";

    for (int i = 0; i < 7; i++) {
        for (int a = 0; a < 4; a++) {
            char numero_loque = (a + 1) + '0'; // Converte o índice para caractere
            strcpy(Prateleira_Inicial.localizacao, "00");

            // Verifica se a prateleira é de número par
            if ((a + 1) % 2 == 0) {
                Prateleira_Inicial.Produto_armazenado = ZonaDePeking;
            } else {
                Prateleira_Inicial.Produto_armazenado = Produto_inicial;
            }

            // Define o endereço da prateleira
            Prateleira_Inicial.localizacao[0] = Letras[i];
            Prateleira_Inicial.localizacao[1] = numero_loque;
            Prateleira_Inicial.localizacao[2] = '\0'; // Garante que a string seja válida

            // Atribui a prateleira ao corredor
            if (a == 0) corredor_inicial.Superior_Direita = Prateleira_Inicial;
            if (a == 1) corredor_inicial.Inferior_Direita = Prateleira_Inicial;
            if (a == 2) corredor_inicial.Superior_Esquerda = Prateleira_Inicial;
            if (a == 3) corredor_inicial.Inferior_Esquerda = Prateleira_Inicial;
        }

        // Atribui o corredor ao estoque
        if (i == 0) Mercado.corredor_A = corredor_inicial;
        if (i == 1) Mercado.corredor_B = corredor_inicial;
        if (i == 2) Mercado.corredor_C = corredor_inicial;
        if (i == 3) Mercado.corredor_D = corredor_inicial;
        if (i == 4) Mercado.corredor_E = corredor_inicial;
        if (i == 5) Mercado.corredor_F = corredor_inicial;
        if (i == 6) Mercado.corredor_G = corredor_inicial;
    }

    Menu(Mercado);

    return 0;
}