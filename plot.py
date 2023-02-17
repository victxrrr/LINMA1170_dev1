import sys
import argparse
import matplotlib.pyplot as plt

plt.rcParams["mathtext.fontset"] = 'cm'
plt.rcParams['font.family'] = 'Times New Roman'

def parse_file(data):
    size, time = [[], []], [[], []]
    i = -1
    for line in data:
        line = line.strip()
        if line.__contains__(">>>") :
            i += 1
        elif line.__contains__("size"):
            continue
        else:
            line = line.split()
            size[i].append(int(line[0]))
            time[i].append(float(line[1]))
    return size, time

def plot(x, y):
    fig, ax = plt.subplots(nrows=2, ncols=1, sharex=True, figsize=(8, 6), dpi=125, num="Analyse Numérique: Devoir 1")
    sz = 12
    fig.suptitle("Mesure des performances des algorithmes définis dans lu.h")

    # LU decomposition function measurements
    ax[0].loglog(x[0], y[0], label="lu", color='slateblue')
    ax[0].set_ylabel("Temps d'exécution " + "$[s]$", fontsize=sz)
    ax[0].legend(loc='best')
    ax[0].grid(True, which='both', lw=0.5)

    # Solve function measurements
    ax[1].loglog(x[1], y[1], label="solve", color='saddlebrown')
    ax[1].set_ylabel("Temps d'exécution " + "$[s]$", fontsize=sz)
    ax[1].set_xlabel("Taille "+ "$n$" + " de la matrice aléatoire inversible " + r'$A^{n \times n}$', fontsize=sz)
    ax[1].legend(loc='best')
    ax[1].grid(True, which='both', lw=0.5, color='lightgrey')

    plt.show()


if __name__ == "__main__":

    # parsing command-line arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('txt_file', type=str, help='a file.txt to plot')
    args = parser.parse_args()

    # parsing file
    try:
        with open(args.txt_file, 'r') as file:
            data = file.readlines()
    except:
        print("Error: Cannot open file") 
        quit() 
    sz, tm = parse_file(data)

    # plot data
    plot(sz, tm)


