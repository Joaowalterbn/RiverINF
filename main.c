
#include <raylib.h>
#include "config_function.h"

int main()
{

    int x = 300;
    int y = 700;

    InitWindow(960, 800, "RiverINF");
    SetTargetFPS(60);

    Texture2D planeCenter = LoadTexture("sprites/plane.png");
    Texture2D planeRight = LoadTexture("sprites/planetoright.png");
    Texture2D planeLeft = LoadTexture("sprites/planetoleft.png");

    Texture2D current_plane_texture = planeCenter;

    Rectangle player_hitbox = {0};

    while(!WindowShouldClose())
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
    }


   //Final - Descarregar
    UnloadTexture(planeCenter);
    UnloadTexture(planeRight);
    UnloadTexture(planeLeft);

    CloseWindow();
    return 0;
    }

