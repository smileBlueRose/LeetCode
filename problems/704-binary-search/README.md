# Binary Search

https://leetcode.com/problems/binary-search

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

&nbsp;

**Example 1:**  
**Input:** `nums = [-1,0,3,5,9,12], target = 9`  
**Output:** `4`  
**Explanation:** 9 exists in nums and its index is 4.


**Example 2:**  
**Input:** `nums = [-1,0,3,5,9,12], target = 2`  
**Output:** `-1`  
**Explanation:** 2 does not exist in nums so return -1.

&nbsp;

**Constraints:**
- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- All the integers in `nums` are unique.
- `nums` is sorted in ascending order.

&nbsp;

## Solution idea
 
Maintain two pointers `left` and `right` spanning the current search range. While `left <= right`, compute `mid`, compare `nums[mid]` to `target`: if equal, return `mid`; if `nums[mid] < target`, discard the left half by setting `left = mid + 1`; otherwise discard the right half by setting `right = mid - 1`. If the range becomes empty, return `-1`.
 
**Time complexity:** O(log n) — each step halves the search range.
 
**Space complexity:** O(1) — only a constant number of pointers used.