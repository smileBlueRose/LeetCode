# Search Insert Position

https://leetcode.com/problems/search-insert-position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**  
Input: nums = [1,3,5,6], target = 5  
Output: 2

**Example 2:**  
Input: nums = [1,3,5,6], target = 2  
Output: 1

**Example 3:**  
Input: nums = [1,3,5,6], target = 7  
Output: 4

**Constraints:**
- `1 <= nums.length <= 104`  
- `-104 <= nums[i] <= 104`  
- `nums` contains distinct values sorted in ascending order.  
- `-104 <= target <= 104`  

## Solution idea

Binary search: use two pointers (`left` and `right`) to narrow down a search range where the target or its insertion position must lie.

You calculate `mid` securely as `left + (right - left) / 2` to prevent overflow and compare `nums[mid]` to `target`. If they match, you return `mid` immediately. If `nums[mid]` is smaller, you eliminate the left half by setting `left = mid + 1`; otherwise, you eliminate the right half by setting `right = mid - 1`.

When `left` crosses `right`, the loop ends. At this exact moment, `left` points to the precise index where `target` belongs to keep the array sorted, so you return `left`.