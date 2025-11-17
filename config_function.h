// config_function.h

#ifndef CONFIG_FUNCTION_H
#define CONFIG_FUNCTION_H

#include <raylib.h>
#include <stdio.h>

#define TAM_DEFAULT 90
#define TAM_RANK 50
#define TAM_TITLE 130
#define MAXSCORES 5
#define ARQ_NOME "top5.bin"
#define X_TITLE 100

typedef enum GameScreen
{
    MENU = 0,
    RANK,
    GAMEPLAY,
    TROCA,
    ENDGAME
} GameScreen;

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

Rectangle move_player(int *x, int *y, Texture2D *plane_atual, Texture2D plane_center, Texture2D plane_left, Texture2D plane_right);

char menu(void);

Rectangle print_rank(void);

void erro_load(void);

void le_arquivo(char nome_arq[], JOGADOR top5[MAXSCORES]);

void salva_arquivo(char nome_arq[], JOGADOR top5[MAXSCORES]);

TIRO fshoot(int x, int y, Texture2D t);

SPRITE definir_sprites(int x, int y, Texture2D txt, char tipo);

#endif // CONFIG_FUNCTION_H
