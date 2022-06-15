import numpy as np
import matplotlib.pyplot as plt

file  = "rad0phi0.csv"
array = np.loadtxt(file, delimiter=",")
array = array.T             # transpose
rad   = array[0] / 180 * np.pi
r     = array[1]

plt.polar(rad, r, 'go-')
plt.show()
