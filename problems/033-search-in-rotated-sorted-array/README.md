# Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array

There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly left rotated at an unknown index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed). For example, `[0,1,2,4,5,6,7]` might be left rotated by `3` indices and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

&nbsp;

**Example 1:**

**Input:** `nums = [4,5,6,7,0,1,2], target = 0`
**Output:** `4`

**Example 2:**

**Input:** `nums = [4,5,6,7,0,1,2], target = 3`
**Output:** `-1`

**Example 3:**

**Input:** `nums = [1], target = 0`
**Output:** `-1`

&nbsp;

**Constraints:**
- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are unique.
- `nums` is an ascending array that is possibly rotated.
- `-10^4 <= target <= 10^4`

&nbsp;

## Solution idea

First locate the rotation point with a binary search: compare `nums[mid]` to `nums[right]`. If `nums[mid] > nums[right]`, the break lies to the right of `mid`, so move `left = mid + 1`; otherwise the segment from `mid` to `right` is already sorted, so move `right = mid`. When the range collapses to one element, that's the index of the minimum.

Once the rotation point (`min_index`) is known, the array splits into two sorted segments: `[0, min_index - 1]` and `[min_index, size - 1]`. Check which segment's value range contains `target` and set `left`/`right` to that segment's bounds; if `target` falls in neither range, it can't be in the array, so return `-1` immediately. Then run a standard binary search within the chosen segment.

**Time complexity:** O(log n) — two binary searches in sequence, each halving its range.

**Space complexity:** O(1) — only a fixed number of variables used, no extra structures.