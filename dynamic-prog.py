
class Solution:
    pass

class SolutionsMatrix():
    def __init__(self, rows: int, columns: int):
        self.__matrix = [[None] * columns for i in rows]

    def __solve(self, row: int, col: int) -> Solution:
        """ Uses the previous solutions for the new solution """
        pass

    def iterate_matrix(self):
        """ __solve() is used for each __matrix[i][j] """
        pass

    def observe_solution(self, row: int, col: int) -> Solution:
        return self.__matrix[row][col]

def dynamic_programming_algorithm(m: SolutionsMatrix) -> Solution:
    m.iterate_matrix()
    solution = m.observe_solution(...)
    return solution