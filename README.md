# Algorithms
[1.Greedy](#gredy)
[2.Divide and Conquer](#divide-and-conquer)
[3.Dynamic Programming](#dynamic-programming)
[4.Searches](#searches)
[5.Sorting algorithms](#sorting-algorithms)

## Gredy
The inputs of the greedy algorithms are a set of candidates and
the output is a subset that maximize benefits or minimize costs.
Example:
    Input = [Candidate-1, Candidate-2, Candidate-3, Candidate-4]
    Output = [Candidate-1, Candidate-3]
To achieve this, greedy algorithms rely on the principle of optimality, which always
decide the best solution of the problem is choose the best candidate at each step.
Example:
    We need 300€ using the minimum number of coins (1€, 5€, 10€, 50€).
    Input = [1€ x 10, 5€ x 10, 10€ x 10, 50€ x 10]
    Firts, we need advanced very fast so starts with 50€ and
    when there isn't this type of coins we choose 10€.
    Output = [50€, 50€, 50€, 50€, 50€, 50€] => 6 coins

## Divide and Conquer
Divide and conquer algorithms into smaller subproblems that are easier to solve
and then combine the solutions to solve the original problem.
Example: The merge-sort.
    Input = [4, 2, 6, 1, 9]
    Div 1: [4, 2] and [6, 1, 9] => [2, 4]
    Div 2: [6, 1] and [9] => [1, 6] and [9]
    Join 1: [1, 6, 9]
    Join 2: [1, 2, 4, 6, 9]

## Dynamic Programming
Dynamic Programming algorithms calculate the solution with before results, which
saved in a matrix.
Example: Binomial coefficients.
    Function: C(n, m) = n! / (m! * (n - m)!)
    Recursive function:
        C(n, m) = 0 if m > n
        C(n, m) = 1 if m = 0 or m = n
        C(n, m) = C(n - 1, m - 1) + C(n - 1, m) in other case
    Matrix:
            0   1   2   3 (m)
        0   1
        1   1   1
        2   1   2   1
        3   1   3   3   1
        (n)
    So C(3, 2) = 3

## Searches
Search algorithms apply actions to init node for find solution node. A node
mostly saves the status, or his depth, costs, heuristic, route...
Exists the uninformed searchs (not use anything information to rise efficiency)
and informed search (that use information to rise efficiency).
Uninformed search:
    - Exhaustive search
    - Depth first search
    - Breadth first search
    - Depth limited search
    - Iterative deepending depth first search
Informed search:
    - Uniform cost search
    - A* seach
    - Aproximaly search:
        - Greedy search
        - Beam search
Example:
    We need 1L with two jugs (2L and 5L).
    Init node: 0L (0L and 0L)
    Actions: Fill jug, empty jug, empty jug in the other jug
    We use some search algoritm. For example: Depth first search

    Solution:
        Epoch 1: "0L (2L and 0L)" or 0L (0L and 5L)
        Epoch 2: 0L (0L and 2L) ...
        Epoch 3: 0L (2L and 2L) ...
        Epoch 4: 0L (0L and 4L) ...
        Epoch 5: 0L (2L and 4L) ...
        Epoch 6: 0L (1L and 5L) ...
        Epoch 7: 1L (0L and 5L) OK

## Sorting algorithms
This algoritms sort a number vector.
Some algorithms are:
    - Bubble sort O(N²)
    - Insertion sort O(N²)
    - Selection sort O(N²)
    - Heap sort 0(N*long(N))
    - Merge sort 0(N*long(N))
    - Quick sort 0(N²), but o(N*log(N)) (Normally is the best)
    - ... (More)