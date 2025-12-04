#include "config_function.h"

void org_top5(JOGADOR r[MAXSCORES], int pts_novos, int ind)
{
    JOGADOR novoj, temp1, temp2;
    novoj.pontos = pts_novos;
    //PEDIR O NOME DO JOGADOR DE ALGUMA FORMA

    temp1 = r[ind];
    r[ind] = novoj;

    for(int j = ind+1; j<MAXSCORES; j++)
    {
        temp2 = r[j];
        r[j] = temp1;
        temp1 = temp2;
    }

}

void organizar_rank(int pts_atual)
{
    JOGADOR ranking[MAXSCORES];
    le_arquivo(ARQ_NOME, ranking);
    for(int i = 0; i < MAXSCORES; i++)
    {
        if(pts_atual > ranking[i].pontos)
        {
            org_top5(ranking, pts_atual, i);
            salva_arquivo(ARQ_NOME, ranking);
        }

    }
}
