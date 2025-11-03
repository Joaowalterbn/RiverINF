
#include <raylib.h>
#include "config_function.h"

int y = 700;
int x = 300;


int main()
{

    Texture2D plane;

    InitWindow(960, 800, "Teste");
    SetTargetFPS(60);

    plane = LoadTexture("sprites/plane.png");



    while(!WindowShouldClose())
    {

        move_player(&x, &y, plane);


    }

    UnloadTexture(plane);
    CloseWindow();

    return 0;
}
