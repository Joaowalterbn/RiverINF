
#include <raylib.h>
#include "config_function.h"

typedef enum GameScreen {
    MENU = 0,
    RANK,
    GAMEPLAY,
    TROCA,
    ENDGAME
    } GameScreen;

int main()
{

    GameScreen tela_atual = MENU;
    int x = 300, y = 700;


    InitWindow(960, 800, "RiverINF");
    SetTargetFPS(60);

    Texture2D planeCenter = LoadTexture("sprites/plane.png");
    Texture2D planeRight = LoadTexture("sprites/planetoright.png");
    Texture2D planeLeft = LoadTexture("sprites/planetoleft.png");

    Texture2D current_plane_texture = planeCenter;

    Rectangle player_hitbox = {0};

    while(!WindowShouldClose())
    {
        switch(tela_atual){
        case MENU:
            {
                if(menu() == 'g')
                    {
                        tela_atual = GAMEPLAY;
                    }
                else if(menu() == 'r')
                    {
                        tela_atual = RANK; //NÃO APERTAR O BOTAO DO RANKING PORQUE NAO CONFIGUREI ESSA TELA RANK ENT VAI TRAVAR O EXECUTAVEL
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


                BeginDrawing();

                    ClearBackground(DARKBLUE);
                    DrawTexture(current_plane_texture, x, y, WHITE);
                    DrawRectangleRec(player_hitbox, Fade(RED, 0.4f));


                EndDrawing();
                break;
            }

        }
    }


   //Final - Descarregar
    UnloadTexture(planeCenter);
    UnloadTexture(planeRight);
    UnloadTexture(planeLeft);

    CloseWindow();
    return 0;
    }

