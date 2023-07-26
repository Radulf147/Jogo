#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>
#define TAMANHO_MAX 100
#include<wchar.h>
#define MAX_PALAVRA 200
#define MAX_TENTATIVAS 6
#define NUM_RANKING 5
#include <locale.h>

char tema='2';
//Criacao do struct Jogador
typedef struct _Player
{
    char nome[21];
    int pontos_max;
    int pontos_totais;
}Player;
Player jogador;
Player ranking[NUM_RANKING];
//Declaracao das funcoes

void Carregar_Imagem(char *nome_img);
void piscaTela();
void Carregar_Menu();
int Carregar_Forca();
void Modificar_P_Max();
void Morte();
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int Save();
void Limpar()
{
    system("cls");
}
void lerNome(char *nome);
int cena = 1;
FILE *f;
char nome_imagem[30];

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    /*clock_t Ticks[2];

    Ticks[0] = clock();
    //O c�digo a ter seu tempo de execucao medido ficaria neste ponto.
    system("pause");
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0/ CLOCKS_PER_SEC;
    printf("Tempo gasto: %g  milissegundos.", Tempo);
    getchar();*/
 
    //Criacao de vari�veis

    int escolha = 0;

    

    //Chamada do arquivo da logo do jogo
    strcpy(nome_imagem, "loop.txt");
    Carregar_Imagem(nome_imagem);

    system("pause");
    
    //Tela Inicial do jogo
    char opc='0';
    while (opc!='6')
    {
        Carregar_Menu();
        scanf("%c",&opc);
        //Telas possiveis a partir da tela inicial
        switch (opc)
        {
        
        //Novo jogo
        case '1':

            //Criacao de personagem
            Limpar();
            
            lerNome(jogador.nome);

            if(Save(2) == 1)
            {
                int escolha = 0;
                printf("Voce deseja continuar do ponto que parou?\n\n");
                printf("1: Sim.\n");
                printf("2: Nao.\n\n");
                scanf("%d", &escolha);

                if(escolha == 1)
                {
                    Save(3);
                }
                else
                {
                    jogador.pontos_max = 6;
                    jogador.pontos_totais = 0;
                }
            }
            else
            {
                jogador.pontos_max = 6;
                jogador.pontos_totais = 0;
            }
            Limpar();
            //Comecar o jogo
            while(cena != 0)
            {
                switch (cena)
                {
                case 1:
                    //Cena 1: O Acordar
                    Limpar();
                    printf("%s: Nossa, que sonho mais estranho, pensei que tinha morrido. Vou comer alguma coisa pra ver se esqueco.\n", jogador.nome);
                    
                    strcpy(nome_imagem, "cama.txt");

                    Carregar_Imagem(nome_imagem);

                    system("pause");

                    Limpar();

                    cena++;


                    break;
                case 2:
                    //Cena 2:Geladeira

                    printf("%s: Aff nada pra comer nessa casa. Vou ter que ir ao mercado.\n", jogador.nome);               

                    strcpy(nome_imagem, "geladeira.txt");

                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    
                    Limpar();

                    cena++;

                    break;
                case 3:
                    //Cena 3:O beco
                    printf("%s: Estranho nao tem ninguem na rua.\n", jogador.nome);
                    strcpy(nome_imagem, "beco.txt");

                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;
                case 4:
                    //Cena 4:A pobreza da mente
                    
                    printf("Bandido: Responda essa forca ou voce M0RR3!!!\n\n");
                    printf("%s: Olha so que dialogo M3RD@.\n", jogador.nome);

                    strcpy(nome_imagem, "faca.txt");

                    Carregar_Imagem(nome_imagem);
                    
                    printf("\nDigite o numero da alternativa escolhida para continuar:\n");
                    printf("1: Eu nao, deixa de ser maluco!\n");
                    printf("2: Jae, cai pra dentro!\n");

                    scanf("%d", &escolha);

                    if(escolha == 1)
                    {
                        Morte();
                    }
                    else
                    {

                        Limpar();

                        if(!Carregar_Forca())
                        {
                            Morte();
                        }
                       else
                       {
                            cena++;
                       }
                    }
                    
                    break;
                
                case 5:
                    //Cena 5: Primeiro inimigo concluido
                    printf("%s: Na proxima vez eu te pego pela cabessa e te joooj.\n", jogador.nome);
                    strcpy(nome_imagem, "caido.txt");
                    //Olhando pro homem caido
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;
                

                case 6:
                    //Cena 6: Porta do mercado
                    printf("%s: Ate que enfim cheguei, mesmo depois daquele cara estranho.\n", jogador.nome);
                    strcpy(nome_imagem, "mercado.txt");
                    //Olhando pr aporta do mercado
                    Carregar_Imagem(nome_imagem);
                    
                    system("pause");
                    Limpar();
                    cena++;
                    break;
                

                case 7:
                    //Cena 7: Indo no balcao
                    printf("%s: Moca nao achei nenhuma cestinha, onde voces colocaram?\n", jogador.nome);
                    strcpy(nome_imagem, "costas.txt");
                    //chegando no balcao
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;

                case 8:
                    //Cena 8: Segundo dragao do dia
                    printf("Atendente: Eh muita ousadia sua vir aqui depois de tudo o que voce fez.\n");
                    printf("%s:Meu Deus o que aconteceu com o seu rosto?!\n", jogador.nome);
                    printf("Atendente: CALADO!!! Apenas jogue.\n");
                    strcpy(nome_imagem, "frente.txt");
                    //Moca com a cara feia
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();

                    if(!Carregar_Forca())
                    {
                        Morte();
                    }
                    else
                    {
                        cena++;
                    }
                    break;
                

                case 9:
                    //Cena 9: segundo inimigo vencido
                    printf("Atendente: Voce ainda vai pagar por tudo que voce fez.\n");
                    printf("%s: Me deixa em paz eu nao fiz nada!\n", jogador.nome);
                    strcpy(nome_imagem, "vomito.txt");
                    //atendente vomitando
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;

                case 10:
                    //Cena 10: a fuga
                    printf("%s: Meu Deus, o que esta acontecendo!\n", jogador.nome);
                    strcpy(nome_imagem, "correndo.txt");
                    //correndo pra casa
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;
                
                case 11:
                    //Cena 11: abrindo a porta
                    printf("%s: Ate que enfim, sera que eu estou seguro agora?\n", jogador.nome);
                    strcpy(nome_imagem, "porta.txt");
                    //abrindo a porta
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;

                case 12:
                    //Cena 12: a mae
                    printf("Mae: %s, voce nao pode mais fugir disso, vou por um fim nisso agora!\n", jogador.nome); 
                    printf("%s: Eu nao aguento mais, so quero que isso acabe!\n", jogador.nome);
                    printf("%s: Isso nao e mais sua escolha\n", jogador.nome);
                    strcpy(nome_imagem, "mae.txt");
                    //mae segurando uma faca
                    Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();

                    if(!Carregar_Forca())
                    {
                        Morte();
                    }
                    else
                    {
                        cena++;
                    }
                    break;



                case 13:

                    //Cena 13:o fim
                    
                    printf("Mae: Filho, eu nao consigo te reconhecer mais!\n"); 

                    strcpy(nome_imagem, "mae2.txt");

                    Carregar_Imagem(nome_imagem);
                    
                    printf("\n Digite o numero da alternativa escolhida para continuar:\n");
                    printf("1: Me perdoa por isso!(Matar sua mae)\n");
                    printf("2: Me perdoa por isso!(Se suicidar)\n");

                    scanf("%d", &escolha);

                    system("pause");
                    Limpar();
                    cena++;
                    break;
                    
                case 14:
                    strcpy(nome_imagem, "investigador.txt");

                    Carregar_Imagem(nome_imagem);
                    printf("Delegado: Naquele dia a mae de %s chegou em casa e viu a namorada de seu filho esfaqueada ao lado da cama.",jogador.nome);
                    printf(" Aparentemente ela ja sabia da situacao mental em que ele se encontrava e ligou para a delegacia denuncia-lo.");
                    printf(" No mesmo dia e no mesmo horario, denuncias de dois assassinatos foram feitas.");
                    printf(" As testemunhas do primeiro disseram que a pessoa assassinada era um mendigo e estava apenas pedindo esmola proximo a um mercado local.");
                    printf(" A segunda foi a atendente desse mesmo mercado.");
                    printf(" Apos investigacoes os policiais conseguiram identificar o assassino e realmente era %s.", jogador.nome);
                    //Final 1
                    if(escolha == 1){
                        
                        printf(" Ao chegarem em sua residencia encontraram sua mae morta e o individuo ja havia fugido do local do crime.");
                        printf(" Mas investigacoes estao sendo realizadas para tentar encontra-lo. ");
                        printf(" Fim do relatorio.");

                    }
                    //Final 2
                    else
                    {
                        printf(" Ao chegarem em sua residencia encontraram sua mae aos prantos no chao, segurando o seu corpo");
                        printf(" A mesma confessou que ele havia se suicidado.");
                        printf(" Fim do relatorio.");
                    }
                    
                    //abrindo a porta
                    //Carregar_Imagem(nome_imagem);

                    system("pause");
                    Limpar();
                    cena++;
                    break;

                case 15:
                    printf("Parabens, voce ganhou o jogo!\n\n");
                    printf("Você deseja salvar sua pontuacao na tabeala de pontuacoes?\n\n");
                    printf("1: Sim.\n");
                    printf("2: Nao.\n");

                    int escolha = 0;
                    scanf("%d", &escolha);

                    if(escolha == 1)
                    {
                        atualizarRanking();
                    }

                    system("pause");
                    Limpar();
                    cena = 0;
                    break;

                
                default:
                    break;
                }
            }
            system("pause");
            break;
        
        //Tela de Creditos
        case '2':
            Limpar();
            printf("Loop, a game developed by:\nCharlie Prince de Souza Andrade\nRaul Montes Rosales do Nascimento\n\n");
            system("pause");
            break;

        //Tela de Teste Piscar
        case '3':
            Limpar();
            printf("Piscou\n\n");
            piscaTela();
            system("pause");
            break;

        //Tela de Escolha de tema
        case '4':
            Limpar();
            printf("1 - Tema Claro\n");
            printf("2 - Tema Escuro\n");
            fflush(stdin);
            scanf("%c",&tema);
            if(tema=='1')
                system("color f0");
            if(tema=='2')
                system("color 0f");
            break;
        case '5':
            Limpar();

            // L� os dados dos jogadores a partir do arquivo bin�rio
            strcpy(nome_imagem, "pontuacao.txt");

            Carregar_Ranking(nome_imagem);
            printf("\n");
            system("pause");
            break;
        case '6':
            Limpar();
            printf("Obrigado por jogar!!!\n");
            break;

        default:
            break;
        }

    }
    
    return 0;
    
}

                            //Area implementacao de Funcoes//
           
//Funcao para carregar a cena desejada
void Carregar_Imagem(char *nome_img)
{
    FILE *imagem;
    imagem = fopen(nome_img,"r");
    char linha[400];
    
    //Chamada do arquivo da logo do jogo
    while (!feof(imagem))
    {
        fgets(linha,sizeof(linha),imagem);
        printf("%s",linha);
    }
    Save(1);
}
void Carregar_Ranking(char *nome_img)
{
    FILE *imagem;
    imagem = fopen(nome_img,"r");
    char linha[400];
    
    //Chamada do arquivo da logo do jogo
    while (!feof(imagem))
    {
        fgets(linha,sizeof(linha),imagem);
        printf("%s",linha);
    }
}
void lerNome(char *nome) {
    int apenasEspacos = 1;

    do {
        apenasEspacos = 1;
        memset(nome, 0, sizeof(nome));
        printf("Digite um nome: ");
        fgets(nome, 20, stdin);
    
        // Remover caracteres de nova linha ou retorno de carro do final da string
        nome[strcspn(nome, "\n\r")] = '\0';

        // Verificar se a string contem apenas espa�os em branco
        for (int i = 0; i < strlen(nome); i++) {
            if (!isspace(nome[i])) {
                limparBufferEntrada();
                apenasEspacos = 0;
                break;
            }
        }

        if (apenasEspacos) {
            Limpar();
            printf("Nome incorreto. Digite novamente.\n");
        }
    } while (apenasEspacos);
}
//Funcao para carregar a tela de Forca
int Carregar_Forca() {
    char palavraSecreta[MAX_PALAVRA];
    char palavraDescoberta[MAX_PALAVRA];
    char letrasTentadas[MAX_TENTATIVAS] = {0}; // Inicializa o array com zeros
    int cont_erros = 0;
    int acertos = 0;
    int i, soma = 0;
    int pontos_max_atual = jogador.pontos_max;
    FILE* palavras;
    palavras = fopen("palavras.txt", "r");

    printf("Jogo da Forca\n");
    printf("==============\n");

    int numeroAleatorio;
    srand(time(NULL));
    numeroAleatorio = rand() % 13;

    system("pause");
    
    for (int k = 0; k < numeroAleatorio + 1; k++)
        fgets(palavraSecreta, sizeof(palavraSecreta), palavras);

    palavraSecreta[strlen(palavraSecreta) - 1] = '\0';

    Limpar();

    // Limpa o buffer do teclado
    fflush(stdin);

    // Inicializa a palavra descoberta com underscores
    for (i = 0; i < strlen(palavraSecreta); i++) {
        palavraDescoberta[i] = '_';
    }
    palavraDescoberta[i] = '\0';

    int numLetrasTentadas = 0; // Nova vari�vel para contar as letras tentadas

    while (cont_erros < MAX_TENTATIVAS && acertos < strlen(palavraSecreta)) {
        Limpar();
        printf("Palavra: %s\n", palavraDescoberta);
        printf("tentativas restantes: %d\n", MAX_TENTATIVAS - cont_erros);
        printf("Letras tentadas: %s\n", letrasTentadas);

        char letra;
        int jaTentou = 0;

        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        // Verifica se a letra j� foi tentada
        for (i = 0; i < numLetrasTentadas; i++) {
            if (letrasTentadas[i] == letra) {
                jaTentou = 1;
                break;
            }
        }

        if (jaTentou) {
            printf("Voce ja tentou essa letra. Tente outra.\n");
            system("pause");
            continue;
        }
        letrasTentadas[numLetrasTentadas++] = letra; // Adiciona a letra e incrementa numLetrasTentadas

        int encontrou = 0;

        // Verifica se a letra esta na palavra secreta
        for (i = 0; i < strlen(palavraSecreta); i++) {
            if (palavraSecreta[i] == letra) {
                palavraDescoberta[i] = letra;
                encontrou = 1;
                acertos++;
            }
        }

        // Adiciona o caractere nulo apos o loop de verificao das letras
        palavraDescoberta[i] = '\0';

        if (encontrou) {
            printf("Letra correta! Continue assim.\n");
        } else {
            printf("Letra incorreta! Tente novamente.\n");
            cont_erros++;
        }

        printf("=================\n");
        system("pause");
        Limpar();
    }

    if (acertos == strlen(palavraSecreta)) {
        if(jogador.pontos_max >= cont_erros)
        {
            jogador.pontos_totais +=((jogador.pontos_max-cont_erros)*2);
        }
        printf("Parabens, voce ganhou, com %d pontos!\n", jogador.pontos_totais);
        printf("Pressione qualquer tecla para sair...");
        system("pause");
        
        Limpar();
        return 1;
    } else {
        printf("Game over! A palavra era: %s\n", palavraSecreta);
        printf("Pressione qualquer tecla para sair...");
        system("pause");
        
        return 0;
    }
}
void Carregar_Menu()
{
   Limpar();
        printf("1 - Iniciar um novo Jogo\n");
        printf("2 - Creditos\n");
        printf("3 - Piscar\n");
        printf("4 - Tema\n");
        printf("5 - Ranking\n");
        printf("6 - Sair\n");
}
//Funcao para piscar tela

void piscaTela(){
    int i=10;
    while (i>0)
    {
        usleep(100000);
        if(i%2==0)
            system("color 47");
        else
            system("color 74");
        i--;
    }

    if(tema=='2')
        system("color 0f");
    if(tema=='1')
        system("color f0");
}
void Morte()
{
    Limpar();
    printf("VOCE MORREU!!!\n");
    strcpy(nome_imagem,"game_over.txt");
    Carregar_Imagem(nome_imagem);
    printf("\n");
    jogador.pontos_max--;
    piscaTela();
    system("pause");
    cena = 1;
}

int Save(int acao)
{
    char nome[50];
    strcpy(nome,"Save\\");
    strcat(nome, jogador.nome);
    strcat(nome, ".bin");
    FILE *f;


    if(acao == 1)
    {
        f = fopen(nome, "wb");

        fwrite(&jogador.pontos_max, sizeof(int), 1, f);
        fwrite(&jogador.pontos_totais, sizeof(int), 1, f);
        fwrite(&cena, sizeof(int), 1, f);
        fclose(f);
        return 0;
    }
    else if(acao == 2)
    {
        f = fopen(nome, "rb");
        
        if(f != NULL)
        {
            fclose(f);
            return 1;
        }
        else
        {
            fclose(f);
            return 0;
        }
    }
    else if(acao == 3)
    {
        f = fopen(nome, "rb");
        
        fread(&jogador.pontos_max, sizeof(int), 1, f);
        fread(&jogador.pontos_totais, sizeof(int), 1, f);
        fread(&cena, sizeof(int), 1, f);
        fclose(f);
        return 0;
    }
}
void atualizarRanking() {
    f = fopen("pontuacao.txt", "a");

    fprintf(f, "\n%s %d Pontos %d Pontos maximos", jogador.nome, jogador.pontos_totais, jogador.pontos_max);
    fclose(f);
    
}