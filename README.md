- 👋 Hi, I'm @codeBennyLaw
- 👀 I'm interested in programming
- 🌱 I'm currently learning cpp
- 💞️ I'm looking to collaborate on Huizhou High School
- 📫 My contact information: alilexiwalker@wyu.edu.cn.

## Bitwise OR Maximization Problem

This repository contains a solution to the competitive programming problem of maximizing the sum of bitwise OR operations between two arrays.

### Problem Description

Given two integers `l` and `r` (l ≤ r):
1. Create two arrays `a` and `b`, both initially equal to `[l, l+1, ..., r]`
2. Reorder array `a` to maximize `∑(a[i] | b[i])` where `|` is bitwise OR
3. Output the maximum value and the optimal reordering

### Solution Approach

The solution uses two strategies:
- For small ranges (≤10 elements): Brute force all permutations to find the optimal solution
- For larger ranges: Greedy heuristic that selects the best available element for each position

### Usage

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```

### Input Format
```
t
l1 r1
l2 r2
...
```

### Output Format
```
max_sum1
reordered_array1
max_sum2
reordered_array2
...
```

<!---
codeBennyLaw/codeBennyLaw is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
