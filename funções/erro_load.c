#include "config_function.h"

//Função tosca de erro, que tomara que não seja utilizada

void erro_load(void)
{
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("Erro ao carregar arquivo", 500, 500, TAM_DEFAULT, RED);
    EndDrawing();
}
