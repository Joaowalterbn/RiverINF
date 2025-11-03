#include "config_function.h"
#include "raylib.h"

void move_player(int *x, int *y, Texture2D plane)
{
    if(IsKeyDown(KEY_W))
    {
        *y -= 5;
    }
    if(IsKeyDown(KEY_S))
    {
        *y += 5;
    }
    if(IsKeyDown(KEY_D))
    {
        *x += 5;
        plane = LoadTexture("sprites/planetoright.png");
    }
    if(IsKeyDown(KEY_A))
    {
        *x -= 5;
        plane = LoadTexture("sprites/planetoleft.png");
    }


    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawTexture(plane, *x, *y, WHITE);
    EndDrawing();

    if(!IsKeyDown(KEY_D) && !IsKeyDown(KEY_A))plane = LoadTexture("sprites/plane.png");
}

