#include "config_function.h"

int main()
{
    GameScreen tela_atual = MENU;

    int x = 300, y = 700;

    InitWindow(960, 800, "RiverINF");
    SetTargetFPS(60);

    TIRO projetil = {0};

    Texture2D tiro = LoadTexture("sprites/projectile.png");

    Texture2D planeCenter = LoadTexture("sprites/plane.png");
    Texture2D planeRight = LoadTexture("sprites/planetoright.png");
    Texture2D planeLeft = LoadTexture("sprites/planetoleft.png");

    Texture2D current_plane_texture = planeCenter;

    Rectangle player_hitbox = {0};

    while(!WindowShouldClose())
    {
        switch(tela_atual)
        {
        case MENU:
        {
            if(menu() == 'g')
            {
                tela_atual = GAMEPLAY;
            }
            else if(menu() == 'r')
            {
                tela_atual = RANK;
            }
            break;
        }

        case GAMEPLAY:
        {
            player_hitbox = move_player(
                                &x,
                                &y,
                                &current_plane_texture,
                                planeCenter,
                                planeLeft,
                                planeRight
                            );

            if(!projetil.flag){
                if(IsKeyPressed(KEY_SPACE))
                    projetil = fshoot(x, y, tiro);
            }



            BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawTexture(current_plane_texture, x, y, WHITE);
            if(projetil.flag){
                DrawTexture(tiro, projetil.sprite_tiro.x, projetil.sprite_tiro.y, WHITE);
                projetil.sprite_tiro.y -= 30;
                if(projetil.sprite_tiro.y < 0) projetil.flag = 0;
            }
            EndDrawing();
            break;
        }
        case RANK:
        {
            if (CheckCollisionPointRec(GetMousePosition(), print_rank()))
            {
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    tela_atual = MENU;
                }
            }
        }

        }//fechamento do switch
    }


    //Final - Descarregar
    UnloadTexture(planeCenter);
    UnloadTexture(planeRight);
    UnloadTexture(planeLeft);
    UnloadTexture(tiro);

    CloseWindow();
    return 0;
}

