# Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

&nbsp;

**Example 1:**  
**Input:** `nums = [1,3,-1,-3,5,3,6,7], k = 3`  
**Output:** `[3,3,5,5,6,7]`  
**Explanation:**
```
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Example 2:**  
**Input:** `nums = [1], k = 1`  
**Output:** `[1]`

&nbsp;

**Constraints:**
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

&nbsp;

## Solution idea

Use a deque that stores indices of `nums`, kept in decreasing order of their values. For each new index `i`: pop indices from the back while their values are less than `nums[i]` (they can never be the max again), then push `i`. Pop from the front if it falls outside the window (`front <= i - k`). Once `i >= k - 1`, the front of the deque is the max of the current window.

**Time complexity:** O(n) — each index is pushed and popped at most once.

**Space complexity:** O(k) — the deque holds at most `k` indices.