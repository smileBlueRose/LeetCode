# 242. Valid Anagram

https://leetcode.com/problems/valid-anagram

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

&nbsp;

**Example 1:**

**Input:** s = "anagram", t = "nagaram"
**Output:** true

**Example 2:**

**Input:** s = "rat", t = "car"
**Output:** false

&nbsp;

**Constraints:**

* `1 <= s.length, t.length <= 5 * 10^4`
* `s` and `t` consist of lowercase English letters.

&nbsp;

## Solution idea: Frequency Array (Single Pass)

First, check if the lengths of `s` and `t` are equal. If not, return `false`. Maintain an array of size 26 to count character frequencies. Iterate through both strings simultaneously: increment the count for each character in `s` and decrement it for each character in `t`. Finally, verify that all elements in the frequency array equal zero.

Time and space complexity: $O(n)$ time and $O(1)$ space, where n is `s.length`.