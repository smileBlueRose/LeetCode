# Longest Common Prefix

https://leetcode.com/problems/longest-common-prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

&nbsp;

**Example 1:**  
**Input:** `strs = ["flower","flow","flight"]`  
**Output:** `"fl"`


**Example 2:**  
**Input:** `strs = ["dog","racecar","car"]`  
**Output:** `""`  
**Explanation:** There is no common prefix among the input strings.

&nbsp;

**Constraints:**
- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters if it is non-empty.

&nbsp;

## Solution idea

Pick `strs[0]` as the initial candidate prefix. Then for every other string in the array, trim the candidate down to the length where it stops matching that string (from the back, or by finding the first mismatching index). After processing all strings, whatever remains is the longest common prefix.

**Time complexity:** O(S) — where S is the sum of all characters across all strings.

**Space complexity:** O(1) — excluding the space needed to store the output.