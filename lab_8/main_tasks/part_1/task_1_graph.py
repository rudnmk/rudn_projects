import pandas as ps
import matplotlib.pyplot as plt
import numpy as np


with open("C:/Users/mk170/projects/lab_8/main_tasks/part_1/data.txt", "r") as f:
    a = f.readlines()
    f.close()


data_list = []
for i in a:
    b = (i.rstrip('\n')).split('            ')
    if len(b) == 2:
        num_1 = float(b[0])
        num_2 = float(b[1])
        data_list.append([num_1, num_2])
    else:
        num = float(b[0])
        data_list.append([num, 0])


plt.style.use("ggplot")
figure = plt.figure()
surface = figure.add_subplot()

result_array = np.asarray(data_list).T
surface.plot(range(0, 6007), result_array[0], color="red", alpha=0.3, label="Va", marker="s", markerfacecolor="black", markersize=1)
surface.plot(range(0, 6007), result_array[1], alpha=0.3, color="blue", label="Vw", marker="o", markerfacecolor="black", markersize=1)
plt.legend(loc="upper left")
plt.show()
