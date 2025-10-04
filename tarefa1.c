#include "csvFile.h"

void min_max_normalize(double arr[], int size);

double distancia(Objetos dataA, Objetos dataB){
    return sqrt(pow(dataB.X - dataA.X,2) + pow(dataB.Y - dataA.Y,2.0) + pow(dataB.Z - dataA.Z, 2.0) + pow(dataB.w - dataA.w, 2.0));
}

int main(){
    FILE *csvpt = fopen("my_dataset.csv", "r");
    
    Objetos *dados = openCSV(csvpt);
    
    //listCSV(dados, SIZE);
    int i =0;
    double dados1 = distancia(dados[i+1],dados[i]);
    double dados2 = distancia(dados[i+2],dados[i+1]);
    double dados3 = distancia(dados[i+3],dados[i+2]);
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