import math, random
import numpy as np

def is_in_circle(x, y, Cx, Cy, R):
    return (x - Cx)** 2 + (y - Cy)**2 <= R**2

def find_area(total_point, R):
    point_in_circle = 0
    square_side = R
    for i in range(total_point):
        x = random.random()*square_side
        y = random.random()*square_side
        if is_in_circle(x, y, R, R, R):
            point_in_circle = point_in_circle + 1
    return point_in_circle / total_point * square_side**2

# quadratic equation using genetic algoritm
a = 2
b = 3
c = -1
population_size = 100
generations = 100
mutation_prob = 0.1
pop = []
pop = [random.uniform(-10, 10) for _ in range(population_size)]

def fitness(x):
    return abs(a * x**2 + b * x + c)

import struct
from codecs import decode


def float_bin(parent):

    # pack the float as a binary string
    s = struct.pack('!f', parent) 

    # convert each byte to binary and join them
    b = ''.join(format(c, '08b') for c in s)
    return b

def mate(new_pop, parents):
    while len(new_pop) < population_size:
        parent1, parent2 = random.sample(parents, 2)
        parent1 = float_to_bin(parent1)
        parent2 = float_to_bin(parent2)
        crossover_point = random.randint(1, len(parent1)- 1)
        child = parent1[:crossover_point] + parent2[crossover_point:]
        if random.random() < mutation_prob:
            mutation_amount = random.uniform(-0.1, 0.1)
            child = [x + str(mutation_amount) for x in child]
        child = bin_to_float(child)
        new_pop.append(child)
    pop = new_pop

def int_to_bytes(n, length):  # Helper function
    """ Int/long to byte string.

        Python 3.2+ has a built-in int.to_bytes() method that could be used
        instead, but the following works in earlier versions including 2.x.
    """
    return decode('%%0%dx' % (length << 1) % n, 'hex')[-length:]

def bin_to_float(b):
    """ Convert binary string to a float. """
    bf = int_to_bytes(int(b, 2), 8)  # 8 bytes needed for IEEE 754 binary64.
    return struct.unpack('>d', bf)[0]

def float_to_bin(value):  # For testing.
    """ Convert float to 64-bit binary string. """
    [d] = struct.unpack(">Q", struct.pack(">d", value))
    return '{:064b}'.format(d)


def select():

    for generation in range(generations):
        fitness_value = [fitness(x) for x in pop]
        parents = []
        for _ in range(population_size):
            tournament_size = 5
            tournament_indices = random.sample(range(population_size), tournament_size)
            tournament_fitness = [fitness_value[i] for i in tournament_indices]
            best_index = tournament_indices[np.argmin(tournament_fitness)]
            parents.append(pop[best_index])
        new_pop = []
        mate(new_pop, parents)

select()
best_solution = min(pop, key=fitness)

print("Best solution:", best_solution)
print("Fitness:", fitness(best_solution))










    
