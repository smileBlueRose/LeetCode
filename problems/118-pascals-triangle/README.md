# 118. Pascal's Triangle

https://leetcode.com/problems/pascals-triangle

Given an integer `numRows`, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it, as shown.

&nbsp;

**Example 1:**

**Input:** numRows = 5
**Output:** [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

**Example 2:**

**Input:** numRows = 1
**Output:** [[1]]

&nbsp;

**Constraints:**

* `1 <= numRows <= 30`

&nbsp;

## Solution idea

Each row is built so that the first and last elements are always 1. For every inner index j (where 0 < j < i), the value is the sum of two elements from the previous row: row[j-1] and row[j] — the two elements directly above it in the triangle.

The inner loop only runs up to i - 1 (exclusive), skipping the last index i, because the last element of the row is already fixed to 1 and has no "two elements above" to sum — it only has one neighbor above it, not two.

Time and space complexity: $O(n^2)$ where n is `numRows`.