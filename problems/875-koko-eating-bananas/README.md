# Koko Eating Bananas

https://leetcode.com/problems/koko-eating-bananas

Koko loves to eat bananas. There are `n` piles of bananas, the `ith` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

&nbsp;

**Example 1:**

**Input:** `piles = [3,6,7,11], h = 8`
**Output:** `4`

**Example 2:**

**Input:** `piles = [30,11,23,4,20], h = 5`
**Output:** `30`

**Example 3:**

**Input:** `piles = [30,11,23,4,20], h = 6`
**Output:** `23`

&nbsp;

**Constraints:**
- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

&nbsp;

## Solution idea

As the eating speed `k` increases, the total hours needed to finish all piles decreases monotonically (using ceiling division per pile, since a partial pile still costs a full hour). This monotonic relationship means binary search can be applied to find the minimum valid `k`.

Binary search `k` over `[1, max(piles)]` — speeds below 1 make no sense, and a speed equal to the largest pile always finishes any single pile in one hour. For each candidate speed, compute the total hours required; if it fits within `h`, try a smaller speed, otherwise try a larger one. The smallest speed that still meets the deadline is the answer.

**Time complexity:** O(n * log(max(piles))) — binary search over the speed range, with an O(n) pass to compute total hours at each step.

**Space complexity:** O(1) — only a fixed number of variables used, no extra structures.