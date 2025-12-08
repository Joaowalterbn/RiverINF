#include "config_function.h"
//Função que desenha o menu principal, cria os botões e retorna um char ao serem clicados
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
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), ranking))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'r';
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), sair))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 's';
        }
    }

    return op;

}

//Parecida com a menu(), mas tira a logo e adiciona alguns botões diferentes
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
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), Menu))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'm';
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), Sair))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 's';
        }
    }

     return op;

}

//Mesma ideia, mas ela printa a mensagem de Game Over e a pontuação final do jogador
char pos_game(int pts)
{
    char op;

    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("GAME OVER", 480 - MeasureText("GAME OVER", TAM_TITLE)/2, 50, TAM_TITLE, YELLOW);
    DrawText(TextFormat("Score: %d", pts), 480 - MeasureText(TextFormat("Score: %d", pts), TAM_DEFAULT)/2, 230, TAM_DEFAULT, YELLOW);

    DrawText("Novo jogo", X_TITLE, 340, TAM_DEFAULT, YELLOW);
    Rectangle novo_jogo =
    {
        X_TITLE,
        340,
        MeasureText("Novo jogo", TAM_DEFAULT),
        TAM_DEFAULT
    };
    DrawText("Ranking", 100, 450, TAM_DEFAULT, YELLOW);
    Rectangle ranking =
    {
        X_TITLE,
        450,
        MeasureText("Ranking", TAM_DEFAULT),
        TAM_DEFAULT
    };
    DrawText("MENU", 100, 560, TAM_DEFAULT, YELLOW);
    Rectangle m =
    {
        X_TITLE,
        560,
        MeasureText("MENU", TAM_DEFAULT),
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
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), ranking))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'r';
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), m))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            op = 'm';
        }
    }

    return op;

}

