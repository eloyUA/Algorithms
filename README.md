# Algorithms

1. [Greedy](#greedy)
2. [Divide and Conquer](#divide-and-conquer)
3. [Dynamic Programming](#dynamic-programming)
4. [Searches](#searches)
5. [Sorting Algorithms](#sorting-algorithms)

---

## Greedy

Greedy algorithms take a set of candidates as input and return a subset that maximizes benefits or minimizes costs.

**Example**  
Input: `[Candidate-1, Candidate-2, Candidate-3, Candidate-4]`  
Output: `[Candidate-1, Candidate-3]`

To achieve this, greedy algorithms rely on the principle of optimality, which assumes that choosing the best candidate at each step will lead to the best overall solution.

**Coin Example**  
We need €300 using the minimum number of coins (1€, 5€, 10€, 50€).  
Input: `[1€ × 10, 5€ × 10, 10€ × 10, 50€ × 10]`  
Steps:
- Use as many 50€ coins as possible.
- Then use 10€, etc.

Output: `[50€, 50€, 50€, 50€, 50€, 50€]` → **6 coins**

---

## Divide and Conquer

Divide and conquer algorithms break the problem into smaller subproblems that are easier to solve, then combine their results to solve the original problem.

**Example: Merge Sort**  
Input: `[4, 2, 6, 1, 9]`

```
Divide 1: [4, 2] and [6, 1, 9]      → [2, 4] and [1, 6, 9]
Divide 2: [6, 1] and [9]            → [1, 6] and [9]
Merge 1:  [1, 6] and [9]            → [1, 6, 9]
Merge 2:  [2, 4] and [1, 6, 9]      → [1, 2, 4, 6, 9]
```

---

## Dynamic Programming

Dynamic programming solves problems by storing and reusing previous results, often using a matrix or table.

**Example: Binomial Coefficients**

Recursive formula:

```
C(n, m) = 0                     if m > n  
C(n, m) = 1                     if m == 0 or m == n  
C(n, m) = C(n−1, m−1) + C(n−1, m)   otherwise
```

Matrix:

```
      m →  0   1   2   3
    n ↓
        +---------------
    0 |   1
    1 |   1   1
    2 |   1   2   1
    3 |   1   3   3   1
```

So: **C(3, 2) = 3**

---

## Searches

Search algorithms apply actions starting from an initial node to reach a goal node. A node usually stores state, cost, depth, heuristic, or path.

There are two main types:

- **Uninformed Search** (no extra knowledge):
  - Exhaustive Search
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Depth-Limited Search
  - Iterative Deepening DFS

- **Informed Search** (uses heuristics or costs):
  - Uniform Cost Search
  - A* Search
  - Approximate Searches:
    - Greedy Search
    - Beam Search

**Example: Water Jug Problem**  
Goal: Get 1L using jugs of 2L and 5L.  
Actions: Fill, empty, or pour from one jug into the other.

Solution (Depth-First Search):

```
Step 1: (2L, 0L)
Step 2: (0L, 2L)
Step 3: (2L, 2L)
Step 4: (0L, 4L)
Step 5: (2L, 4L)
Step 6: (1L, 5L)
Step 7: (0L, 5L) → Success!
```

---

## Sorting Algorithms

Sorting algorithms arrange a list of elements in a specific order (usually ascending).

Common algorithms:

- **Bubble Sort** – O(N²)
- **Insertion Sort** – O(N²)
- **Selection Sort** – O(N²)
- **Heap Sort** – O(N·logN)
- **Merge Sort** – O(N·logN)
- **Quick Sort** – O(N²) worst case, but typically O(N·logN)
- *(... and others)*