# Remove Nth Node From End of List

https://leetcode.com/problems/remove-nth-node-from-end-of-list

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

&nbsp;

**Example 1:**

**Input:** `head = [1,2,3,4,5], n = 2`
**Output:** `[1,2,3,5]`

**Example 2:**

**Input:** `head = [1], n = 1`
**Output:** `[]`

**Example 3:**

**Input:** `head = [1,2], n = 1`
**Output:** `[1]`

&nbsp;

**Constraints:**
- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

&nbsp;

## Solution idea

First pass through the list to count its total length `len`. The node to remove, counted from the front, sits at index `len - n`. If that index is `0`, the head itself must be removed, so special-case it by returning `head->next` and freeing the old head. Otherwise, walk `prev` and `node` forward together until `node` reaches the target index, keeping `prev` one step behind so it points at the node before it. Then splice `node` out by linking `prev->next` directly to `node->next`, and free `node`.

**Time complexity:** O(n) — one pass to find the length, another to reach the target node.

**Space complexity:** O(1) — only a fixed number of pointers used, no extra structures.