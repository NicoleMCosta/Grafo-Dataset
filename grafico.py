import matplotlib.pyplot as plt
import csv

limiar = 0
pares = []
csvFile = "distances.csv"
with open(csvFile, 'r', newline= '') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')


# plt.scatter(X, y, color='blue', label='Dados reais')
# plt.title(f"Limiar {limiar}")
# plt.plot(pares,a,'ro')
# plt.xlabel('Número de vértices')
# plt.ylabel('Componentes do mesmo tamanho')



# # plt.xlabel('Limiar 0.3')


# # plt.xlabel('Limiar 0.5')


# # plt.xlabel('Limiar 0.9')
# plt.plot(pares,a,'ro')
# plt.xlabel('Componentes conexos')
# plt.ylabel('Tamanho')

# plt.show()