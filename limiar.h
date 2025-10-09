#include "csvFile.h"
#include <string.h>

int limiares(FILE *output_csv, float limiar, int num_combinacoes){
    DistanciaPar dados;
    fclose(output_csv);

    FILE *csv = fopen("distances.csv", "r");
    if (csv == NULL) {
        printf("Erro ao reabrir distances.csv para leitura\n");
        return 1;
    }
    char nomefile[20];
    sprintf(nomefile, "limiar%.1f.csv", limiar);
    FILE *limiarcalc= fopen(nomefile, "w");
        if (limiarcalc == NULL) {
            printf("Erro ao criar o arquivo %s\n", nomefile);
            return 1;
        }

    int count = 0;
    while(fscanf(csv, "%d,%d,%lf", &dados.ponto1, &dados.ponto2, &dados.distancia) == 3){

        if (dados.distancia <= limiar) {
                fprintf(limiarcalc, "%d,%d\n", dados.ponto1, dados.ponto2);
                count++;
            }
        if (count >= num_combinacoes)
            break;
    }
    fclose(limiarcalc);
    printf("\nCSV %.1lf criado\n", limiar);
    return 0;
}


int buscaBFS(FILE *limiar){

}