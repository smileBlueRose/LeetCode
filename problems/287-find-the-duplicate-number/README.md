# Find the Duplicate Number

https://leetcode.com/problems/find-the-duplicate-number

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only one repeated number in `nums`, return this repeated number.

You must solve the problem without modifying the array `nums` and using only constant extra space.

&nbsp;

**Example 1:**  
**Input:** `nums = [1,3,4,2,2]`  
**Output:** `2`

**Example 2:**  
**Input:** `nums = [3,1,3,4,2]`  
**Output:** `3`

**Example 3:**  
**Input:** `nums = [3,3,3,3,3]`  
**Output:** `3`

&nbsp;

**Constraints:**
- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All the integers in `nums` appear only once except for precisely one integer which appears two or more times.

&nbsp;

**Follow up:**
- How can we prove that at least one duplicate number must exist in `nums`?
- Can you solve the problem in linear runtime complexity?

&nbsp;

## Solution idea

**Solution 1** — use a boolean array `digits` indexed by value to track seen numbers. Scan `nums` once; the first value already marked in `digits` is the duplicate.

**Time complexity:** O(n) — single pass over the array.

**Space complexity:** O(n) — auxiliary array sized to the value range.

**Solution 2** — treat `nums` as a function `f(i) = nums[i]` mapping each index to another index in `[1, n]`. Since one value repeats, at least two indices map to it, which means following `f` repeatedly must eventually enter a cycle (like a linked list with a loop) — the duplicate value is exactly the entry point of that cycle.

This is Floyd's cycle detection (tortoise and hare), applied to that implicit function graph instead of a real linked list:

1. **Phase 1 — detect the cycle:** `slow` moves one step (`slow = nums[slow]`), `fast` moves two steps (`fast = nums[nums[fast]]`). Because fast gains on slow by one step per iteration inside a finite cycle, they're guaranteed to meet somewhere inside it.
2. **Phase 2 — find the entry point:** reset `slow` to the start (index 0, which isn't part of the cycle since values are in `[1, n]`, never 0), keep `fast` at the meeting point, then move both one step at a time. The classic Floyd proof (distance from start to cycle entry equals distance from meeting point to cycle entry, going around the cycle) guarantees they meet exactly at the entry — which is the duplicate number.

**Time complexity:** O(n) — both phases traverse the sequence a bounded number of times.

**Space complexity:** O(1) — only a few integer variables, no extra array; satisfies the problem's constraint.