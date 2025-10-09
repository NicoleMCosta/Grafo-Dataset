#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 150

typedef struct Objetos{
    int caso;
    float X;
    float Y;
    float Z;
    float w;
}Objetos;

typedef struct {
    int ponto1;
    int ponto2;
    double distancia;
} DistanciaPar;



Objetos* openCSV(FILE *csv){
    if(csv == NULL){
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }
    
    Objetos *obj = malloc((SIZE+1)*sizeof(Objetos));
    if (!obj) {
        printf("Erro de memória\n");
        return NULL;
    }

    int caso= 0;
    int r = 4;
    Objetos temp;
    while (r == 4){
        r = fscanf(csv, "%f,%f,%f,%f", &temp.X, &temp.Y, &temp.Z, &temp.w);
        temp.caso = caso;
        // printf("CASO %i\n", caso);
        obj[caso] = temp;
        caso++;
    }
    return obj;
}

void listCSV(Objetos *data, int n){
    for (int i = 0; i < (n); i++) {
        printf("caso_%d: %.1f %.1f %.1f %.1f\n", data[i].caso+1, data[i].X, data[i].Y, data[i].Z, data[i].w);
    }
}

// int openFiles(FILE **f0, FILE **f3, FILE **f5, FILE **f9,
//               const char *name0, const char *name3, const char *name5, const char *name9) {
//     *f0 = fopen(name0, "r");
//     *f3 = fopen(name3, "r");
//     *f5 = fopen(name5, "r");
//     *f9 = fopen(name9, "r");

//     if (!*f0 || !*f3 || !*f5 || !*f9) {
//         printf("Erro ao abrir os arquivos\n");
//         return 0;
//     }
//     return 1;
// }
