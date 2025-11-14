#include "config_function.h"

char menu(void)
{
    char op;
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("RIVERINF", X_TITLE, 100, TAM_TITLE, YELLOW);
    DrawText("Novo jogo", X_TITLE, 230, TAM_DEFAULT, YELLOW);
    Rectangle novo_jogo =
    {
        X_TITLE,
        230,
        MeasureText("Novo jogo", TAM_DEFAULT),
        TAM_DEFAULT
    };
    DrawText("Ranking", 100, 340, TAM_DEFAULT, YELLOW);
    Rectangle ranking =
    {
        X_TITLE,
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
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'g';
            return op;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), ranking))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'r';
            return op;
        }
    }



}
