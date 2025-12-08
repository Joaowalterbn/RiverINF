#include "config_function.h"

// Função le arquivo bem simples que pega os dados e coloca num array
void le_arquivo(char nome_arq[], JOGADOR top5[])
{
    FILE *fp = fopen(nome_arq, "rb");
    if(fp != NULL)
    {
        if(fread(top5, sizeof(JOGADOR), 5, fp) != 5)
        {
             erro_load();
        }
        fclose(fp);
    }
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
         erro_load();
    }
}

// Função que troca de Lugar e atribui o novo jogador no rank
void org_top5(JOGADOR r[], int pts_novos, int ind, char nome_recorde[])
{
    JOGADOR novoj, temp1, temp2;
    novoj.pontos = pts_novos;

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

int processar_nome(char nome_recorde[], int *ind)
{
    char tecla = GetCharPressed();
    int flag = 0;

    while (tecla != NULL)
    {
        if ((tecla >= 32) && (tecla <= 122) && (*ind < 7))
        {
            nome_recorde[*ind] = tecla;
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


    if (IsKeyPressed(KEY_ENTER) && *ind > 3)
    {
        flag = 1;
    }

    return flag;
}

void desenhar_nome(char nome_atual[])
{
    Rectangle textBox = { 300, 370, 360, 70 };

    DrawText("NOVO RECORDE!", 480 - MeasureText("NOVO RECORDE!", TAM_DEFAULT + 5)/2, 150, TAM_DEFAULT + 5, YELLOW);
    DrawText("DIGITE SEU NOME:", 480 - MeasureText("DIGITE SEU NOME:", TAM_DEFAULT - 40)/2, 300, TAM_DEFAULT - 40, YELLOW); // Branco/Claro para contraste
    DrawText("Pressione [ENTER] para confirmar", 480 - MeasureText("Pressione [ENTER] para confirmar", TAM_DEFAULT - 60)/2, 500, TAM_DEFAULT - 60, YELLOW);
    DrawRectangleRec(textBox, RAYWHITE);
    DrawRectangleLinesEx(textBox, 4, YELLOW);
    DrawText(nome_atual, textBox.x + 15, textBox.y + 15, 50, BLACK);
}

void organizar_rank(int pts_atual, JOGADOR ranking[], Sound yeah)
{
    int indice_rank = -1; //Flag para começar a coleta do nome

    for(int i = 0; i < 5; i++)
    {
        if(pts_atual > ranking[i].pontos)
        {
            indice_rank = i;
            PlaySound(yeah);
            break;
        }
    }

    //Inicio da coleta do nome
    if(indice_rank != -1)
    {
        char nome_recorde[8] = {0};
        int cont_ind = 0;
        int nome_finalizado = 0;

        while(!nome_finalizado)
        {
            nome_finalizado = processar_nome(nome_recorde, &cont_ind);

            BeginDrawing();
                ClearBackground(DARKBLUE);
                desenhar_nome(nome_recorde);
            EndDrawing();
        }

        org_top5(ranking, pts_atual, indice_rank, nome_recorde);
        salva_arquivo("highscore.bin", ranking);
    }
}
