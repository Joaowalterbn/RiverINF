#include "config_function.h"

//Função que corrige os erros de multiplas funções com ponteiros

void altera_sprites(Texture2D *txt, Texture2D nova){
    *txt = nova;
}
