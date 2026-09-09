# Reorder List

https://leetcode.com/problems/reorder-list

You are given the head of a singly linked-list. The list can be represented as:

```
L0 → L1 → … → Ln - 1 → Ln
```

Reorder the list to be on the following form:

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

&nbsp;

**Example 1:**

**Input:** `head = [1,2,3,4]`
**Output:** `[1,4,2,3]`

**Example 2:**

**Input:** `head = [1,2,3,4,5]`
**Output:** `[1,5,2,4,3]`

&nbsp;

**Constraints:**
- The number of nodes in the list is in the range `[1, 5 * 10^4]`.
- `1 <= Node.val <= 1000`

&nbsp;

## Solution idea

Use two pointers, `slow` and `fast`, both starting at `head`, to find the middle of the list: `slow` advances one node per step while `fast` advances two, so when `fast` reaches the end, `slow` sits at the midpoint. Split the list there into a left half and a right half, then reverse the right half in place using the standard `prev`/`curr`/`next` iterative reversal — this gives exactly the order needed for interleaving. Finally, merge the two halves by alternating one node from the left half with one node from the reversed right half until the left half is exhausted, attaching whatever remains of the right half to the end.

**Time complexity:** O(n) — one pass to find the middle, one pass to reverse, one pass to merge.

**Space complexity:** O(1) — only pointer manipulation, no auxiliary data structures.