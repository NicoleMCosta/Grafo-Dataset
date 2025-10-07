#include "csvFile.h"

void min_max_normalize(DistanciaPar arr[], int size);

double distancia(Objetos dataA, Objetos dataB){
    return sqrt(pow(dataB.X - dataA.X,2) + pow(dataB.Y - dataA.Y,2.0) + pow(dataB.Z - dataA.Z, 2.0) + pow(dataB.w - dataA.w, 2.0));
}

int main(){
    FILE *csvpt = fopen("my_dataset.csv", "r");

    if (csvpt == NULL) {
        printf("Erro ao abrir o arquivo my_dataset.csv\n");
        return 1;
    }
    
    Objetos *dados = openCSV(csvpt);
    if (dados == NULL) {
        fclose(csvpt);
        return 1;
    }
    
    // O número de combinações de pares é n*(n-1)/2
    int num_combinacoes = SIZE * (SIZE - 1) / 2;
    DistanciaPar *distancias = malloc(num_combinacoes * sizeof(DistanciaPar));
    if (!distancias) {
        printf("Erro de memória ao alocar o array de distâncias\n");
        free(dados);
        fclose(csvpt);
        return 1;
    }

    // Calcula a distância para todos os pares
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            distancias[k].ponto1 = i;
            distancias[k].ponto2 = j;
            distancias[k].distancia = distancia(dados[i], dados[j]);
            k++;
        }
    }
    DistanciasPar *copiaDistancias = distancas;
    // Normaliza as distâncias
    min_max_normalize(distancias, num_combinacoes);

    // Salva o resultado em um novo arquivo CSV
    FILE *output_csv = fopen("distances.csv", "w");
    if (output_csv == NULL) {
        printf("Erro ao criar o arquivo distances.csv\n");
        free(distancias);
        free(dados);
        fclose(csvpt);
        return 1;
    }

    fprintf(output_csv, "ponto1,coordenada1,ponto2,coordenada2,distancia,distancia_normalizada\n");
    for (int i = 0; i < num_combinacoes; i++) {
        fprintf(output_csv, "%d,,%f,%d,%f,%f,%f\n", distancias[i].ponto1 + 1,dados[distancias[i].ponto1].X ,distancias[i].ponto2 + 1,dados[distancias[i].ponto2] ,copiaDistancias.distancia , distancias[i].distancia);
    }

    printf("Arquivo 'distances.csv' criado com sucesso!\n");

    // Libera a memória e fecha os arquivos
    fclose(output_csv);
    free(distancias);
    free(dados);
    fclose(csvpt);

    return 0;
}



void min_max_normalize(DistanciaPar arr[], int size) {
    if (size == 0) return;

    double min_val = arr[0].distancia;
    double max_val = arr[0].distancia;

    // Encontra os valores mínimo e máximo
    for (int i = 1; i < size; i++) {
        if (arr[i].distancia < min_val) {
            min_val = arr[i].distancia;
        }
        if (arr[i].distancia > max_val) {
            max_val = arr[i].distancia;
        }
    }

    // Aplica a normalização
    if (max_val - min_val == 0) {
        for (int i = 0; i < size; i++) {
            arr[i].distancia = 0.0;
        }
    } else {
        for (int i = 0; i < size; i++) {
            arr[i].distancia = (arr[i].distancia - min_val) / (max_val - min_val);
        }
    }
}
