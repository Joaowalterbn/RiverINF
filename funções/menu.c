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
    DrawText("Sair", 100, 450, TAM_DEFAULT, YELLOW);
    Rectangle sair =
    {
        X_TITLE,
        450,
        MeasureText("Sair", TAM_DEFAULT),
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

    if (CheckCollisionPointRec(GetMousePosition(), sair))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 's';
            return op;
        }
    }



}

#include "config_function.h"

char pause(void)
{
    char op;
    BeginDrawing();
    DrawRectangle(0, 0, 960, 800, Fade(WHITE, 0.01f));
    DrawText("Continuar", 300, 230, TAM_DEFAULT, YELLOW);
    Rectangle Continuar =
    {
        300,
        230,
        MeasureText("Continuar", TAM_DEFAULT),
        TAM_DEFAULT
    };
    DrawText("Menu", 300, 340, TAM_DEFAULT, YELLOW);
    Rectangle Menu =
    {
        300,
        340,
        MeasureText("MENU", TAM_DEFAULT),
        TAM_DEFAULT
    };
    DrawText("Sair", 300, 450, TAM_DEFAULT, YELLOW);
    Rectangle Sair =
    {
        300,
        450,
        MeasureText("Sair", TAM_DEFAULT),
        TAM_DEFAULT
    };
    EndDrawing();


    if (IsCursorHidden())
    {
        ShowCursor();
    }

    if (CheckCollisionPointRec(GetMousePosition(), Continuar))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'c';
            return op;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), Menu))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'm';
            return op;
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), Sair))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 's';
            return op;
        }
    }



}

