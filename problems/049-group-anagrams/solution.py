class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        result = {}
        for s in strs:
            key = ''.join(sorted(s))
            result.setdefault(key, []).append(s)
        return list(result.values())