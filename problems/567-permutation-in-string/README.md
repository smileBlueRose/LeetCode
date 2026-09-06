# Permutation in String

https://leetcode.com/problems/permutation-in-string

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

&nbsp;

**Example 1:**  
**Input:** `s1 = "ab", s2 = "eidbaooo"`  
**Output:** `true`  
**Explanation:** s2 contains one permutation of s1 ("ba").


**Example 2:**  
**Input:** `s1 = "ab", s2 = "eidboaoo"`  
**Output:** `false`

&nbsp;

**Constraints:**
- `1 <= s1.length, s2.length <= 10^4`
- `s1` and `s2` consist of lowercase English letters.

&nbsp;

## Solution idea

Use a sliding window of size `s1.length` over `s2`, tracking character-frequency differences in a 26-element array `letters`, initialized with the counts from `s1`.

Instead of comparing all 26 counters on every window shift, maintain a single `mismatch_counter` that reflects how far the current window is from a valid permutation:
- When a character enters the window, decrement its count. If the count is still `>= 0`, that occurrence was needed, so `mismatch_counter` decreases; if it drops below `0`, it's an excess character, so `mismatch_counter` increases.
- When a character leaves the window, increment its count. If the count becomes `<= 0`, an excess occurrence was removed, so `mismatch_counter` decreases; otherwise a needed character was removed, so `mismatch_counter` increases.

The window is a valid permutation exactly when `mismatch_counter == 0`. Check this after building the initial window and after every shift.

**Time complexity:** O(n) — each character of `s2` is processed once when entering and once when leaving the window.

**Space complexity:** O(1) — fixed-size 26-element frequency array.