import sympy  as sym
import matplotlib.pyplot as plt
import csv

csvFile = "distances.csv"
with open(csvFile, 'r', newline= '') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')
    next(csv_reader)


    for row in csv_reader:
        print(row)

# plt.scatter(X, y, color='blue', label='Dados reais')
# plt.title(f"Limiar {limiar}")

# plt.plot(pares,a,'ro')
# plt.xlabel('Componentes conexos')
# plt.ylabel('Tamanho')

# plt.show()
