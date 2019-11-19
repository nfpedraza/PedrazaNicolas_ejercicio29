import os
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Clase_29.dat")

plt.figure(1, figsize=(10,5)) 
plt.plot(data[:,0], data[:,1])
plt.plot(data[:,0], data[:,2])
#plt.plot(data[:,0], data[:,3])
#plt.plot(data[:,0], data[:,4])
#plt.plot(data[:,0], data[:,5])
#plt.plot(data[:,0], data[:,6])
#plt.plot(data[:,0], data[:,7])
#plt.plot(data[:,0], data[:,8])
#plt.plot(data[:,0], data[:,9])
plt.xlabel('X')
plt.ylabel('Y')
plt.savefig("graph.png")
#print(len(data))