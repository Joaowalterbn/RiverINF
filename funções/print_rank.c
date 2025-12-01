#include "config_function.h"

Rectangle print_rank(void)
{
    int z = 100;
    JOGADOR ranking[MAXSCORES];
    le_arquivo(ARQ_NOME, ranking);
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("NOME--------------------PONTOS", X_TITLE - TAM_RANK, z - (TAM_RANK + 20), TAM_RANK, YELLOW);
    for(int i = 0; i < MAXSCORES; i++)
    {
        DrawText(ranking[i].nome, X_TITLE, z, TAM_RANK, YELLOW);
        DrawText(TextFormat("%d", i+ 1), X_TITLE - TAM_RANK, z, TAM_RANK, YELLOW);
        DrawText(TextFormat("%d", ranking[i].pontos), 800 - X_TITLE, z, TAM_RANK, YELLOW);
        z += 100;
    }
    DrawRectangle(490 - X_TITLE, z - 20, MeasureText("Voltar", TAM_DEFAULT)+20, TAM_DEFAULT+40, YELLOW);
    DrawText("Voltar", 500 - X_TITLE, z, TAM_DEFAULT, DARKBLUE);
    Rectangle voltar =
    {
        490 - X_TITLE,
        z - 20,
        MeasureText("Voltar", TAM_DEFAULT)+20,
        TAM_DEFAULT+40
    };
    EndDrawing();
    return voltar;
}


