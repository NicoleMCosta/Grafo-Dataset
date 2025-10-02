#include "csvFile.h"

int main(){
    FILE *csvpt = fopen("my_dataset.csv", "r");
    
    Objetos *dados = openCSV(csvpt);
    
    listCSV(dados, SIZE);

    fclose(csvpt);
    free(dados);
    return 0;
}