# 217. Contains Duplicate

https://leetcode.com/problems/contains-duplicate

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

&nbsp;

**Example 1:**

**Input:** nums = [1,2,3,1]
**Output:** true
**Explanation:**
The element 1 occurs at the indices 0 and 3.

**Example 2:**

**Input:** nums = [1,2,3,4]
**Output:** false
**Explanation:**
All elements are distinct.

**Example 3:**

**Input:** nums = [1,1,1,3,3,4,3,2,4,2]
**Output:** true

&nbsp;

**Constraints:**

* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`

&nbsp;

## Solution idea 1: Hash Set

Iterate through the array while storing visited elements in a hash set. At each step, check if the current value is already present in the set. If it is, a duplicate exists. Otherwise, add the value to the set and continue.

Time and space complexity: $O(n)$ time and $O(n)$ space, where n is `nums.length`.

&nbsp;

## Solution idea 2: Sorting

Sort the array in ascending order so that identical values become adjacent. Then scan the sorted array linearly, comparing each element with the neighboring one. If two adjacent elements are equal, a duplicate exists.

Time and space complexity: $O(n \log n)$ time for sorting and $O(1)$ extra space if sorted in place.