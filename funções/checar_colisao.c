#include "config_function.h"
//Função que checa as colisões do tiro com os inimigos e do avião com todas as estruturas e inimigos
//Tira vidas dos inimigos e do jogador
//Faz as animações de explosões e ainda toca os audios
//Não precisa retornar nada, pois faz uso de alterações através de ponteiros
void checar_colisao(SPRITE v[], int nblocos, TIRO projetil, int *flag_tiro, Rectangle aviao, int *pontos, int *vidas, int *x, int *y, float *gas, Texture2D exp, Sound bomb, int *invulnerabilidade_timer)
{
    for(int i = 0; i < nblocos; i++)
    {
        int flag = v[i].flag, tiro_ativo = *flag_tiro, life = *vidas, pts = *pontos;
        if(flag)
        {
            char c = v[i].tipo; //Tipo da Sprite atual
            Rectangle atual = v[i].ini;//Hitbox da Sprite atual
            switch(c)
            {
            case'T':
                if(CheckCollisionRecs(aviao, atual)&& *invulnerabilidade_timer <= 0)
                {
                    DrawTexture(exp, atual.x, atual.y, WHITE);
                    PlaySound(bomb);
                    life--;
                    altera_variaveis(vidas, life);
                    altera_variaveis(x, 450);
                    altera_variaveis(y, 750);
                    altera_variaveis(invulnerabilidade_timer, 60);//Para evitar dupla colisão
                }
                break;
            case'G':
                if(CheckCollisionRecs(aviao, atual))
                {
                    if(*gas <= 99) *gas = *gas + 1;
                }
                if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo)
                {
                    v[i].flag-= 1;
                    tiro_ativo = 0;
                    if(v[i].flag <= 0)
                    {
                        DrawTexture(exp, atual.x, atual.y, WHITE);
                        PlaySound(bomb);
                        pts += PTS_G;
                        altera_variaveis(pontos, pts);
                    }
                }
                break;
            case'X':
                if(CheckCollisionRecs(aviao, atual)&& *invulnerabilidade_timer <= 0)
                {
                    DrawTexture(exp, atual.x, atual.y, WHITE);
                    life--;
                    altera_variaveis(vidas, life);
                    altera_variaveis(x, 450);
                    altera_variaveis(y, 750);
                    altera_variaveis(invulnerabilidade_timer, 60);
                }
                if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo)
                {
                    v[i].flag-= 1;
                    tiro_ativo = 0;
                    if(v[i].flag <= 0)
                    {
                        DrawTexture(exp, atual.x, atual.y, WHITE);
                        PlaySound(bomb);
                        pts += PTS_H;//pontos helicoptero;
                        altera_variaveis(pontos, pts);
                    }
                }
                break;
            case'J':
                if(CheckCollisionRecs(aviao, atual)&& *invulnerabilidade_timer <= 0)
                {
                    DrawTexture(exp, atual.x, atual.y, WHITE);
                    PlaySound(bomb);
                    life--;
                    altera_variaveis(vidas, life);
                    altera_variaveis(x, 450);
                    altera_variaveis(y, 750);
                    altera_variaveis(invulnerabilidade_timer, 60);
                }
                if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo)
                {
                    v[i].flag-= 1;
                    tiro_ativo = 0;
                    if(v[i].flag <= 0)
                    {
                        DrawTexture(exp, atual.x, atual.y, WHITE);
                        PlaySound(bomb);
                        pts += PTS_J;//pontos jato;
                        altera_variaveis(pontos, pts);
                    }
                }
                break;
                case'N':
                if(CheckCollisionRecs(aviao, atual)&& *invulnerabilidade_timer <= 0)
                {
                    DrawTexture(exp, atual.x, atual.y, WHITE);
                    life--;
                    altera_variaveis(vidas, life);
                    altera_variaveis(x, 450);
                    altera_variaveis(y, 750);
                    altera_variaveis(invulnerabilidade_timer, 60);
                }
                if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo)
                {
                    v[i].flag-= 1;
                    tiro_ativo = 0;
                    if(v[i].flag <= 0)
                    {
                        DrawTexture(exp, atual.x, atual.y, WHITE);
                        PlaySound(bomb);
                        pts += PTS_J;//pontos jato;
                        altera_variaveis(pontos, pts);
                    }
                }
                break;
            case'B':
                if(CheckCollisionRecs(aviao, atual)&& *invulnerabilidade_timer <= 0)
                {
                    DrawTexture(exp, atual.x, atual.y, WHITE);
                    PlaySound(bomb);
                    life--;
                    altera_variaveis(vidas, life);
                    altera_variaveis(x, 450);
                    altera_variaveis(y, 750);
                    altera_variaveis(invulnerabilidade_timer, 60);
                }
                if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo)
                {
                    v[i].flag -= 1;
                    tiro_ativo = 0;
                    if(v[i].flag <= 0)
                    {
                        DrawTexture(exp, atual.x, atual.y, WHITE);
                        pts += PTS_P;//pontos Ponte;
                        altera_variaveis(pontos, pts);
                    }
                }
                break;
            }
            altera_variaveis(flag_tiro, tiro_ativo);

        }
    }
}
