#include "config_function.h"

int main()
{
    GameScreen tela_atual = MENU;
    Fase fase_atual;
    JOGADOR top_five[MAXSCORES], reset[MAXSCORES] = {0};
    //salva_arquivo("highscore.bin", reset);
    le_arquivo("highscore.bin", top_five);

    SPRITE vetor_hitboxs[480] = {0};

    int quant_hitboxs, deslocamento = 0, inv = 0, invulnerabilidade;
    int x_aviao, y_aviao, pontuacao, vidas, nivel, velocidade_ini, velocidade;
    float combustivel;
    bool mapa_carregado;

    InitWindow(960, 800, "RiverINF");
    InitAudioDevice();
    SetTargetFPS(60);

    Rectangle hud =
    {
        0,
        0,
        960,
        40
    };



    TIRO projetil = {0};

    Texture2D explosao = LoadTexture("sprites/explosion_5.png");
    Texture2D tiro = LoadTexture("sprites/projectile.png");
    Texture2D vida = LoadTexture("sprites/heart.png");
    Texture2D terra = LoadTexture("sprites/land.png");
    Texture2D heli_1 = LoadTexture("sprites/helicopter_1.png");
    Texture2D navio = LoadTexture("sprites/ship.png");
    Texture2D navio_inv = LoadTexture("sprites/ship_inv.png");
    Texture2D jet = LoadTexture("sprites/jet.png");
    Texture2D posto = LoadTexture("sprites/fuel.png");
    Texture2D planeCenter = LoadTexture("sprites/plane.png");
    Texture2D planeRight = LoadTexture("sprites/planetoright.png");
    Texture2D planeLeft = LoadTexture("sprites/planetoleft.png");
    Texture2D planeAtual = planeCenter;
    Texture2D navio_atual = navio;
    Texture2D house = LoadTexture("sprites/house.png");
    Texture2D street = LoadTexture("sprites/street.png");
    Texture2D bridge = LoadTexture("sprites/bridge.png");

    Sound exp = LoadSound("sounds/explosion.wav");
    Sound zap = LoadSound("sounds/zap.wav");

    Rectangle player_hitbox = {0};


    while(!WindowShouldClose())
    {
        switch(tela_atual)
        {
        //Cenário MENU
        case MENU:
        {
            mapa_carregado = false;
            char op = menu();

            if(op == 'g')
            {
                tela_atual = TROCA;
                //Reset de Variáveis do Jogo
                velocidade = 2;
                vidas = 3;
                nivel = 1;
                pontuacao = 0;
                combustivel = 100;
                fase_atual = 0;
                velocidade_ini = 3;
            }
            else if(op == 'r')
            {
                tela_atual = RANK;
            }
            else if(op == 's')
            {
                return 0;
            }
            break;
        }

        //Cenario troca de mapa
        case TROCA:
        {
            if(!mapa_carregado)
            {
                switch(fase_atual)
                {
                case FASE1:
                    quant_hitboxs = le_mapa("mapas/Mapa1.txt", vetor_hitboxs, planeAtual, terra, heli_1, posto, navio_atual, jet, street, bridge, house, &x_aviao, &y_aviao);
                    break;
                case FASE2:
                    quant_hitboxs = le_mapa("mapas/Mapa2.txt", vetor_hitboxs, planeAtual, terra, heli_1, posto, navio_atual, jet, street, bridge, house, &x_aviao, &y_aviao);
                    break;
                case FASE3:
                    quant_hitboxs = le_mapa("mapas/Mapa3.txt", vetor_hitboxs, planeAtual, terra, heli_1, posto, navio_atual, jet, street, bridge, house, &x_aviao, &y_aviao);
                    break;
                case FASE4:
                    quant_hitboxs = le_mapa("mapas/Mapa4.txt", vetor_hitboxs, planeAtual, terra, heli_1, posto, navio_atual, jet, street, bridge, house, &x_aviao, &y_aviao);
                    break;
                case FASE_FINAL:
                    quant_hitboxs = le_mapa("mapas/Mapa5.txt", vetor_hitboxs, planeAtual, terra, heli_1, posto, navio_atual, jet, street, bridge, house, &x_aviao, &y_aviao);
                    break;
                }
                mapa_carregado = true;
                tela_atual = GAMEPLAY;
            }
        }
        break;

        //Cenário Gameplay
        case GAMEPLAY:
        {
            //Verificação se o player está vivo
            if(vidas <= 0 || combustivel <= 0)
            {
                mapa_carregado = false;
                organizar_rank(pontuacao, top_five);
                tela_atual = ENDGAME;
            }
            else
            {
                if(invulnerabilidade > 0) invulnerabilidade--; //Invulnerábilidade de 1 segundo para não tomar mais de 1 de dano

                //Movimentação do jogador
                player_hitbox = move_player(
                                    &x_aviao,
                                    &y_aviao,
                                    &planeAtual,
                                    planeCenter,
                                    planeLeft,
                                    planeRight,
                                    velocidade
                                );

                //Analisar o gasto de combustivel
                deslocamento += velocidade;
                if(deslocamento >= 76)
                {
                    deslocamento -= 76;
                    combustivel -= 1;
                }

                //Função que faz o avião atirar
                if(!projetil.flag)
                {
                    if(IsKeyPressed(KEY_SPACE))
                        projetil = fshoot(x_aviao, y_aviao, tiro);
                }

                //Começo do desenho
                BeginDrawing();
                ClearBackground(DARKBLUE);

                //Função para desenhar o mapa
                desenhar_mapa(quant_hitboxs, vetor_hitboxs, terra, heli_1, posto, navio_atual, jet, street, bridge, house);

                //Desenho do avião
                DrawTexture(planeAtual, x_aviao, y_aviao, WHITE);
                //DrawRectangleRec(player_hitbox, Fade(RED, 0.5f));


                //Desenha o projétil
                if(projetil.flag)
                {
                    DrawTexture(tiro, projetil.sprite_tiro.x, projetil.sprite_tiro.y, WHITE);
                    PlaySound(zap);
                    projetil.sprite_tiro.y -= 30;
                    if(projetil.sprite_tiro.y < 0) projetil.flag = 0;
                }

                //Desenha a hud
                DrawRectangleRec(hud, BLACK);
                DrawText("Vidas: ", 10, 10, 30, YELLOW);

                for(int life = 0; life < vidas; life++)//Desenho das vidas
                {
                    DrawTexture(vida, (life * 30 + MeasureText("Vidas: ", 30)+ 10), 10, WHITE);
                }

                DrawText(TextFormat("Nivel: %i", nivel), 210, 10, 30, YELLOW);
                DrawText(TextFormat("Fuel: %.0f", combustivel), 360, 10, 30, YELLOW);
                DrawText(TextFormat("Score: %i", pontuacao), 520, 10, 30, YELLOW);

                //Desenho que checa as colisões
                //Obs.: A checar colisão ta dentro do desenho pois ela desenha as explosões
                checar_colisao(vetor_hitboxs, quant_hitboxs, projetil, &(projetil.flag), player_hitbox, &pontuacao, &vidas, &x_aviao, &y_aviao, &combustivel, explosao, exp, &invulnerabilidade);
                EndDrawing();

                //Verificação se acabou a fase
                if(CheckCollisionRecs(hud, player_hitbox))
                {
                    tela_atual = TROCA;

                    //Aumento da dificuldade
                    if(fase_atual == FASE_FINAL)
                    {
                        velocidade_ini += 2;
                        velocidade += 1;
                    }
                    x_aviao = 450;
                    y_aviao = 800;
                    fase_atual = (fase_atual + 1)%5; //Parte que faz o jogo um arcade infinito
                    mapa_carregado = false;
                    nivel += 1;
                }

                //Movimentação dos inimigos
                att_inimigos(vetor_hitboxs, quant_hitboxs, velocidade_ini);
                if(inv%120 == 0) navio_atual = navio_inv;
                else if (inv%120 == 60)navio_atual = navio;
                inv++;

                //Ativar o Menu de Pause
                if (IsKeyDown(KEY_P))
                {
                    tela_atual = PAUSE;
                }
            }
        }
        break;
        //Cenario de Pause
        case PAUSE:
            char op = pause();
            if(op == 'm')
            {
                tela_atual = MENU;
            }
            else if(op == 'c')
            {
                tela_atual = GAMEPLAY;
            }
            else if(op == 's')
            {
                return 0;
            }
            break;
        //Cenario de RANK
        case RANK:
        {
            //Botão para voltar (print rank retorna o retangulo voltar)
            if (CheckCollisionPointRec(GetMousePosition(), print_rank()))
            {
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsMouseButtonPressed(MOUSE_LEFT_BUTTON)||IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    tela_atual = MENU;
                }
            }
        }
        break;
        //Cenário ENDGAME
        case ENDGAME:
        {
            char op = pos_game(pontuacao);
            if(op == 'm')
            {
                tela_atual = MENU;
            }
            else if(op == 'g')
            {
                //Reset de variáveis
                tela_atual = TROCA;
                velocidade = 2;
                vidas = 3;
                nivel = 1;
                pontuacao = 0;
                combustivel = 100;
                fase_atual = 0;
                velocidade_ini = 3;
            }
            else if(op == 'r')
            {
                tela_atual = RANK;
            }
        }
        break;
        }//fechamento do switch
    }


    //Final - Descarregar
    UnloadTexture(vida);
    UnloadTexture(terra);
    UnloadTexture(heli_1);
    UnloadTexture(navio);
    UnloadTexture(jet);
    UnloadTexture(posto);
    UnloadTexture(planeCenter);
    UnloadTexture(planeRight);
    UnloadTexture(planeLeft);
    UnloadTexture(tiro);
    UnloadTexture(house);
    UnloadTexture(street);
    UnloadTexture(bridge);
    UnloadSound(zap);
    UnloadSound(exp);

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

