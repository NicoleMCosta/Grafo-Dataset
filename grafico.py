import matplotlib.pyplot as plt

limiar = 0.0
componentes = [1,2] # X
tamanhos = [3,2] # Y


plt.title(f"Limiar {limiar}")
plt.xticks(range(0,151))
plt.yticks(range(0,151))
plt.plot(componentes, tamanhos,'ro')
plt.xlabel('Componentes conexos')
plt.ylabel('Tamanho')
plt.grid()

plt.show()


#Grafico de analise final
componentes = [0.0,0.3,0.5,0.9] # X
tamanhos = [2,1,1,1] # Y
plt.yticks(range(0,151))
plt.bar(componentes, tamanhos, width=0.1)
plt.xlabel("Limiar")
plt.ylabel("Qtd. componentes conexos")
plt.title("Resultados de cada Limiar")
plt.grid()
plt.show()