# Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of unique elements, return the minimum element of this array.

You must write an algorithm that runs in `O(log n) time`.

&nbsp;

**Example 1:**

**Input:** `nums = [3,4,5,1,2]`
**Output:** `1`
**Explanation:** The original array was `[1,2,3,4,5]` rotated 3 times.

**Example 2:**

**Input:** `nums = [4,5,6,7,0,1,2]`
**Output:** `0`
**Explanation:** The original array was `[0,1,2,4,5,6,7]` and it was rotated 4 times.

**Example 3:**

**Input:** `nums = [11,13,15,17]`
**Output:** `11`
**Explanation:** The original array was `[11,13,15,17]` and it was rotated 4 times.

&nbsp;

**Constraints:**
- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are unique.
- `nums` is sorted and rotated between `1` and `n` times.

&nbsp;

## Solution idea

At each step, compare `nums[mid]` to `nums[right]` to decide which half contains the rotation point (the minimum). If `nums[mid] > nums[right]`, the break between the two sorted segments lies to the right of `mid`, so the minimum is in `[mid+1, right]`. If `nums[mid] < nums[right]`, the segment from `mid` to `right` is already sorted with no break, so the minimum is at `mid` or somewhere to its left, meaning `right` narrows to `mid` itself rather than `mid - 1`. The search range keeps shrinking toward the rotation point until it collapses to a single element, which is the minimum.

**Time complexity:** O(log n) — binary search halves the search range each iteration.

**Space complexity:** O(1) — only a fixed number of variables used, no extra structures.