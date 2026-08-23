# 58. Length of Last Word

https://leetcode.com/problems/length-of-last-word

Given a string `s` consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

&nbsp;

**Example 1:**

**Input:** s = "Hello World"
**Output:** 5
**Explanation:** The last word is "World" with length 5.

**Example 2:**

**Input:** s = "   fly me   to   the moon  "
**Output:** 4
**Explanation:** The last word is "moon" with length 4.

**Example 3:**

**Input:** s = "luffy is still joyboy"
**Output:** 6
**Explanation:** The last word is "joyboy" with length 6.

&nbsp;

**Constraints:**

* `1 <= s.length <= 10^4`
* `s` consists of only English letters and spaces `' '`.
* There will be at least one word in `s`.

&nbsp;

## Solution idea
 
Scan the string from the right. First skip over any trailing spaces to find the end of the last word, then continue scanning left while characters are non-space, counting how many are seen — that count is the answer. The boundary check (has the start of the string been reached?) must be evaluated before stepping the pointer/index further left, not after, otherwise the scan can step one position past the start of the string while looking for a stop condition that was already satisfied.
 
Time and space complexity: $O(n)$ where n is `s.length`.