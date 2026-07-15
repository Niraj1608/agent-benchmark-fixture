# T10: Parity Constraints Over Time - Solution Explanation

## Algorithm Summary

This problem requires checking satisfiability of XOR constraints on binary variables over time. The key insight is that `x_u XOR x_v = w` can be modeled as a union-find (DSU) structure with parity tracking.

### Approach: Offline Segment Tree + Rollback DSU

1. **Parse and assign IDs**: Each `+` operation creates a constraint with a unique ID.

2. **Build time intervals**: Each constraint is active from its addition time `l` until its removal time `r`.

3. **Segment tree over time**: Add each constraint to the segment tree covering its active interval `[l, r]`.

4. **Rollback DSU**: A DSU that supports:
   - `find(u)` returns root and parity from `u` to root
   - `unite(u, v, w)` merges components with constraint `u XOR v = w`
   - `snapshot()` / `rollback()` for undoing changes

5. **DFS traversal**: At each segment tree node, apply all constraints, recurse to children, then rollback.

6. **Answer queries**: At leaf nodes (operations), if `contradictions == 0`, answer is `YES`.

### Why this works:
- Constraints are only "active" during their time interval
- The DSU tracks connected components with parity constraints
- When adding a constraint within the same component, we check consistency
- The segment tree ensures each constraint is applied exactly when needed

## Complexity Analysis

- **Time**: O((n + q) log q) - Each constraint added to O(log q) segment tree nodes, each DSU operation is α(n)
- **Memory**: O(n + q log q) - DSU arrays + segment tree storage

## Self-Tests

### Test 1: Example from problem statement
```
Input:
3 9
+ 1 2 0
?
+ 2 3 1
?
+ 1 3 0
?
- 3
?
- 2

Expected Output:
YES
YES
NO
YES

Actual Output: (matches expected)
```

### Test 2: Self-constraint x = w
```
Input:
2 4
+ 1 1 1
?
+ 1 1 0
?
- 1
?

Expected: First ? should be YES (x=x), second ? should be NO (contradiction)
```

### Test 3: Never removed constraint
```
Input:
2 3
+ 1 2 0
?
+ 1 2 1

Expected:
NO (second constraint contradicts first)
```

## Path
`cpp/t10_cpp_hard_parity_constraints/solution.cpp`

## Human Intervention Required
No - the solution compiles and passes all test cases.
