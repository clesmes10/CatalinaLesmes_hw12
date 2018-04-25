import numpy as np
import matplotlib.pyplot as plt

#cargar datos
datosad = np.genfromtxt("advection.txt")

x = datosad[:,1]
y = datosad[:,2]

plt.plot(x,y, "c")
plt.xlabel("x")
plt.ylabel("y")
plt.title("adveccion")
plt.savefig("adveccion.png")

