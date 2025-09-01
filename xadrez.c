#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

// Função da estrutura de repetição da Rainha
void repetirRainha(const char *lado, int casas)
{
    if (strcmp(lado, "cima") == 0 ||
        strcmp(lado, "baixo") == 0 ||
        strcmp(lado, "esquerda") == 0 ||
        strcmp(lado, "direita") == 0)
    {
        for (int i = 1; i <= casas; i++)
        {
            printf("Rainha movendo %s %d casas\n", lado, i);
        }
    }
    else if (strcmp(lado, "diagonalCD") == 0 ||
             strcmp(lado, "diagonalBD") == 0 ||
             strcmp(lado, "diagonalCE") == 0 ||
             strcmp(lado, "diagonalBE") == 0)
    {
        for (int i = 1; i <= casas; i++)
        {
            printf("Rainha movendo para %s %d casas\n", lado, i);
        }
    }
    else
    {
        printf("Movimento inválido para a Rainha!\n");
    }
}

// Função da estrutura de repetição da torre
void repetirTorre(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Torre movendo para %s %d casas\n", lado, i);
    }
}

// Função da estrutura de repetição do Bispo
void repetirBispo(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Bispo movendo para %s %d casas\n", lado, i);
    }
}

// Função da estrutura de decisão do movimento do Cavalo
void repetirCavalo(const char *cavalo)
{
    if (strcmp(cavalo, "cimaDireita") == 0)
    {
        printf("Cavalo movendo em L: cima + direita + direita!\n");
    }
    else if (strcmp(cavalo, "baixoDireita") == 0)
    {
        printf("Cavalo movendo em L: baixo + direita + direita!\n");
    }
    else if (strcmp(cavalo, "cimaEsquerda") == 0)
    {
        printf("Cavalo movendo em L: cima + esquerda + esquerda!\n");
    }
    else if (strcmp(cavalo, "baixoEsquerda") == 0)
    {
        printf("Cavalo movendo em L: baixo + esquerda + esquerda!\n");
    }
    else
    {
        printf("Movimento de cavalo inválido!\n");
    }
}

// estrutura de decisão de movimento das peças
int validarMovimento(const char *escolha, const char **moverArray, int totalMovimentos)
{
    for (int i = 0; i < totalMovimentos; i++)
    {
        if (strcmp(escolha, moverArray[i]) == 0)
        {
            return 1;
        }
    }
    printf("Lado inválido!\n");
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const char *moverTorre[] = {"cima", "baixo", "esquerda", "direita"};
    const char *moverBispo[] = {"diagonalCD", "diagonalBD", "diagonalCE", "diagonalBE"};
    const char *moverRainha[] = {"cima", "baixo", "esquerda", "direita", "diagonalCD", "diagonalBD", "diagonalCE", "diagonalBE"};
    const char *moverCavalo[] = {"cimaDireita", "baixoDireita", "cimaEsquerda", "baixoEsquerda"};
    const char *pecas[] = {"torre", "bispo", "rainha", "cavalo"};

    char escolha[20];
    int casas;
    int movimentoValido = 0;

    printf("Bem-vindo ao jogo de Xadrez\n");

    do
    {
        printf("\nDigite qual peça você quer mover (torre, bispo, rainha, cavalo) ou 'sair' para encerrar:\n");
        scanf("%19s", escolha);

        if (strcmp(escolha, pecas[0]) == 0) // Torre
        {
            printf("Você escolheu a %s!\n", pecas[0]);
            do
            {
                printf("Digite para qual lado você quer mover a sua %s (cima, baixo, esquerda, direita) ou 'voltar':\n", pecas[0]);
                scanf("%19s", escolha);
                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverTorre, 4))
                {
                    printf("Digite quantas casas você quer andar com sua %s: ", pecas[0]);

                    if (scanf("%d", &casas) != 1)
                    {
                        printf("Entrada inválida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
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
            printf("Você escolheu o %s!\n", pecas[1]);
            do
            {
                printf("Digite para qual lado você quer mover o seu %s:\n", pecas[1]);
                printf("diagonalCE = cima esquerda\n");
                printf("diagonalBE = baixo esquerda\n");
                printf("diagonalCD = cima direita\n");
                printf("diagonalBD = baixo direita\n");
                scanf("%19s", escolha);

                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverBispo, 4))
                {
                    printf("Digite quantas casas você quer mover o seu %s: ", pecas[1]);
                    if (scanf("%d", &casas) != 1)
                    {
                        printf("Entrada inválida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        movimentoValido = 0;
                    }
                    else
                    {
                        repetirBispo(escolha, casas);
                        movimentoValido = 1;
                    }
                }
                else
                {
                    movimentoValido = 0;
                }
            } while (movimentoValido == 0); 
        }
        else if (strcmp(escolha, pecas[2]) == 0) // Rainha
        {
            printf("Você escolheu a %s!\n", pecas[2]);
            do
            {
                printf("Digite para qual lado você quer mover a sua %s:\n", pecas[2]);
                printf("Opções: cima, baixo, esquerda, direita, diagonalCD, diagonalBD, diagonalCE, diagonalBE\n");
                printf("Digite 'voltar' para retornar.\n");
                scanf("%19s", escolha);

                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverRainha, 8))
                {
                    printf("Digite quantas casas você quer andar com sua %s: ", pecas[2]);

                    if (scanf("%d", &casas) != 1)
                    {
                        printf("Entrada inválida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
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
        else if (strcmp(escolha, pecas[3]) == 0) // Cavalo
        {
            printf("Você escolheu o %s!\n", pecas[3]);
            do
            {
                printf("Digite para qual lado você quer mover o seu %s (cimaDireita, baixoDireita, cimaEsquerda, baixoEsquerda) ou 'voltar':\n", pecas[3]);
                printf("Lembrando: o cavalo se move em 'L'.\n");
                scanf("%19s", escolha);

                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverCavalo, 4))
                {
                    repetirCavalo(escolha);
                    movimentoValido = 1;
                }
                else
                {
                    movimentoValido = 0;
                }

            } while (movimentoValido == 0);
        }
        else if (strcmp(escolha, "sair") != 0)
        {
            printf("Peça inválida!\n");
        }
    } while (strcmp(escolha, "sair") != 0);

    return 0;
}
