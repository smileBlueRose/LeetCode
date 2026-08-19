from typing import List, Optional


class TreeNode:
    def __init__(self, val: int, left: 'TreeNode', right: 'TreeNode'):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:        
        tree = self.rec(nums)
        return tree


    def rec(self, nums: list[int]):
        if not len(nums):
            return None

        mid = len(nums) // 2
        tree = TreeNode(nums[mid])
        tree.left = self.rec(nums[:mid])
        tree.right = self.rec(nums[mid + 1:])

        return tree