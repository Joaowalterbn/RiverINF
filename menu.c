#include "config_function.h"
#include <raylib.h>

char menu(void){
    char op;
     BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("RIVERINF", 100, 100, TAM_TITLE, YELLOW);
        DrawText("Novo jogo", 100, 230, TAM_DEFAULT, YELLOW);
        Rectangle novo_jogo = {
            100,
            230,
            MeasureText("Novo jogo", TAM_DEFAULT),
            TAM_DEFAULT
        };
        DrawText("Ranking", 100, 340, TAM_DEFAULT, YELLOW);
        Rectangle ranking = {
            100,
            340,
            MeasureText("Ranking", TAM_DEFAULT),
            TAM_DEFAULT
        };
    EndDrawing();

    if (IsCursorHidden())
            {
                ShowCursor();
            }

    if (CheckCollisionPointRec(GetMousePosition(), novo_jogo))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            op = 'g';
            return op;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), ranking))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            op = 'r';
            return op;
        }
    }



}
