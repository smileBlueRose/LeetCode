# Climbing Stairs

https://leetcode.com/problems/climbing-stairs

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**
```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**
```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

**Constraints:**

- `1 <= n <= 45`

## Solution idea

Let `f(n)` be the number of ways to reach step `n`. The last move to reach step `n` was either a single step from `n-1`, or a double step from `n-2`. So `f(n) = f(n-1) + f(n-2)` — this is the Fibonacci recurrence. Compute it iteratively bottom-up in O(n) time and O(1) space, keeping only the last two values.