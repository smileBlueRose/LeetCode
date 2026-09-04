# 3. Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters

Given a string s, find the length of the longest substring without duplicate characters. 

**Example 1:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
```

**Example 2:**
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

&nbsp;

**Constraints:**

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

&nbsp;

## Solution idea

Use a sliding window [left, right] that always contains no duplicate characters. Move right forward one step at a time, adding the new character. If that character already appeared inside the current window, move left forward to just past its previous occurrence, so the window stays duplicate-free. To find previous occurrences in O(1), keep an array last_seen mapping each character to the last index it was seen at. After each step, the window length right - left + 1 is a candidate for the answer — track the maximum.

Time: O(n)  
Space: O(1) (fixed 256-entry array for byte values)