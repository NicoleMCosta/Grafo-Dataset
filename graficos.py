import sympy  as sym
import matplotlib.pyplot as plt
import csv

limiar = 0
pares = []
a = [1,2,3,4,5,6,7,8]
csvFile = "distances.csv"
with open(csvFile, 'r', newline= '') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')
    next(csv_reader)


    for row in csv_reader:
        print(row)

# plt.scatter(X, y, color='blue', label='Dados reais')
# plt.title(f"Limiar {limiar}")
# plt.plot(pares,a,'ro')
# plt.xlabel('Número de vértices')
# plt.ylabel('Componentes do mesmo tamanho')



# # plt.xlabel('Limiar 0.3')


# # plt.xlabel('Limiar 0.5')


# # plt.xlabel('Limiar 0.9')

# plt.show()
