#include "config_function.h"

int main()
{
    GameScreen tela_atual = MENU;
    Fase fase_atual;
    bool mapa_carregado = false;

    SPRITE vetor_hitboxs[480] = {0};
    int quant_hitboxs;
    int x_aviao, y_aviao, pontuacao, vidas, combustivel, nivel, velocidade;

    InitWindow(960, 800, "RiverINF");
    SetTargetFPS(60);

    Rectangle hud =
    {
        0,
        0,
        960,
        40
    };

    TIRO projetil = {0};

    Texture2D tiro = LoadTexture("sprites/projectile.png");
    Texture2D vida = LoadTexture("sprites/heart.png");
    Texture2D terra = LoadTexture("sprites/land.png");
    Texture2D heli_1 = LoadTexture("sprites/helicopter_1.png");

    Texture2D planeCenter = LoadTexture("sprites/plane.png");
    Texture2D planeRight = LoadTexture("sprites/planetoright.png");
    Texture2D planeLeft = LoadTexture("sprites/planetoleft.png");

    Texture2D current_plane_texture = planeCenter;

    Rectangle player_hitbox = {0};

    while(!WindowShouldClose())
    {
        switch(tela_atual)
        {
        case MENU:
        {
            if(menu() == 'g')
            {
                tela_atual = TROCA;
                velocidade = 2;
                vidas = 3;
                nivel = 1;
                pontuacao = 0;
                combustivel = 100;
                fase_atual = 0;
            }
            else if(menu() == 'r')
            {
                tela_atual = RANK;
            }
            break;
        }
        case TROCA:
            {
                if(!mapa_carregado){
                    switch(fase_atual){
                    case FASE1:
                        quant_hitboxs = le_mapa("mapas/mapa1.txt", vetor_hitboxs, current_plane_texture, terra, heli_1, &x_aviao, &y_aviao);
                        break;
                    case FASE2:
                        quant_hitboxs = le_mapa("mapas/mapa1.txt", vetor_hitboxs, current_plane_texture, terra, heli_1, &x_aviao, &y_aviao);
                        break;
                    case FASE3:
                        quant_hitboxs = le_mapa("mapas/mapa1.txt", vetor_hitboxs, current_plane_texture, terra, heli_1, &x_aviao, &y_aviao);
                        break;
                    case FASE4:
                        quant_hitboxs = le_mapa("mapas/mapa1.txt", vetor_hitboxs, current_plane_texture, terra, heli_1, &x_aviao, &y_aviao);
                        break;
                    case FASE5:
                        quant_hitboxs = le_mapa("mapas/mapa1.txt", vetor_hitboxs, current_plane_texture, terra, heli_1, &x_aviao, &y_aviao);
                        break;
                    } mapa_carregado = true;
                }
            }

        case GAMEPLAY:
        {
            if(vidas <= 0){
                tela_atual = MENU;
                mapa_carregado = false;
            }

            player_hitbox = move_player(
                                &x_aviao,
                                &y_aviao,
                                &current_plane_texture,
                                planeCenter,
                                planeLeft,
                                planeRight,
                                velocidade
                            );

            if(!projetil.flag)
            {
                if(IsKeyPressed(KEY_SPACE))
                    projetil = fshoot(x_aviao, y_aviao, tiro);
            }



            BeginDrawing();
            ClearBackground(DARKBLUE);
            desenhar_mapa(quant_hitboxs, vetor_hitboxs, terra, heli_1);

            DrawTexture(current_plane_texture, x_aviao, y_aviao, WHITE);
            DrawRectangleRec(player_hitbox, Fade(RED, 0.5f));


            //Desenha o projétil
            if(projetil.flag)
            {
                DrawTexture(tiro, projetil.sprite_tiro.x, projetil.sprite_tiro.y, WHITE);
                projetil.sprite_tiro.y -= 30;
                if(projetil.sprite_tiro.y < 0) projetil.flag = 0;
            }

            //Desenha a hud
            DrawRectangleRec(hud, BLACK);
            DrawText("Vidas: ", 10, 10, 30, YELLOW);
            for(int life = 0; life < vidas; life++)
            {
                DrawTexture(vida, (life * 30 + MeasureText("Vidas: ", 30)+ 10), 10, WHITE);
            }

            DrawText(TextFormat("Nivel: %i", nivel), 210, 10, 30, YELLOW);
            DrawText(TextFormat("Fuel: %i", combustivel), 360, 10, 30, YELLOW);
            DrawText(TextFormat("Score: %i", pontuacao), 520, 10, 30, YELLOW);

            EndDrawing();
            checar_colisao(vetor_hitboxs, quant_hitboxs, projetil, &(projetil.flag), player_hitbox, &pontuacao, &vidas, &x_aviao, &y_aviao);
            if(CheckCollisionRecs(hud, player_hitbox)) {
                    tela_atual = TROCA;
                    fase_atual++;
                    mapa_carregado = false;
                    nivel++;
            }
            break;
        }
        case RANK:
        {
            if (CheckCollisionPointRec(GetMousePosition(), print_rank()))
            {
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    tela_atual = MENU;
                }
            }
        }

        }//fechamento do switch
    }


    //Final - Descarregar
    UnloadTexture(planeCenter);
    UnloadTexture(planeRight);
    UnloadTexture(planeLeft);
    UnloadTexture(tiro);

    CloseWindow();
    return 0;
}

