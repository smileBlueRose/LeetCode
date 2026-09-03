# 628. Maximum Product of Three Numbers

https://leetcode.com/problems/maximum-product-of-three-numbers

You are given an integer array `nums`.

Find three numbers whose product is maximum and return the maximum product.

&nbsp;

**Example 1:**

**Input:** nums = [1,2,3]
**Output:** 6

**Example 2:**

**Input:** nums = [1,2,3,4]
**Output:** 24

**Example 3:**

**Input:** nums = [-1,-2,-3]
**Output:** -6

&nbsp;

**Constraints:**

* `3 <= nums.length <= 10^4`
* `-1000 <= nums[i] <= 1000`

&nbsp;

## Solution idea

The maximum product of three numbers comes from one of two cases: the three largest numbers, or the two smallest (most negative) numbers combined with the largest number, since two negatives multiply into a positive.

Track the three largest values (`max1 >= max2 >= max3`) and the two smallest values (`min1 <= min2`) in a single pass. For each element, update the max trio by shifting values down when a larger one is found, and update the min pair the same way.

Time complexity: $O(n)$ — a single pass over `nums`.

Space complexity: $O(1)$ — only a fixed number of tracking variables are used.