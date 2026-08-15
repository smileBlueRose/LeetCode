def two_sum(self, nums: list[int], target: int) -> tuple[int, int]:
    seen = {}
    for i, n in enumerate(nums):
        diff = target - n
        if diff in seen:
            return seen[diff], i
        seen[n] = i

    raise ValueError("no solution found")