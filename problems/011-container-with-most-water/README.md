# 11. Container With Most Water

https://leetcode.com/problems/container-with-most-water

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

&nbsp;

**Example 1:**

**Input:** height = [1,8,6,2,5,4,8,3,7]
**Output:** 49
**Explanation:** The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

**Example 2:**

**Input:** height = [1,1]
**Output:** 1

**Constraints:**

* `n == height.length`
* `2 <= n <= 10^5`
* `0 <= height[i] <= 10^4`

&nbsp;

## Solution idea

Use a two-pointer approach starting at both ends of the array. At each step, compute the container area using the distance between pointers and the shorter line: area = width * min_height. Move the pointer pointing to the shorter height inward, as moving the taller line cannot increase the area. Keeping a running max of the area gives the optimal result in a single pass.

Time complexity: $O(n)$, where n is the length of the array. Space complexity: $O(1)$.