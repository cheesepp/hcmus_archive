import pygame
from maze import *
from const import *
import math

def print_path(g: SearchSpace, sc: pygame.Surface, trace_path):

    # if arrived goal stop
    if (trace_path[g.goal.id] == -1):
        return
    
    # the final path from start to goal
    path = []

    goal = g.goal.id

    # draw goal and start on figure after searching
    g.goal.set_color(PURPLE, sc)
    g.start.set_color(ORANGE, sc)

    # back tracking from goal to start
    while (goal != g.start.id):

        path.append(goal)
        goal = trace_path[goal]

    # add start id to path
    path.append(goal)

    # iterate step in path
    for step in range(0, len(path) - 1):
        current = path[step]
        next = path[step + 1]

        # get current coordinate
        x1, y1 = g.grid_cells[current].rect.centerx, g.grid_cells[current].rect.centery
        # get next coordinate
        x2, y2 = g.grid_cells[next].rect.centerx, g.grid_cells[next].rect.centery

        # draw line between these coordinates
        pygame.draw.line(sc, WHITE, (x2, y2), (x1, y1), 2)
        pygame.time.delay(20)
        pygame.display.update()



def DFS(g: SearchSpace, sc: pygame.Surface):
    print('Implement DFS algorithm')

    # perform open set like a stack
    open_set = [g.start]
    father = [-1]*g.get_length()
    # treat closed set as visited list
    closed_set = []

    # check while open set is not empty
    while open_set:

        # get the first element (top element in stack)
        curr = open_set.pop(0)
        curr.set_color(YELLOW, sc)
        pygame.time.delay(20)
        # close current
        if curr not in closed_set:
            closed_set.append(curr)
            curr.set_color(BLUE, sc)

        # check if current is goal
        if g.is_goal(curr):
            print_path(g, sc, father)
            return

        # iterate neighbors of current point
        for neighbor in g.get_neighbors(curr):
            if neighbor not in closed_set and neighbor not in open_set:
                if neighbor.id != g.goal.id:
                    # tracking neighbor
                    neighbor.set_color(RED, sc)
                # add path to father
                father[neighbor.id] = curr.id
                # add neighbor to open
                open_set.insert(0, neighbor)


def BFS(g: SearchSpace, sc: pygame.Surface):
    print('Implement BFS algorithm')
    # open set in bfs will be perform like a queue
    open_set = [g.start]
    father = [-1]*g.get_length()
    closed_set = []
    curr = g.start
    
    while open_set:
        
        # dequeue the first element
        curr = open_set.pop(0)
        
        curr.set_color(YELLOW, sc)
        pygame.time.delay(20)

        if curr not in closed_set:
            closed_set.append(curr)
            curr.set_color(BLUE, sc)

        if g.is_goal(curr):
            print_path(g, sc, father)
            return
        
        for neighbor in g.get_neighbors(curr):
            if neighbor not in closed_set and neighbor not in open_set:
                # enqueue the neighbor
                open_set.append(neighbor)
                father[neighbor.id] = curr.id
                
                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)
    
# helper function to calculate cost between two nodes
def costTwoNode(neighbor: Node, curr: Node):

    neighbor_x, neighbor_y = neighbor.id%COLS, neighbor.id//COLS
    curr_x, curr_y = curr.id%COLS, curr.id//COLS

    cost = math.sqrt((neighbor_x - curr_x)**2 + (neighbor_y - curr_y)**2)
    return cost

def UCS(g: SearchSpace, sc: pygame.Surface):
    print('Implement UCS algorithm')

    # +1 respect if you can implement UCS with a priority queue
    # perform open set like min-priority queue
    open_set = [(0, g.start)]
    father = [-1]*g.get_length()
    closed_set = []
    cost = [100_000]*g.get_length()
    cost[g.start.id] = 0

    while open_set:

        # dequeue the first element
        curr = open_set.pop(0)

        curr[1].set_color(YELLOW, sc)
        pygame.time.delay(20)

        if curr not in closed_set:
            closed_set.append(curr)
            curr[1].set_color(BLUE, sc)

        if g.is_goal(curr[1]):
            print_path(g, sc, father)
            return

        for neighbor in g.get_neighbors(curr[1]):
            # check if neighbor not in closed set and open set
            neigh_in_closed = [item for item in closed_set if item[1] == neighbor]
            neigh_in_open = [item for item in open_set if item[1] == neighbor]
            if len(neigh_in_closed) == 0 and len(neigh_in_open) == 0:
            
                cost[neighbor.id] = costTwoNode(neighbor, curr[1]) + cost[curr[1].id]
                open_set.append((cost[neighbor.id], neighbor))
                father[neighbor.id] = curr[1].id

                open_set.sort(key=lambda i: i[0])

                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)

            # check if found the neighbor which has less cost than the same neighbor in the open set before
            elif len(neigh_in_open) >= 1 and neigh_in_open[0][0] > costTwoNode(neighbor, curr[1]) + cost[curr[1].id]:

                # remove all neighbors which have higher cost
                open_set = [neighbor for neighbor in open_set if neighbor not in neigh_in_open]
                cost[neighbor.id] = costTwoNode(neighbor, curr[1]) + cost[curr[1].id]
                # enqueue the min cost neighbor to open set
                open_set.append((cost[neighbor.id], neighbor))
                # track path
                father[neighbor.id] = curr[1].id
                # sort open set in ascending order (min-priority queue)
                open_set.sort(key=lambda i: i[0])

                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)
                

# helper function to calculate heuristic value
def getHeuristic(g: SearchSpace, node: Node):

    x, y = node.id%COLS, node.id//COLS

    goal_x, goal_y = g.goal.id%COLS, g.goal.id//COLS

    cost = (math.sqrt((x - goal_x)**2 + (y - goal_y)**2))
    return cost

def AStar(g: SearchSpace, sc: pygame.Surface):
    print('Implement AStar algorithm')


    # +1 respect if you can implement AStar with a priority queue
    # all attribute will perform like UCS algorithm
    open_set = [(0, g.start)]
    father = [-1]*g.get_length()
    closed_set = []
    cost = [100_000]*g.get_length()
    cost[g.start.id] = 0
    curr = (0, g.start)

    while open_set:

        curr = open_set.pop(0)

        curr[1].set_color(YELLOW, sc)
        pygame.time.delay(20)

        if curr not in closed_set:
            closed_set.append(curr)
            curr[1].set_color(BLUE, sc)
            
        
        if g.is_goal(curr[1]):
            print_path(g, sc, father)
            return
        
        for neighbor in g.get_neighbors(curr[1]):
            
            neigh_in_closed = [item for item in closed_set if item[1] == neighbor]
            neigh_in_open = [item for item in open_set if item[1] == neighbor]
            if len(neigh_in_closed) == 0 and len(neigh_in_open) == 0:
  
                cost[neighbor.id] = costTwoNode(neighbor, curr[1]) + cost[curr[1].id]

                # add heuristic value to find better path
                f = cost[neighbor.id] + getHeuristic(g,neighbor)
                open_set.append((f, neighbor))
                father[neighbor.id] = curr[1].id

                open_set.sort(key=lambda i: i[0])

                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)

            elif len(neigh_in_open) >= 1 and neigh_in_open[0][0] > costTwoNode(neighbor, curr[1]) + cost[curr[1].id] + getHeuristic(g, neighbor):

                open_set = [neighbor for neighbor in open_set if neighbor not in neigh_in_open]
                cost[neighbor.id] = costTwoNode(neighbor, curr[1]) + cost[curr[1].id]
                f = cost[neighbor.id] + getHeuristic(g, neighbor)
                open_set.append((f, neighbor))
                father[neighbor.id] = curr[1].id

                open_set.sort(key=lambda i: i[0])

                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)

def Greedy(g: SearchSpace, sc: pygame.Surface):
    print('Implement AStar algorithm')


    # +1 respect if you can implement AStar with a priority queue
    # all attribute will perform like UCS algorithm
    open_set = [(0, g.start)]
    father = [-1]*g.get_length()
    closed_set = []
    cost = [100_000]*g.get_length()
    cost[g.start.id] = 0
    curr = (0, g.start)

    while open_set:

        curr = open_set.pop(0)

        curr[1].set_color(YELLOW, sc)
        pygame.time.delay(20)

        if curr not in closed_set:
            closed_set.append(curr)
            curr[1].set_color(BLUE, sc)
            
        
        if g.is_goal(curr[1]):
            print_path(g, sc, father)
            return
        
        for neighbor in g.get_neighbors(curr[1]):
            
            neigh_in_closed = [item for item in closed_set if item[1] == neighbor]
            neigh_in_open = [item for item in open_set if item[1] == neighbor]
            if len(neigh_in_closed) == 0 and len(neigh_in_open) == 0:
  
                # add heuristic value to find better path
                cost[neighbor.id] = getHeuristic(g,neighbor)
                open_set.append((cost[neighbor.id], neighbor))
                father[neighbor.id] = curr[1].id

                open_set.sort(key=lambda i: i[0])

                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)

            elif len(neigh_in_open) >= 1 and neigh_in_open[0][0] > getHeuristic(g, neighbor):

                open_set = [neighbor for neighbor in open_set if neighbor not in neigh_in_open]
                cost[neighbor.id] = getHeuristic(g, neighbor)
                open_set.append((cost[neighbor.id], neighbor))  
                father[neighbor.id] = curr[1].id

                open_set.sort(key=lambda i: i[0])

                if neighbor.id != g.goal.id:
                    neighbor.set_color(RED, sc)