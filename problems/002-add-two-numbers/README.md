# Add Two Numbers

https://leetcode.com/problems/add-two-numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

&nbsp;

**Example 1:**  
**Input:** `l1 = [2,4,3], l2 = [5,6,4]`  
**Output:** `[7,0,8]`  
**Explanation:** 342 + 465 = 807.

**Example 2:**  
**Input:** `l1 = [0], l2 = [0]`  
**Output:** `[0]`

**Example 3:**  
**Input:** `l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]`  
**Output:** `[8,9,9,9,0,0,0,1]`

&nbsp;

**Constraints:**
- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution idea

Copy `l1`'s digits into a fixed-size buffer `res[101]` (max possible sum length), then walk `l2` in parallel, adding each digit plus carry directly into `res[i]` and reducing mod 10 in place. Once `l2` is exhausted, keep propagating any remaining carry through `res`. This avoids any separate carry-only pass over `l1`.

After the digit array is built, trim trailing zeros from the top (`last` marks the highest non-zero index, guarding against the all-zero case). Instead of allocating each `ListNode` separately, allocate one contiguous block of `last + 1` nodes and link them by pointer arithmetic — one `malloc` call instead of N.

**Time complexity:** O(n + m) — one pass over each list plus carry propagation.

**Space complexity:** O(n + m) — fixed-size digit buffer plus the output node array.