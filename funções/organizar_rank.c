#include "config_function.h"

void org_top5(JOGADOR r[MAXSCORES], int pts_novos, int ind)
{
    JOGADOR novoj, temp1, temp2;
    novoj.pontos = pts_novos;
    strcpy(novoj.nome, "Julia");

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
    le_arquivo("top5.bin", ranking);
    int i = 0;
    bool flag = true;
    while(i < 5 && flag)
    {
        if(pts_atual > ranking[i].pontos)
        {
            org_top5(ranking, pts_atual, i);
            salva_arquivo("top5.bin", ranking);
            flag = false;
        }

    }
}
