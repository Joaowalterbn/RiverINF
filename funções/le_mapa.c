#include "config_function.h"

int le_mapa(char nome_arq[], SPRITE v[],Texture2D A, Texture2D T, Texture2D X, int *x_aviao, int *y_aviao){
    FILE *fp = fopen(nome_arq, "r");
    int posX = 0;
    int posY = 0;
    int i = 0;
    int x = *x_aviao, y = *y_aviao;

    if(fp != NULL)
    {
       while(!feof(fp))
       {
            switch(fgetc(fp))
            {
                case'A':
                        x = posX;
                        y = posY - 20;
                        altera_variaveis(x_aviao, x);
                        altera_variaveis(y_aviao, y);
                        i++;
                        posX += 40;
                        break;
                case'T':
                        v[i] = definir_terrenos(posX, posY, T, 'T');
                        i++;
                        posX += 40;
                        break;
                case'X':
                        v[i] = definir_sprites(posX, posY, X, 'X', 2);
                        i++;
                        posX += 40;
                        break;
                case'R':
                        posX += 40;
                        break;
                case'\n':
                        posX = 0;
                        posY += 40;
                        break;
            }
       }
    }
    else printf("Erro!\n");
    fclose(fp);

return i;
}

void desenhar_mapa(int nblocos, SPRITE v[], Texture2D T, Texture2D X)
{
    for(int i = 0; i < nblocos; i++){
        char c = v[i].tipo;
        int flag;
        if(v[i].flag > 0) flag = 1;
        else flag = 0;
        if(flag){
            switch(c)
                    {
                        case'T':
                                DrawTexture(T, v[i].ini.x, v[i].ini.y, WHITE);
                                //DrawRectangleRec(v[i].ini,Fade(RED, 0.1f));
                                break;
                        case'X':
                                DrawRectangle(v[i].ini.x, v[i].ini.y, 40, 40, DARKBLUE);
                                DrawTexture(X, v[i].ini.x - ((float)X.width - (float)X.width * 0.8) / 2.0f, v[i].ini.y - ((float)X.height - (float)X.height * 0.8) / 2.0f, WHITE);
                                //DrawRectangleRec(v[i].ini,Fade(RED, 0.5f));
                                break;

                    }
        }
    }
}
