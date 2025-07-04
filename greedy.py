from typing import List
from copy import deepcopy

class Candidate:
    def get_cost(self) -> float:
        pass
    
    def get_benefit(self) -> float:
        pass

def is_solution(candidates: List[Candidate]) -> bool:
    pass

def is_possible(solution: List[Candidate], candidate: Candidate) -> bool:
    pass

def choose_best_candidate(candidates: List[Candidate],
                          solution: List[Candidate]) -> Candidate:
    best_pos = 0
    best_candidate = candidates[0]
    for i, cand in enumerate(candidates):
        if is_possible(solution, cand):
            if cand.get_cost() < best_candidate.get_cost(): # Cost or Benefit
                best_candidate = deepcopy(cand)
                best_pos = i
    del candidates[best_pos]
    return best_candidate

def greedy_algorithm():
    solution = []
    candidates = []
    while not is_solution(solution) and len(candidates) > 0:
        candidate = choose_best_candidate(candidates, solution)
        solution.append(candidate)
    
    if not is_solution(solution):
        print('There isn\'t solution')
    else:
        print('Solution: ')
        for cand in candidates:
            print(cand.show())