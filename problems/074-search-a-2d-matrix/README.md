# Search a 2D Matrix

https://leetcode.com/problems/search-a-2d-matrix

You are given an `m x n` integer matrix `matrix` with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution in `O(log(m * n))` time complexity.

&nbsp;

**Example 1:**

**Input:** `matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3`
**Output:** `true`

**Example 2:**

**Input:** `matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13`
**Output:** `false`

&nbsp;

**Constraints:**
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

&nbsp;

## Solution idea

Since each row is sorted and continues from where the previous one ends, the whole matrix can be treated as one flat sorted array of size `rows * cols`. Binary search over the range `[0, rows * cols - 1]`, converting each flat index `mid` back to 2D coordinates via `row = mid / cols` and `col = mid % cols` to access `matrix[row][col]`. Narrow the search range based on the standard binary search comparison until `target` is found or the range is exhausted.

**Time complexity:** O(log(m * n)) — binary search over all `m * n` elements treated as one sorted array.

**Space complexity:** O(1) — only a fixed number of variables used, no extra structures.