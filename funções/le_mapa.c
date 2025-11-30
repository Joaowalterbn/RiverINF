#include "config_function.h"

int le_mapa(char nome_arq[], SPRITE v[],Texture2D A, Texture2D T, Texture2D X){
    FILE *fp = fopen(nome_arq, "r");
    int posX = 0;
    int posY = 0;
    int i = 0;

    if(fp != NULL)
    {
       BeginDrawing();
       ClearBackground(DARKBLUE);
       while(!feof(fp))
       {
            switch(fgetc(fp))
            {
                case'A':
                        DrawRectangle(posX, posY, 40, 40, DARKBLUE);
                        DrawTexture(A, posX, posY, WHITE);
                        DrawRectangleRec(definir_sprites(posX, posY, A, 'A').ini,Fade(RED, 0.5f));
                        v[i] = definir_sprites(posX, posY, A, 'A');
                        i++;
                        posX += 40;
                        break;
                case'T':
                        DrawRectangle(posX, posY, 40, 40, DARKGREEN);
                        DrawTexture(T, posX, posY, WHITE);
                        DrawRectangleRec(definir_sprites(posX, posY, T, 'T').ini,Fade(RED, 0.5f));
                        v[i] = definir_sprites(posX, posY, T, 'T');
                        i++;
                        posX += 40;
                        break;
                case'X':
                        DrawRectangle(posX, posY, 40, 40, DARKBLUE);
                        DrawTexture(X, posX, posY, WHITE);
                        DrawRectangleRec(definir_sprites(posX, posY, X, 'X').ini,Fade(RED, 0.5f));
                        v[i] = definir_sprites(posX, posY, X, 'X');
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
       EndDrawing();
    }
    else printf("Erro!\n");
    fclose(fp);

return i;
}

/*
int main(void){
    InitWindow(960, 800, "RiverINF");
    SetTargetFPS(60);


    Texture2D A = LoadTexture("sprites/plane.png");
    Texture2D T = LoadTexture("sprites/land.png");
    Texture2D X = LoadTexture("sprites/helicopter_1.png");


    SPRITE vetor_hitboxs[480] = {0};
    int quant_hitboxs;

    while(!WindowShouldClose())
    {
        quant_hitboxs = le_mapa(MAPA1, vetor_hitboxs, A, T, X);
    }

return 0;
}
*/
