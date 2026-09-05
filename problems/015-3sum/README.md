# 15. 3Sum

https://leetcode.com/problems/3sum

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

&nbsp;

**Example 1:**  
**Input:** `nums = [-1,0,1,2,-1,-4]`  
**Output:** `[[-1,-1,2],[-1,0,1]]`


**Example 2:**  
**Input:** `nums = [0,1,1]`  
**Output:** `[]`


**Example 3:**  
**Input:** `nums = [0,0,0]`  
**Output:** `[[0,0,0]]`

&nbsp;

**Constraints:**
- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

&nbsp;

## Solution idea

First sort `nums`. Then fix the first element at index `i` and use two pointers `left = i + 1` and `right = nums_size - 1` to scan the remaining sorted subarray for a pair that sums to `-nums[i]`.

If `sum == 0`, a triplet is found; move both pointers inward while skipping duplicates to avoid repeating the same triplet. If `sum < 0`, `left` moves right to increase the sum; if `sum > 0`, `right` moves left to decrease it.

Duplicate triplets are avoided by skipping repeated values for `i` (comparing to `nums[i-1]`) and for `left`/`right` after a match is found.

**Time complexity:** O(n^2) — sorting is O(n log n), and the outer loop with the two-pointer scan is O(n^2).

**Space complexity:** O(n) for the output, plus O(log n) to O(n) for the sort's recursion stack, depending on implementation.