#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este c�digo inicial serve como base para o desenvolvimento do sistema de movimenta��o das pe�as de xadrez.
// O objetivo � utilizar estruturas de repeti��o e fun��es para determinar os limites de movimenta��o dentro do jogo.

//func��es obrigat�rias para o funcionamento do jogo e melhorar a apar�ncia do c�digo

//fun��o para imprimir a quantidade que a rainha ir� se movar com a quantidade de casas que o usu�rio pediu
void repetirRainha(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Rainha movendo para %s %d casas\n", lado, i);
    }
}
//fun��o para imprimir a quantidade que a torre ir� se movar com a quantidade de casas que o usu�rio pediu
void repetirTorre(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Torre movendo para %s %d casas\n", lado, i);
    }
}

//fun��o para imprimir a quantidade que o bispo ir� se movar com a quantidade de casas que o usu�rio pediu
void repetirBispo(const char *lado, int casas)
{
    for (int i = 1; i <= casas; i++)
    {
        printf("Bispo movendo para %s %d casas\n", lado, i);
    }
}

//fun��o que serve para valida��o de movinmento (n�o ultrapassar a quantidade maxima do tabuleiro 8 casas)
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
    // N�vel Novato - Movimenta��o das Pe�as
    // Sugest�o: Declare vari�veis constantes para representar o n�mero de casas que cada pe�a pode se mover.

    // Implementa��o de Movimenta��o do Bispo
    // Sugest�o: Utilize uma estrutura de repeti��o para simular a movimenta��o do Bispo em diagonal.

    // Implementa��o de Movimenta��o da Torre
    // Sugest�o: Utilize uma estrutura de repeti��o para simular a movimenta��o da Torre para a direita.

    // Implementa��o de Movimenta��o da Rainha
    // Sugest�o: Utilize uma estrutura de repeti��o para simular a movimenta��o da Rainha para a esquerda.

    // N�vel Aventureiro - Movimenta��o do Cavalo
    // Sugest�o: Utilize loops aninhados para simular a movimenta��o do Cavalo em L.
    // Um loop pode representar a movimenta��o horizontal e outro vertical.

    // N�vel Mestre - Fun��es Recursivas e Loops Aninhados
    // Sugest�o: Substitua as movimenta��es das pe�as por fun��es recursivas.
    // Exemplo: Crie uma fun��o recursiva para o movimento do Bispo.

    // Sugest�o: Implemente a movimenta��o do Cavalo utilizando loops com vari�veis m�ltiplas e condi��es avan�adas.
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
                printf("Digite para qual lado voc� quer mover o seu %s (diagonalCE = cima esquerda\ndiagonalBE = baixo esquerda\n)");
                printf("diagonalCD = cima direita\ndiagonalBD = baixo direita\n");
                scanf("%19s", escolha);
                if (strcmp(escolha, "voltar") == 0)
                {
                    break;
                }
                if (validarMovimento(escolha, moverBispo, 4))
                {
                    printf("Digite quantas casas voc� quer mover o seu %s: ", pecas[1]);
                    if (scanf("%d", &casas) != 1)
                    { // verifica se a quantidade de casas que usuario digitou � permitia [v�lida]
                        printf("Entrada inv�lida! Por favor, digite um n�mero.\n");
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

                    // --- CORRE��O DO SCANF AQUI ---
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