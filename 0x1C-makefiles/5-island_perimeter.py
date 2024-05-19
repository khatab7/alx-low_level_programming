#!/usr/bin/python3
'''Module defining a function for calculating a perimeter given\
a grid '''


def island_perimeter(grid):
    '''Calculates the perimter of the given grid'''
    perimter = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimter += (4 - check_neighbors(grid, row, col))
    return perimter


def check_neighbors(grid, row, col):
    '''Returns the number of ones surrounding the given
    row and col'''
    neighbors = 0
    if row > 0 and grid[row - 1][col] == 1:
        neighbors += 1
    if row < len(grid) - 1 and grid[row + 1][col] == 1:
        neighbors += 1
    if col > 0 and grid[row][col - 1] == 1:
        neighbors += 1
    if col < len(grid[row]) - 1 and grid[row][col + 1] == 1:
        neighbors += 1
    return neighbors
