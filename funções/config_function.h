// config_function.h

#ifndef CONFIG_FUNCTION_H
#define CONFIG_FUNCTION_H

#include "raylib.h"
#include <stdio.h>

#define TAM_DEFAULT 90
#define TAM_RANK 50
#define TAM_TITLE 130
#define MAXSCORES 5
#define ARQ_NOME "top5.bin"
#define X_TITLE 100
#define PTS_H 60
#define PTS_P 200
#define PTS_N 30

typedef enum GameScreen
{
    MENU = 0,
    RANK,
    TROCA,
    GAMEPLAY,
    ENDGAME
} GameScreen;

typedef enum Fase
{
    FASE1 = 0,
    FASE2,
    FASE3,
    FASE4,
    FASE5,

} Fase;

typedef struct
{
    int flag;
    Rectangle sprite_tiro;
}TIRO;

typedef struct
{
    int flag;
    char tipo;
    Rectangle ini;
}SPRITE;

typedef struct
{
    char nome[45];
    int pontos;
} JOGADOR;

Rectangle move_player(int *x, int *y, Texture2D *plane_atual, Texture2D plane_center, Texture2D plane_left, Texture2D plane_right, int velocidade_y);

char menu(void);

Rectangle print_rank(void);

void erro_load(void);

void le_arquivo(char nome_arq[], JOGADOR top5[MAXSCORES]);

void salva_arquivo(char nome_arq[], JOGADOR top5[MAXSCORES]);

int le_mapa(char nome_arq[], SPRITE v[],Texture2D A, Texture2D T, Texture2D X, int *x_aviao, int *y_aviao);

void desenhar_mapa(int nblocos, SPRITE v[], Texture2D T, Texture2D X);

TIRO fshoot(int x, int y, Texture2D t);

SPRITE definir_sprites(int x, int y, Texture2D txt, char tipo);

SPRITE definir_terrenos(int x, int y, Texture2D txt, char tipo);

void checar_colisao(SPRITE v[], int nblocos, TIRO projetil, int *flag_tiro, Rectangle aviao, int *pontos, int *vidas, int *x, int *y);

void altera_variaveis(int *v, int novo);

void altera_sprites(Texture2D *txt, Texture2D nova);

#endif // CONFIG_FUNCTION_H
