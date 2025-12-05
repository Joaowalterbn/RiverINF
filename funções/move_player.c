#include "config_function.h"

Rectangle move_player(int *x, int *y, Texture2D *plane_atual, Texture2D plane_center, Texture2D plane_left, Texture2D plane_right, int velocidade_y)
{
    float velocidade = velocidade_y * 1.5, PosX = *x, PosY = *y;
    float escala = 0.6; //Escala de diminuição da hitbox do player, mais uma correção para colisões injustas
    float original_alt, original_larg, larg_offset, alt_offset, hitbox_larg, hitbox_alt;
    Texture2D aviao = *plane_atual;

    //Atualiza a posição y
    PosY -= velocidade_y;
    altera_variaveis(y, PosY);


    if (IsKeyDown(KEY_D))
    {
        PosX += velocidade;
        altera_variaveis(x, PosX);
        aviao = plane_right;
    }
    else if (IsKeyDown(KEY_A))
    {
        PosX -= velocidade;
        altera_variaveis(x, PosX);
        aviao = plane_left;
    }
    else
    {

        aviao = plane_center;
    }
    altera_sprites(plane_atual, aviao);

    //Correção da hitbox
    original_larg = (float)plane_atual->width; //equivalente a (*plane_atual).width
    original_alt = (float)plane_atual->height; //equivalente a (*plane_atual).height

    hitbox_larg = original_larg * escala;
    hitbox_alt = original_alt * escala;

    larg_offset = (original_larg - hitbox_larg) / 2.0f;
    alt_offset = (original_alt - hitbox_alt) / 2.0f;

    //Cria a hitbox
    Rectangle player_hitbox =
    {
        (float)*x + larg_offset,
        (float)*y + alt_offset,
        hitbox_larg,
        hitbox_alt
    };

    return player_hitbox;
}
