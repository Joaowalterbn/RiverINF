#include "config_function.h"

void att_inimigos(SPRITE v[], int nblocos, int velocidade)
{
    for(int i = 0; i < nblocos; i++){
        char c = v[i].tipo;
        int flag;
        bool virar = false;
        if(v[i].flag > 0) flag = 1;
        else flag = 0;
        if(flag){
            switch(c)
                    {
                        case'X':
                            if(v[i].ini.x >= 0 && v[i].ini.x < 960) v[i].ini.x += velocidade;
                            else v[i].ini.x = 0;
                                break;
                        /*case'N':

                                break;
                        */case'J':
                                if(v[i].ini.x >= 0 && v[i].ini.x <= 960) v[i].ini.x -= velocidade * 1.5;
                            else v[i].ini.x = 960;
                                break;
                    }
        }
    }
}

    /*typedef struct
{
    int flag;
    char tipo;
    Rectangle ini;
}SPRITE;
*/
