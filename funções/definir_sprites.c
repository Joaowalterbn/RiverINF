#include "config_function.h"

SPRITE definir_sprites(int x, int y, Texture2D txt, char tipo){
    float escala = 0.8;
    Rectangle hitbox = {
        x + ((float)txt.width - (float)txt.width * escala) / 2.0f,
        y + ((float)txt.height - (float)txt.height * escala) / 2.0f,
        txt.width *escala,
        txt.height*escala
    };
    SPRITE s = {
        1,
        tipo,
        hitbox
    };
    return s;
}
