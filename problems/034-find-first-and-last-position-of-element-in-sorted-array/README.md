# 34. Find First and Last Position of Element in Sorted Array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

&nbsp;

**Example 1:**  
**Input:** `nums = [5,7,7,8,8,10], target = 8`  
**Output:** `[3,4]`


**Example 2:**  
**Input:** `nums = [5,7,7,8,8,10], target = 6`  
**Output:** `[-1,-1]`


**Example 3:**  
**Input:** `nums = [], target = 0`  
**Output:** `[-1,-1]`

&nbsp;

**Constraints:**
- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is a non-decreasing array.
- `-10^9 <= target <= 10^9`

&nbsp;

## Solution idea
 
Run two separate binary searches on `nums`: one to find the leftmost occurrence of `target` (`lower_bound`), and one to find the rightmost occurrence (`upper_bound`).
 
In `lower_bound`, when `nums[mid] == target`, check the neighbor at `mid - 1`: if it also equals `target`, narrow the search by setting `right = mid - 1` to keep looking further left; otherwise `mid` is the first occurrence, so return it.
 
In `upper_bound`, when `nums[mid] == target`, check the neighbor at `mid + 1`: if it also equals `target`, narrow the search by setting `left = mid + 1` to keep looking further right; otherwise `mid` is the last occurrence, so return it.
 
If either search exhausts the range without finding `target`, it returns `-1`.
 
**Time complexity:** O(log n) — two independent binary searches.
 
**Space complexity:** O(1) — excluding the output array.