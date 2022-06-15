import numpy as np
import matplotlib.pyplot as plt

degs = np.array([ 30, 60, 90,120,150,210,240,270,300,330,360])

rad  = degs / 180 * np.pi
r    = np.array([ 32, 35, 45, 75, 34, 35, 24, 25, 19, 26, 56])
plt.polar(rad, r, 'go-')
plt.show()
