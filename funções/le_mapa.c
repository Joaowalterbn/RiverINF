#include "config_function.h"
//Função que lê os .txt e gera o mapa, colocando no array das hitbox todos os terrenos e inimigos e que ainda posiciona o avião
int le_mapa(char nome_arq[], SPRITE v[],Texture2D A, Texture2D T, Texture2D X, Texture2D G, Texture2D N, Texture2D J,Texture2D S, Texture2D B, Texture2D H, int *x_aviao, int *y_aviao)
{
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
                v[i] = definir_terrenos(posX, posY, T, 'T', 1);
                i++;
                posX += 40;
                break;
            case'X':
                v[i] = definir_sprites(posX, posY, X, 'X', 2);
                i++;
                posX += 40;
                break;
            case' ':
                posX += 40;
                break;
            case'G':
                v[i] = definir_terrenos(posX, posY, G, 'G', 1);
                i++;
                posX += 40;
                break;
            case'N':
                v[i] = definir_sprites(posX, posY, N, 'N', 1);
                i++;
                posX += 40;
                break;
            case'J':
                v[i] = definir_sprites(posX, posY, J, 'J', 1);
                i++;
                posX += 40;
                break;
            case'B':
                v[i] = definir_terrenos(posX, posY, B, 'B', 3);
                i++;
                posX += 40;
                break;
            case'S':
                v[i] = definir_terrenos(posX, posY, S, 'S', 1);
                i++;
                posX += 40;
                break;
            case'H':
                v[i] = definir_terrenos(posX, posY, H, 'H', 1);
                i++;
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

//Função que de fato desenha o mapa após ele ser lido pela anterior
//Desenha a partir da hitbox, por isso inverti a lógica de diminuir a hitbox utilizando o inverso da fórmula para atribuir x e y nos inimigos
void desenhar_mapa(int nblocos, SPRITE v[], Texture2D T, Texture2D X, Texture2D G, Texture2D N, Texture2D J, Texture2D S, Texture2D B, Texture2D H)
{
    char c;
    int flag;
    for(int i = 0; i < nblocos; i++)
    {
        c = v[i].tipo;
        if(v[i].flag > 0) flag = 1;
        else flag = 0;
        if(flag)
        {
            switch(c)
            {
            case'T':
                DrawTexture(T, v[i].ini.x, v[i].ini.y, WHITE);
                //DrawRectangleRec(v[i].ini,Fade(RED, 0.1f));
                break;
            case'G':
                DrawTexture(G, v[i].ini.x, v[i].ini.y, WHITE);
                //DrawRectangleRec(v[i].ini,Fade(RED, 0.5f));
                break;
            }
        }
    }
    for(int i = 0; i < nblocos; i++)
    {
        c = v[i].tipo;
        if(v[i].flag > 0) flag = 1;
        else flag = 0;
        if(flag)
        {
            switch(c)
            {
            case'X':
                DrawTexture(X, v[i].ini.x - ((float)X.width - (float)X.width * 0.8) / 2.0f, v[i].ini.y - ((float)X.height - (float)X.height * 0.8) / 2.0f, WHITE);
                //DrawRectangleRec(v[i].ini,Fade(RED, 0.5f));
                break;
            case'N':
                DrawTexture(N, v[i].ini.x - ((float)N.width - (float)N.width * 0.8) / 2.0f, v[i].ini.y - ((float)N.height - (float)N.height * 0.8) / 2.0f, WHITE);
                //DrawRectangleRec(v[i].ini,Fade(RED, 0.5f));
                break;
            case'J':
                DrawTexture(J, v[i].ini.x - ((float)J.width - (float)J.width * 0.8) / 2.0f, v[i].ini.y - ((float)J.height - (float)J.height * 0.8) / 2.0f, WHITE);
                //DrawRectangleRec(v[i].ini,Fade(RED, 0.5f));
                break;
            case'S':
                DrawTexture(S, v[i].ini.x, v[i].ini.y, WHITE);
                break;
            case'B':
                DrawTexture(B, v[i].ini.x, v[i].ini.y, WHITE);
                break;
            case'H':
                DrawTexture(H, v[i].ini.x, v[i].ini.y, WHITE);
                break;
            }
        }
    }
}
