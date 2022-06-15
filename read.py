import numpy as np

with open("rad0phi0.csv") as file_name:
    array = np.loadtxt(file_name, delimiter=",")
    array = array.T
    rad  = array[0] / 180 * np.pi

print(rad)
