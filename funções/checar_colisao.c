#include "config_function.h"

void checar_colisao(SPRITE v[], int nblocos, TIRO projetil, Rectangle aviao, int *pontos, int *vidas, int *x, int *y){
    for(int i = 0; i < nblocos; i++){
        int flag = v[i].flag, tiro_ativo = projetil.flag, life = *vidas, pts = *pontos;
        if(flag){
            char c = v[i].tipo;
            Rectangle atual = v[i].ini;
            switch(c){
                case'T':
                    if(CheckCollisionRecs(aviao, atual)){
                            life--;
                            altera_variaveis(vidas, life);
                            altera_variaveis(x, 450);
                            altera_variaveis(y, 750);
                    }
                    break;
                case'X':
                        if(CheckCollisionRecs(aviao, atual)){
                            life--;
                            altera_variaveis(vidas, life);
                            altera_variaveis(x, 450);
                            altera_variaveis(y, 750);
                        }
                         if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo){
                            v[i].flag = 0;
                            pts += PTS_H;//pontos helicoptero;
                            altera_variaveis(pontos, pts);
                         }
                        break;
                case'P':
                        if(CheckCollisionRecs(aviao, atual)){
                            life--;
                            altera_variaveis(vidas, life);
                            altera_variaveis(x, 450);
                            altera_variaveis(y, 750);
                        }
                         if(CheckCollisionRecs(projetil.sprite_tiro, atual)&& tiro_ativo){
                            v[i].flag -= 1;
                            int flagPonte = v[i].flag;
                            if(flagPonte <= 0){
                                pts += PTS_P;//pontos Ponte;
                                altera_variaveis(pontos, pts);
                            }
                         }
                        break;
            }
        }
    }
}
