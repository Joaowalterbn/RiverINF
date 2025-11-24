#include "config_function.h"

SPRITE definir_sprites(int x, int y, Texture2D txt, char tipo){
    Rectangle hitbox = {
        x,
        y,
        txt.width *0.8f,
        txt.height*0.8f
    };
    SPRITE s = {
        1,
        tipo,
        hitbox
    };
    return s;
}
