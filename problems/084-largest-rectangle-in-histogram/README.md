# Largest Rectangle in Histogram

https://leetcode.com/problems/largest-rectangle-in-histogram

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return the area of the largest rectangle in the histogram.

**Example 1:**
```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

**Example 2:**
```
Input: heights = [2,4]
Output: 4
```

**Constraints:**

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

## Solution Idea

Use a monotonic increasing stack of indices. Append a sentinel `0` at the end of the array so every remaining bar gets popped and processed.

Iterate through the array:
- If the current bar's height is `>=` the height at the top of the stack, push its index.
- Otherwise, pop indices while the stack top's height is greater than the current height. For each popped index `k`, the current index `i` is the first bar to the right that is smaller, and the new stack top (or `-1` if empty) is the first bar to the left that is smaller. The width of the rectangle with height `heights[k]` is `i - left - 1`, and its area is `width * heights[k]`. Push `i` after the pops.

Track the maximum area seen across all pops. This runs in O(n) time since each index is pushed and popped at most once, and O(n) space for the stack.