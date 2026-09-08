# Merge Two Sorted Lists

https://leetcode.com/problems/merge-two-sorted-lists

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

&nbsp;

**Example 1:**

**Input:** `list1 = [1,2,4], list2 = [1,3,4]`
**Output:** `[1,1,2,3,4,4]`

**Example 2:**

**Input:** `list1 = [], list2 = []`
**Output:** `[]`

**Example 3:**

**Input:** `list1 = [], list2 = [0]`
**Output:** `[0]`

&nbsp;

**Constraints:**
- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in non-decreasing order.

## Solution idea

Use a dummy node as a placeholder before the merged list's actual head, so there's no special-case handling for attaching the first node. Walk `list1` and `list2` simultaneously, at each step splicing whichever current node has the smaller value onto the tail of the result, then advancing that list's pointer and the result's tail pointer. Once one list is exhausted, the other still holds a sorted remainder, so splice it onto the tail in one shot rather than node-by-node. Finally, skip past the dummy node to get the real head, and free the dummy since it was only scaffolding.

**Time complexity:** O(n + m) — each node from both lists is visited exactly once.

**Space complexity:** O(1) — nodes are relinked in place, no new nodes are allocated.
