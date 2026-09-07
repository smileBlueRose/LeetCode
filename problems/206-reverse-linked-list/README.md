# Reverse Linked List

https://leetcode.com/problems/reverse-linked-list

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

&nbsp;

**Example 1:**

**Input:** `head = [1,2,3,4,5]`
**Output:** `[5,4,3,2,1]`

**Example 2:**

**Input:** `head = [1,2]`
**Output:** `[2,1]`

**Example 3:**

**Input:** `head = []`
**Output:** `[]`

&nbsp;

**Constraints:**
- The number of nodes in the list is the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

&nbsp;

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## Solution idea

Iterate through the list once, at each node redirecting its `next` pointer to point backward (to `prev`) instead of forward. Before overwriting `curr->next`, save it in `next` so the rest of the list isn't lost. Advance `prev` and `curr` one step forward each iteration. When `curr` becomes `NULL`, `prev` holds the new head of the reversed list.

**Time complexity:** O(n) — single pass over the list.

**Space complexity:** O(1) — only a fixed number of pointers used, no extra structures.