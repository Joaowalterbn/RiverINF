#include "config_function.h"
#include <raylib.h>


Rectangle move_player(int *x, int *y, Texture2D *plane_atual, Texture2D plane_center, Texture2D plane_left, Texture2D plane_right)
{
    int velocidade = 5;
    float escala = 0.8;
    float original_alt, original_larg, larg_offset, alt_offset, hitbox_larg, hitbox_alt;

    // 1. ATUALIZA POSIÇÃO E TEXTURA
    if (IsKeyDown(KEY_W)) *y -= velocidade;
    if (IsKeyDown(KEY_S)) *y += velocidade;

    if (IsKeyDown(KEY_D))
    {
        *x += velocidade;
        *plane_atual = plane_right;
    }
    else if (IsKeyDown(KEY_A))
    {
        *x -= velocidade;
        *plane_atual = plane_left;
    }
    else
    {

        *plane_atual = plane_center;
    }

    //Pegar a altura e largura da sprite para setar as dimensoes da hitbox
    original_larg = (float)plane_atual->width; //equivalente a (*plane_atual).width
    original_alt = (float)plane_atual->height; //equivalente a (*plane_atual).height

    hitbox_larg = original_larg * escala;
    hitbox_alt = original_alt * escala;

    larg_offset = (original_larg - hitbox_larg) / 2.0f;
    alt_offset = (original_alt - hitbox_alt) / 2.0f;

    // Cria o retângulo de colisão, aplicando a correção
    Rectangle player_hitbox = {
        (float)*x + larg_offset,
        (float)*y + alt_offset,
        hitbox_larg,
        hitbox_alt
    };

    return player_hitbox;
}
