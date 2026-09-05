# Longest Repeating Character Replacement

https://leetcode.com/problems/longest-repeating-character-replacement

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

&nbsp;

**Example 1:**  
**Input:** `s = "ABAB", k = 2`  
**Output:** `4`  
**Explanation:** Replace the two 'A's with two 'B's or vice versa.


**Example 2:**  
**Input:** `s = "AABABBA", k = 1`  
**Output:** `4`  
**Explanation:** Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the longest repeating letters, which is 4. There may exist other ways to achieve this answer too.

&nbsp;

**Constraints:**
- `1 <= s.length <= 10^5`
- `s` consists of only uppercase English letters.
- `0 <= k <= s.length`

&nbsp;

## Solution idea

Sliding window `[left, right]` over the whole string. Track `count[26]` — frequency of each letter in the current window, and `max_freq` — the highest frequency ever seen for any single letter (not necessarily in the current window). A window is valid if `window_size - max_freq <= k` (i.e., replacing all non-dominant letters costs at most k operations). If the window becomes invalid after including `s[right]`, shrink it by moving `left` forward by one — this is always enough since the window grew by exactly 1.

`max_freq` is never decreased on shrink, so it can become stale (higher than the true max frequency currently in the window). This is safe: `max_freq` only ever increases when `count[s[right]]` sets a new record, and at that exact moment it is guaranteed accurate (count[] is always exact), so `res` is updated with a genuinely valid window size. Between such updates, `max_freq` stays fixed, which caps `window` at `max_freq + k` — the window can grow by 1 and immediately shrink back by 1, but can never exceed a size already validated earlier. So a stale `max_freq` never lets `res` grow incorrectly; it can only let the window coast at a size it already legitimately reached.

**Time complexity:** O(n) — each index enters/leaves the window at most once.

**Space complexity:** O(1) — `count[26]` is fixed size, independent of input length.