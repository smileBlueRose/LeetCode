class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        longest = 0
        nums_set = set(nums)
        for i in nums_set:
            if i - 1 not in nums_set:
                cnt = 0
                while i + cnt in nums_set:
                    cnt += 1
                if cnt > longest:
                    longest = cnt
        return longest
