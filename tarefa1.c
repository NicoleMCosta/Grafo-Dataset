#include "csvFile.h"

void min_max_normalize(double arr[], int size);

int main(){
    FILE *csvpt = fopen("my_dataset.csv", "r");
    
    Objetos *dados = openCSV(csvpt);
    
    //listCSV(dados, SIZE);
    int i =0;
    double dados1 = sqrt(pow(dados[i+1].X - dados[i].X,2) + pow(dados[i+1].Y - dados[i].Y,2.0) + pow(dados[i+1].Z - dados[i].Z, 2.0) + pow(dados[i+1].w - dados[i].w, 2.0));
    double dados2 = sqrt(pow(dados[i+2].X - dados[i+1].X,2) + pow(dados[i+2].Y - dados[i+1].Y,2.0) + pow(dados[i+2].Z - dados[i+1].Z, 2.0) + pow(dados[i+2].w - dados[i+1].w, 2.0));
    double dados3 = sqrt(pow(dados[i+3].X - dados[i+2].X,2) + pow(dados[i+3].Y - dados[i+2].Y,2.0) + pow(dados[i+3].Z - dados[i+2].Z, 2.0) + pow(dados[i+3].w - dados[i+2].w, 2.0));
    double teste[] = {dados1, dados2,dados3};
    
    for (int i = 0; i < 3; i++) {
        printf("%.2f \n", teste[i]);
    }

    min_max_normalize(teste,3);
    
    for (int i = 0; i < 3; i++) {
        printf("%.2f \n", teste[i]);
    }

    fclose(csvpt);
    free(dados);
    return 0;
}



void min_max_normalize(double arr[], int size) {
    if (size == 0) return;

    double min_val = arr[0];
    double max_val = arr[0];

    // Find min and max values
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Apply normalization
    if (max_val - min_val == 0) { // Handle cases where all values are the same
        for (int i = 0; i < size; i++) {
            arr[i] = 0.0; // Or any other desired value
        }
    } else {
        for (int i = 0; i < size; i++) {
            arr[i] = (arr[i] - min_val) / (max_val - min_val);
        }
    }
}