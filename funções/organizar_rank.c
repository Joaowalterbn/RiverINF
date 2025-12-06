#include "config_function.h"
#include <string.h> // Necessário para strcpy

// Função le arquivo bem simples que pega os dados e coloca num array
void le_arquivo(char nome_arq[], JOGADOR top5[])
{
    FILE *fp = fopen(nome_arq, "rb");
    if(fp != NULL)
    {
        if(fread(top5, sizeof(JOGADOR), 5, fp) != 5)
        {
            // Opcional: lidar com erro de leitura ou arquivo vazio
            // erro_load();
        }
        fclose(fp);
    }
    // Se não abrir (arquivo não existe), o array continua zerado (definido na main)
}

// Função que escreve os dados no arquivo binario
void salva_arquivo(char nome_arq[], JOGADOR top5[])
{
    FILE *fp = fopen(nome_arq, "wb");
    if(fp != NULL)
    {
        fwrite(top5, sizeof(JOGADOR), 5, fp);
        fclose(fp);
    }
    else
    {
        // erro_load();
    }
}

// Função que troca de Lugar e atribui o novo jogador no rank
void org_top5(JOGADOR r[], int pts_novos, int ind, char nome_recorde[])
{
    JOGADOR novoj, temp1, temp2;
    novoj.pontos = pts_novos;

    // Garante que o nome tenha terminação nula e copia
    strncpy(novoj.nome, nome_recorde, 7);
    novoj.nome[7] = '\0';

    temp1 = r[ind];
    r[ind] = novoj;

    for(int j = ind+1; j < MAXSCORES; j++)
    {
        temp2 = r[j];
        r[j] = temp1;
        temp1 = temp2;
    }
}

bool processar_input_nome(char nome_recorde[], int *ind)
{
    int tecla = GetCharPressed();

    while (tecla > 0)
    {
        // Aceita letras e números, limita a 7 caracteres
        if ((tecla >= 32) && (tecla <= 125) && (*ind < 7))
        {
            nome_recorde[*ind] = (char)tecla;
            (*ind)++;
            nome_recorde[*ind] = '\0';
        }
        tecla = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        if (*ind > 0)
        {
            (*ind)--;
            nome_recorde[*ind] = '\0';
        }
    }

    // Só permite confirmar se tiver digitado pelo menos 1 letra
    if (IsKeyPressed(KEY_ENTER) && *ind > 0)
    {
        return true; // Finalizou a digitação
    }

    return false; // Ainda está digitando
}

// Função apenas de desenho, recebe o nome atual para mostrar na tela
// Função de desenho aprimorada com cursor piscante e melhor alinhamento
// Função de desenho adaptada ao estilo pixel art
void desenhar_input_nome(char nome_atual[])
{
    DrawText("NOVO RECORDE!", 480 - MeasureText("NOVO RECORDE!", TAM_DEFAULT + 5)/2, 150, TAM_DEFAULT + 5, YELLOW);

    DrawText("DIGITE SEU NOME:", 480 - MeasureText("DIGITE SEU NOME:", TAM_DEFAULT - 40)/2, 300, TAM_DEFAULT - 40, YELLOW); // Branco/Claro para contraste

    // --- Definição e Desenho da Caixa de Texto ---
    Rectangle textBox = { 300, 370, 360, 70 };

    // Fundo da caixa: Usaremos uma cor escura com alta transparência, ou PRETO
    // Se o estilo for puramente pixel art, uma caixa sólida é melhor.
    DrawRectangleRec(textBox, RAYWHITE);

    // Borda: Amarela, para seguir o tema retro da imagem
    DrawRectangleLinesEx(textBox, 4, YELLOW);

    // Desenha o nome que o usuário está digitando
    DrawText(nome_atual, textBox.x + 15, textBox.y + 15, 50, BLACK);

    DrawText("Pressione [ENTER] para confirmar", 480 - MeasureText("Pressione [ENTER] para confirmar", TAM_DEFAULT - 60)/2, 500, TAM_DEFAULT - 60, YELLOW);
}

// Função principal que gerencia o Rank
void organizar_rank(int pts_atual, JOGADOR ranking[])
{
    int indice_rank = -1;

    // 1. Verifica se entrou no top 5 e descobre a posição
    for(int i = 0; i < 5; i++)
    {
        if(pts_atual > ranking[i].pontos)
        {
            indice_rank = i;
            break; // Achou a posição, para o loop
        }
    }

    // 2. Se entrou no rank, inicia o loop de captura de nome
    if(indice_rank != -1)
    {
        char nome_recorde[8] = {0}; // Buffer para o nome (7 letras + \0)
        int letras_count = 0;       // Índice atual da letra
        bool nome_finalizado = false;

        while(!nome_finalizado)
        {
            // Input
            nome_finalizado = processar_input_nome(nome_recorde, &letras_count);

            // Desenho
            BeginDrawing();
            ClearBackground(DARKBLUE);

            desenhar_input_nome(nome_recorde);

            EndDrawing();
        }

        org_top5(ranking, pts_atual, indice_rank, nome_recorde);
        salva_arquivo("highscore.bin", ranking);
    }
}
