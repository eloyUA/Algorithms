from typing import List
from typing import Set
from typing import Callable
from copy import deepcopy
from collections import deque

# ==========================================
#       CLASS NODE
# ==========================================
class Node:
    def __init__(self):
        self.__state = None
        self.__depth = None
        self.__cost = None
        self.__heuristic = None

    def is_solution(self) -> bool:
        pass
    
    def children(self) -> Set["Node"]:
        pass

    def get_depth(self) -> int:
        pass

    def get_cost(self) -> float:
        pass

    def get_heuristic(self) -> float:
        pass

    def __eq__(self, obj):
        if isinstance(obj, Node):
            return self.__state == obj.__state and self.__cost == obj.__cost
        return False
    
    def __hash__(self):
        return hash(self.__state) + hash(self.__cost)

# ==========================================
#       UNINFORMED SEARCHES
# ==========================================
def exhaustive_search() -> Node:
    start = Node()
    stack = [start]
    explored = set()
    while len(stack) > 0 and not(stack[-1].is_solution()):
        current = stack.pop(-1)
        explored.add(current)

        children = current.children()
        children = children.difference(stack).difference(explored)
        stack.extend(children)

    if len(stack) == 0:
        return None # There isn't solution
    else:
        best_solution = deepcopy(stack[-1])
        while len(stack) > 0:
            current = stack.pop(-1)
            explored.add(current)

            if current.is_solution():
                if current.get_cost() < best_solution.get_cost():
                    best_solution = deepcopy(current)

            children = current.children()
            children = children.difference(stack).difference(explored)
            stack.extend(children)
        return best_solution

def depth_first_search() -> Node:
    start = Node()
    stack = [start]
    explored = set()
    while len(stack) > 0 and not(stack[-1].is_solution()):
        current = stack.pop(-1)
        explored.add(current)

        children = current.children()
        children = children.difference(stack).difference(explored)
        stack.extend(children)

    if len(stack) == 0:
        return None
    else:
        return current

def breadth_first_search() -> Node:
    start = Node()
    queue = deque([start])
    explored = set()
    while len(queue) > 0 and not(queue[0].is_solution()):
        current = queue.popleft()
        explored.add(current)

        children = current.children()
        children = children.difference(queue).difference(explored)
        queue.extend(children)

    if len(queue) == 0:
        return None
    else:
        return current

def depth_limited_search(max_depth: int) -> Node:
    start = Node()
    stack = [start]
    explored = set()
    while len(stack) > 0 and not(stack[-1].is_solution()):
        current = stack.pop(-1)
        explored.add(current)

        if current.get_depth() <= max_depth:
            children = current.children()
            children = children.difference(stack).difference(explored)
            stack.extend(children)

    if len(stack) == 0:
        return None
    else:
        return current

def iterative_deepending_depht_first_search(max_depth_explore: int) -> Node:
    solution = None
    for depth in range(1, max_depth_explore + 1):
        solution = depth_limited_search(depth)
        if solution != None:
            break
    return solution

# ==========================================
#       INFORMED SEARCHES
# ==========================================

def binary_search_and_insert(sorted_list: List[Node], child: Node,
                             cost_func: Callable[[Node], float]):
    """
    This isn't a search algorithm.
    Insert child in sorted_list using the cost_func
    """
    if len(sorted_list) == 0:
        sorted_list.append(child)
    else:
        cost_child = cost_func(child)
        if cost_child <= cost_func(sorted_list[0]):
            sorted_list.insert(0, child)
        elif cost_child >= cost_func(sorted_list[-1]):
            sorted_list.append(child)
        else:
            start = 0
            finish = len(sorted_list) - 1
            while start <= finish:
                center = (start + finish) // 2
                
                if cost_child < cost_func(sorted_list[center]):
                    finish = center
                elif cost_child > cost_func(sorted_list[center]):
                    start = center + 1
                else:
                    start = center
                    finish = center + 1
            sorted_list.insert(start, child)

def uniform_cost_search():
    start = Node()
    sorted_list = [start]
    explored = set()
    while len(sorted_list) > 0 and not(sorted_list[0].is_solution()):
        current = sorted_list.pop(0)
        explored.add(current)

        children = current.children()
        children = children.difference(sorted_list).difference(explored)
        for child in children:
            binary_search_and_insert(sorted_list, child, lambda node: node.get_cost())

    if len(sorted_list) == 0:
        return None
    else:
        return current

def A_search():
    start = Node()
    sorted_list = [start]
    explored = set()
    while len(sorted_list) > 0 and not(sorted_list[0].is_solution()):
        current = sorted_list.pop(0)
        explored.add(current)

        children = current.children()
        children = children.difference(sorted_list).difference(explored)
        for child in children:
            binary_search_and_insert(
                sorted_list,
                child,
                lambda node: node.get_cost() + node.get_heuristic()
            )

    if len(sorted_list) == 0:
        return None
    else:
        return current

def greedy_search():
    start = Node()
    current = start
    children = current.children()
    explored = set()
    while not(current.is_solution()) and len(children) > 0:
        explored.add(current)
        
        best_child = deepcopy(children[0])
        for child in children:
            if child.get_heuristic() < best_child.get_heuristic():
                best_child = deepcopy(child)
        current = best_child
        children = current.children().difference(explored)

    if not current.is_solution():
        return None
    else:
        return current

def beam_search(k: int):
    start = Node()
    sorted_list = [start]
    explored = set()
    solutions = []
    while len(sorted_list) > 0:
        current = sorted_list.pop(0)
        explored.add(current)

        if current.is_solution():
            solutions.append(current)

        children = current.children()
        children = children.difference(sorted_list).difference(explored)
        best_children = sorted(children, key=lambda node: node.get_heuristic())
        
        sorted_list.clear()
        if len(best_children) <= k:
            sorted_list.extend(best_children)
        else:
            sorted_list.extend(best_children[:k])

    if len(sorted_list) == 0:
        return None
    else:
        return current