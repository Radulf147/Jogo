#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

#define MAX_PALAVRA 200
#define MAX_TENTATIVAS 6

void jogoForca();

int main() {
    jogoForca();
    return 0;
}

void jogoForca() {
    char palavraSecreta[MAX_PALAVRA];
    char palavraDescoberta[MAX_PALAVRA];
    char letrasTentadas[MAX_TENTATIVAS];
    int tentativas = 0;
    int acertos = 0;
    int i;
    FILE* palavras;
    palavras=fopen("palavras.txt","r");

    printf("Jogo da Forca\n");
    printf("==============\n");

    int numeroAleatorio;
    srand(time(NULL));
    numeroAleatorio = rand() % 4;

    printf("%d: ",numeroAleatorio);
    system("pause");
    
    for(int k = 0; k < numeroAleatorio+1; k++)
        fgets(palavraSecreta,sizeof(palavraSecreta),palavras);

    palavraSecreta[strlen(palavraSecreta)-1]='\0';

    system("cls");

    // Limpa o buffer do teclado
    fflush(stdin);

    // Inicializa a palavra descoberta com underscores
    for (i = 0; i < strlen(palavraSecreta); i++) {
        palavraDescoberta[i] = '_';
    }
    palavraDescoberta[i] = '\0';

    while (tentativas < MAX_TENTATIVAS && acertos < strlen(palavraSecreta)) {
        printf("Palavra: %s\n", palavraDescoberta);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Letras tentadas: %s\n", letrasTentadas);

        char letra;
        int jaTentou;

        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        // Verifica se a letra já foi tentada
        jaTentou = 0;
        for (i = 0; i < tentativas; i++) {
            if (letrasTentadas[i] == letra) {
                jaTentou = 1;
                break;
            }
        }

        if (jaTentou) {
            printf("Você já tentou essa letra. Tente outra.\n");
            continue;
        }

        letrasTentadas[tentativas] = letra;
        letrasTentadas[tentativas + 1] = '\0';

        int encontrou = 0;

        // Verifica se a letra está na palavra secreta
        for (i = 0; i < strlen(palavraSecreta); i++) {
            if (palavraSecreta[i] == letra) {
                palavraDescoberta[i] = letra;
                encontrou = 1;
                acertos++;
            }
        }

        if (encontrou) {
            printf("Letra correta! Continue assim.\n");
        } else {
            printf("Letra incorreta! Tente novamente.\n");
            tentativas++;
        }

        printf("=================\n");
    }

    if (acertos == strlen(palavraSecreta)) {
        printf("Parabéns, você ganhou!\n");
    } else {
        printf("Game over! A palavra era: %s\n", palavraSecreta);
    }

    printf("Pressione qualquer tecla para sair...");
    getchar();
}
