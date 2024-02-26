import math, random

# ex1: monte carlo simulation
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

# ex2: genetic algorithms
