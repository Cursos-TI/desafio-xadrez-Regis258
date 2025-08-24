#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

//funcções obrigatórias para o funcionamento do jogo e melhorar a aparência do código

//função para imprimir a quantidade que a rainha irá se movar com a quantidade de casas que o usuário pediu
void repetirRainha(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Rainha movendo para %s %d casas\n", lado, i);
    }
}
//função para imprimir a quantidade que a torre irá se movar com a quantidade de casas que o usuário pediu
void repetirTorre(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Torre movendo para %s %d casas\n", lado, i);
    }
}

//função para imprimir a quantidade que o bispo irá se movar com a quantidade de casas que o usuário pediu
void repetirBispo(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Bispo movendo para %s %d casas\n", lado, i);
    }
}

//função que serve para validação de movinmento (não ultrapassar a quantidade maxima do tabuleiro 8 casas)
int validarMovimento(const char *escolha, const char **moverArray, int totalMovimentos)
{
    for (int i = 0; i < totalMovimentos; i++)
    {
        if (strcmp(escolha, moverArray[i]) == 0)
        {
            return 1;
        }
    }
    printf("Lado Invalido!\n");
    return 0;
}
int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    setlocale(LC_ALL, "Portuguese");

    const char *moverTorre[] = {"cima", "baixo", "esquerda", "direita"};
    const char *moverBispo[] = {"diagonalCD", "diagonalB", "diagonalCE", "diagonalBE"};
    const char *moverRainha[] = {"cima", "baixo", "esquerda", "direita"};
    const char *pecas[] = {"torre", "bispo", "rainha"};

    char escolha[20];
    int casas;
    int movimentoValido = 0;

    printf("Bem vindo ao jogo de Xadrez\n");

    do
    {
        printf("\nDigite qual peca voce quer mover (torre, bispo, rainha) ou 'sair' para encerrar:\n");
        scanf("%19s", escolha);

        if (strcmp(escolha, pecas[0]) == 0) // torre
        {
            printf("Voce escolheu a %s!\n", pecas[0]);
            do
            {
                printf("Digite para qual lado voce quer mover a sua %s (cima, baixo, esquerda, direita!) ou 'voltar':\n", pecas[0]);
                scanf("%19s", escolha);
                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverTorre, 4))
                {
                    printf("Digite quantas casas voce quer andar com sua %s: ", pecas[0]);

                    if (scanf("%d", &casas) != 1)
                    { // Verifica se a leitura foi bem-sucedida
                        printf("Entrada invalida! Por favor, digite um numero.\n");
                        // Limpa o buffer de entrada
                        while (getchar() != '\n')
                            ;
                        movimentoValido = 0;
                    }
                    else
                    {
                        repetirTorre(escolha, casas);
                        movimentoValido = 1;
                    }
                }
                else
                {
                    movimentoValido = 0;
                }
            } while (movimentoValido == 0);
        }
        else if (strcmp(escolha, pecas[1]) == 0) // Bispo
        {
            printf("Voce escolheu o %s!\n", pecas[1]);
            do
            {
                printf("Digite para qual lado você quer mover o seu %s (diagonalCE = cima esquerda\ndiagonalBE = baixo esquerda\n)");
                printf("diagonalCD = cima direita\ndiagonalBD = baixo direita\n");
                scanf("%19s", escolha);
                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverBispo, 4))
                {
                    printf("Digite quantas casas você quer mover o seu %s: ", pecas[1]);
                    if (scanf("%d", &casas) != 1)
                    { // verifica se a quantidade de casas que usuario digitou é permitia [válida]
                        printf("Entrada inválida! Por favor, digite um número.\n");
                        while (getchar() != 1)
                            ;
                        movimentoValido = 0;
                    }
                    else
                    {
                        repetirBispo(escolha, casas);
                        movimentoValido = 1;
                    }
                }
            } while (movimentoValido = 0);
        }
        else if (strcmp(escolha, pecas[2]) == 0) // Rainha
        {
            printf("Voce escolheu a %s!\n", pecas[2]);
            do
            {
                printf("Digite para qual lado voce quer mover a sua %s (cima, baixo, esquerda, direita!) ou 'voltar':\n", pecas[2]);
                scanf("%19s", escolha);
                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverRainha, 4))
                {
                    printf("Digite quantas casas voce quer andar com sua %s: ", pecas[2]);

                    // --- CORREÇÃO DO SCANF AQUI ---
                    if (scanf("%d", &casas) != 1)
                    { // Verifica se a leitura foi bem-sucedida
                        printf("Entrada invalida! Por favor, digite um numero.\n");
                        while (getchar() != '\n')
                            ;
                        movimentoValido = 0;
                    }
                    else
                    {
                        repetirRainha(escolha, casas);
                        movimentoValido = 1;
                    }
                }
                else
                {
                    movimentoValido = 0;
                }
            } while (movimentoValido == 0);
        }
        else if (strcmp(escolha, "sair") != 0)
        {
            printf("Peca invalida!\n");
        }
    } while (strcmp(escolha, "sair") != 0);

    return 0;
}