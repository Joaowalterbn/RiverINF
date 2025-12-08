#include "config_function.h"

//Função que cria o tiro

TIRO fshoot(int x, int y, Texture2D t)
{
    Rectangle shoot =
    {
        x + 20,
        y - (float)t.height,
        (float)t.width,
        (float)t.height
    };
    TIRO tiro =
    {
        1,
        shoot
    };
    return tiro;
}


