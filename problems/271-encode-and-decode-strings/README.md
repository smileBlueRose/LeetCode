# 271. Encode and Decode Strings

https://leetcode.com/problems/encode-and-decode-strings

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

```java
String encode(List<String> strs) {
  // ... your code
  return encoded_string;
}
```

Machine 2 (receiver) has the function:

```java
List<String> decode(String encoded_string) {
  // ... your code
  return decoded_strs;
}
```

So Machine 1 does:

```java
String encoded_string = encode(strs);
```

and Machine 2 does:

```java
List<String> decoded_strs = decode(encoded_string);
```

`decoded_strs` in Machine 2 should be equal to `strs` in Machine 1.

&nbsp;

**Example 1:**

**Input:** strs = ["Hello","World"]
**Output:** ["Hello","World"]

**Example 2:**

**Input:** strs = [""]
**Output:** [""]

&nbsp;

**Constraints:**

* `0 <= strs.length < 100`
* `0 <= strs[i].length < 200`
* `strs[i]` contains any possible characters out of `256` valid ASCII characters.

&nbsp;

**Follow up:** Could you write a generalized algorithm to work on any possible set of characters?

&nbsp;

## Solution idea: Length-prefixed encoding

Encode each string as `<length>#<string>`, using `#` as a separator between the length prefix and the string content. To decode, read digits until `#` to get the length, then read exactly that many characters as the string, and repeat until the encoded string is consumed. This avoids ambiguity with delimiter characters appearing inside the strings themselves.

Time and space complexity: $O(m)$ time per `encode()`/`decode()` call and $O(m+n)$ space, where `m` is the sum of lengths of all strings and `n` is the number of strings.