#include "config_function.h"

//Função que retorna a struct SPRITE, que facilita a leitura de mapa e ainda reduz a hitbox dos inimigos para evitar injustiças
//Obs.: Utilizei uma formula da internet para reduzir as hitboxes e ainda elas acompanharem os inimigos/jogador

SPRITE definir_sprites(int x, int y, Texture2D txt, char tipo, int flag)
{
    float escala = 0.8;
    Rectangle hitbox =
    {
        x + ((float)txt.width - (float)txt.width * escala) / 2.0f,
        y + ((float)txt.height - (float)txt.height * escala) / 2.0f,
        txt.width *escala,
        txt.height*escala
    };
    SPRITE s =
    {
        flag,
        tipo,
        hitbox
    };
    return s;
}

//Função que retorna a struct SPRITE, que facilita a leitura de mapa
//Obs.: Essa não reduz as hitbox, afinal terrenos tem sprites bem definidas

SPRITE definir_terrenos(int x, int y, Texture2D txt, char tipo, int flag)
{
    Rectangle hitbox =
    {
        x,
        y,
        txt.width,
        txt.height
    };
    SPRITE s =
    {
        flag,
        tipo,
        hitbox
    };
    return s;
}
