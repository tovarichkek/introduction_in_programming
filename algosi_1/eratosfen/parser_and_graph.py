import matplotlib.pyplot as plt
from math import sqrt
import numpy as np

f = open("build_folder/bench.txt", "r")
for i in range(13):
    f.readline()

test = 0
bench_time = 0
bench_cpu = 0
iterat = 0

trash = 0 

data = {"time":
                {"x":[], "y":[], "color":"green", "dots":'gs'},
        "CPU":
                {"x":[], "y":[], "color":"blue", "dots":'ro'}
}

for string in f.readlines():
    test, bench_time, trash, bench_cpu, trash, iterat = string.split()

    test = test.split("/")[1]

    data["time"]["x"].append(int(test))
    data["time"]["y"].append(float(bench_time))
    
    data["CPU"]["x"].append(int(test))
    data["CPU"]["y"].append(float(bench_cpu))



plt.figure(figsize=(14,10))
plt.grid(True, which='both', linestyle='--', linewidth=0.5)  # Рисуем сетку

#for logarithmic scale
#fig, ax = plt.subplots()
#ax.set_xscale('log')

for lsdadsada, dat in data.items():
	plt.plot(dat['x'],dat['y'],dat['dots'],label=f'{lsdadsada}')

plt.xlabel('N, up to which the search for prime numbers')
plt.ylabel('time')
plt.legend(loc='best',fontsize=12)
plt.savefig('build_folder/Benchmarking_graph.png')



f.close()
