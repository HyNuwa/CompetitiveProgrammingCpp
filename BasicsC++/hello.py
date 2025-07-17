import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Estados
VEGETACION = 0
FUEGO = 1
QUEMADO = 2
AGUA = 3

N = 300
p_fuego = 0.5  # Probabilidad de propagación
generaciones = 300

# Inicializar grilla con vegetación aleatoria
grid = np.random.choice([VEGETACION, VEGETACION, VEGETACION, AGUA], size=(N, N), p=[0.9, 0.05, 0.04, 0.01])

# Crear un río sinuoso más grueso
for i in range(N):
    x = int(N/3 + 40 * np.sin(i / 25))
    for ancho in range(-2, 3):  # Grosor del río
        if 0 <= x + ancho < N:
            grid[i, x + ancho] = AGUA

# Crear un lago
cx, cy = int(N * 0.7), int(N * 0.3)
radio = 15
for i in range(N):
    for j in range(N):
        if (i - cx)**2 + (j - cy)**2 < radio**2:
            grid[i, j] = AGUA

# Encender fuego en la parte inferior izquierda
grid[N - 10, 10] = FUEGO

# Colores personalizados
import matplotlib.colors as mcolors
cmap = mcolors.ListedColormap(["green", "red", "black", "blue"])

fig, ax = plt.subplots()
im = ax.imshow(grid, cmap=cmap, vmin=0, vmax=3)

# Función de actualización
def update(frame):
    global grid
    nueva_grid = grid.copy()
    for i in range(1, N-1):
        for j in range(1, N-1):
            if grid[i, j] == FUEGO:
                nueva_grid[i, j] = QUEMADO
                # Vecinos
                for dx in [-1, 0, 1]:
                    for dy in [-1, 0, 1]:
                        ni, nj = i + dx, j + dy
                        if grid[ni, nj] == VEGETACION and np.random.rand() < p_fuego:
                            nueva_grid[ni, nj] = FUEGO
    grid = nueva_grid
    im.set_array(grid)
    return [im]

ani = animation.FuncAnimation(fig, update, frames=generaciones, interval=50, repeat=False)
plt.show()
