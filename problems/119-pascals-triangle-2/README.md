# 119. Pascal's Triangle II

https://leetcode.com/problems/pascals-triangle-ii

Given an integer `rowIndex`, return the `rowIndex`th (0-indexed) row of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it, as shown.

&nbsp;

**Example 1:**

**Input:** rowIndex = 3
**Output:** [1,3,3,1]

**Example 2:**

**Input:** rowIndex = 0
**Output:** [1]

**Example 3:**

**Input:** rowIndex = 1
**Output:** [1,1]

&nbsp;

**Constraints:**

* `0 <= rowIndex <= 33`

**Follow up:** Could you optimize your algorithm to use only `O(rowIndex)` extra space?

&nbsp;

## Solution idea

Instead of building the triangle row by row, each element of the target row is computed directly from the previous element using the multiplicative relation between binomial coefficients: `res[i] = res[i-1] * (rowIndex - i + 1) / i`. This works because `C(n, k) = C(n, k-1) * (n - k + 1) / k`, so the row can be filled in a single left-to-right pass, starting from `res[0] = 1`.

Time and space complexity: $O(n)$ where n is `rowIndex`.