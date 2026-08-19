# 108. Convert Sorted Array to Binary Search Tree

[https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)

Given an integer array `nums` where the elements are sorted in ascending order, convert it to a **height-balanced** binary search tree.

&nbsp;

**Example 1:**

**Input:** nums = [-10,-3,0,5,9]
**Output:** [0,-3,9,-10,null,5]
**Explanation:** [0,-10,5,null,-3,null,9] is also accepted:

**Example 2:**

**Input:** nums = [1,3]
**Output:** [3,1]
**Explanation:** [1,null,3] and [3,1] are both height-balanced BSTs.

&nbsp;

**Constraints:**

* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `nums` is sorted in a strictly increasing order.

&nbsp;

## Solution idea

To construct a height-balanced Binary Search Tree (BST) from a strictly increasing array, we can leverage a recursive **Divide and Conquer** strategy, similar to binary search.

* **Root Selection:** To ensure the tree remains balanced, the middle element of the array (or subarray) must be chosen as the root of the current subtree. This splits the array into two halves of roughly equal size.
* **Recursive Construction:**
* The elements to the left of the middle element are recursively converted into the **left subtree**.
* The elements to the right of the middle element are recursively converted into the **right subtree**.


* **Base Case:** When the subsegment becomes empty (e.g., `start > end` or `size <= 0`), return `null`.

Since each step reduces the problem size by half, the total depth of the tree will be $O(\log N)$, guaranteeing a height-balanced BST in $O(N)$ time complexity.