# 42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water

You are given `n` non-negative integers representing an elevation map where the width of each bar is `1`.

Compute how much water it can trap after raining.

&nbsp;

**Example 1:**

**Input:** height = [0,1,0,2,1,0,1,3,2,1,2,1]
**Output:** 6
**Explanation:** The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

**Example 2:**

**Input:** height = [4,2,0,3,2,5]
**Output:** 9

**Constraints:**

- `n == height.length`
- `1 <= n <= 2 * 10^4`
- `0 <= height[i] <= 10^5`

&nbsp;

## Solution idea

Water above point i can't rise higher than the smaller of the two maximums — the max to the left and the max to the right — because it would spill over on the shorter side. That smaller value is the water level at point i.

To know this value for every point, you need the max to the left and right of each i. So the maximums are computed once and stored in two arrays: lmax_arr[i] — the max to the left, filled with a left-to-right pass, rmax_arr[i] — the max to the right, filled with a right-to-left pass.

Then for each i, take the smaller of lmax_arr[i] and rmax_arr[i] — that's the water level at that point. The water layer above the bar equals the difference between this level and height[i], but only if the water level is higher than the bar itself — otherwise there's no water there, and 0 is added.

Time complexity: $O(n)$  
Space complexity: $O(n)$