### 155. Min Stack

https://leetcode.com/problems/min-stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

&nbsp;

**Example 1:**

- **Input:** `["MinStack","push","push","push","getMin","pop","top","getMin"]`, `[[],[-2],[0],[-3],[],[],[],[]]`
- **Output:** `[null,null,null,null,-3,null,0,-2]`
- **Explanation:**
    - `minStack.push(-2)`
    - `minStack.push(0)`
    - `minStack.push(-3)`
    - `minStack.getMin()` returns `-3`
    - `minStack.pop()`
    - `minStack.top()` returns `0`
    - `minStack.getMin()` returns `-2`

&nbsp;

**Constraints:**

- `-2^31 <= val <= 2^31 - 1`
- Methods `pop`, `top` and `getMin` operations will always be called on non-empty stacks.
- At most `3 * 10^4` calls will be made to `push`, `pop`, `top`, and `getMin`.

&nbsp;

## Solution idea:

- Maintain a second array `mins` parallel to the values stack.
- `mins[i]` stores the minimum of `values[0..i]`.
- Each push computes `mins[pos]` as `min(value, mins[pos-1])`.
- `getMin()` is just `mins[pos]` — O(1) for every operation.