#include "config_function.h"

void salva_arquivo(char nome_arq[], JOGADOR top5[])
{
    FILE *fp = fopen(nome_arq, "wb");
    if(fp != NULL)
    {
        if(fwrite(top5, sizeof(JOGADOR), 5, fp) == 5)
        {
        } erro_load();

    }else erro_load();

    fclose(fp);
}
