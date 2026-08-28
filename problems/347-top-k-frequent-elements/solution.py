class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        count = {}
        for i in nums:
            count[i] = count.get(i, 0) + 1
        buckets = [[] for _ in range(len(nums) + 1)]
        
        for n, freq in count.items():
            buckets[freq].append(n)
        result = []

        for i in range(len(buckets) - 1, 0, -1):
            if len(buckets[i]):
                result.extend(buckets[i])
                if len(result) >= k:
                    break

        return result[:k]
