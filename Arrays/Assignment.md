# C++ Array Assignments — MAANG Interview Level

This assignment set contains **10 array problems** designed for engineering students preparing for MAANG-level coding interviews. The format follows NeetCode/LeetCode-style prompts: a clear problem statement, required function signature, examples, expected output, constraints, and additional test cases.

The problems progress from fundamental array manipulation to common interview patterns such as hash maps, two pointers, sliding windows, prefix sums, and in-place transformations. Implement the requested function rather than writing a separate full program for every problem.

## Assignment overview

| # | Problem | Difficulty | Main concept |
|---:|---|---|---|
| 1 | Two Sum | Easy | Hash map |
| 2 | Best Time to Buy and Sell Stock | Easy | One-pass tracking |
| 3 | Contains Duplicate | Easy | Hash set |
| 4 | Product of Array Except Self | Medium | Prefix and suffix products |
| 5 | Maximum Subarray | Medium | Kadane's algorithm |
| 6 | Move Zeroes | Easy | In-place two pointers |
| 7 | 3Sum | Medium | Sorting and two pointers |
| 8 | Longest Consecutive Sequence | Medium | Hash set |
| 9 | Subarray Sum Equals K | Medium | Prefix sums and frequency map |
| 10 | Trapping Rain Water | Hard | Two pointers / boundary maxima |

## Common C++ conventions

Use standard C++ vectors and the following general conventions:

- Arrays are represented as `vector<int>`.
- Indices are zero-based.
- Unless stated otherwise, return the requested result rather than printing it.
- When a problem asks for an in-place operation, do not create another array to hold the transformed result.
- For vector outputs where order is unspecified, any output satisfying the stated requirements is acceptable.

Include these headers as needed:

```cpp
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
```

---

## Problem 1 — Two Sum

**Difficulty:** Easy

### Problem statement

Write a function `twoSum` that takes an integer array `nums` and an integer `target`. Return the indices of two distinct elements whose values add up to `target`.

Assume exactly one valid answer exists. You may not use the same element twice. Return the two indices in either order.

### Function signature

```cpp
vector<int> twoSum(vector<int>& nums, int target);
```

### Examples

**Example 1**

```text
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9.
```

**Example 2**

```text
Input:  nums = [3, 2, 4], target = 6
Output: [1, 2]
```

**Example 3**

```text
Input:  nums = [3, 3], target = 6
Output: [0, 1]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `nums = [-1, -2, -3, -4, -5], target = -8` | `[2, 4]` |
| `nums = [0, 4, 3, 0], target = 0` | `[0, 3]` |
| `nums = [1, 5, 8, 10], target = 13` | `[1, 2]` |

### Constraints

- `2 <= nums.size() <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Exactly one valid answer exists.

**Required complexity:** Aim for `O(n)` time and `O(n)` auxiliary space.

**Interview follow-up:** How would your solution change if the array were sorted and you had to return the values rather than their original indices?

---

## Problem 2 — Best Time to Buy and Sell Stock

**Difficulty:** Easy

### Problem statement

Write a function `maxProfit` that takes an array `prices`, where `prices[i]` is the price of a stock on day `i`.

Choose one day to buy and a later day to sell. Return the maximum possible profit. If no positive profit is possible, return `0`.

You must buy before you sell.

### Function signature

```cpp
int maxProfit(vector<int>& prices);
```

### Examples

**Example 1**

```text
Input:  prices = [7, 1, 5, 3, 6, 4]
Output: 5
Explanation: Buy at 1 and sell at 6. Profit = 6 - 1 = 5.
```

**Example 2**

```text
Input:  prices = [7, 6, 4, 3, 1]
Output: 0
Explanation: No profitable transaction is possible.
```

**Example 3**

```text
Input:  prices = [2, 4, 1]
Output: 2
```

### Additional test cases

| Input | Expected output |
|---|---:|
| `[5]` | `0` |
| `[1, 2]` | `1` |
| `[2, 1, 2, 1, 0, 1, 2]` | `2` |
| `[3, 3, 3, 3]` | `0` |

### Constraints

- `1 <= prices.size() <= 10^5`
- `0 <= prices[i] <= 10^4`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** How would the problem change if you were allowed to complete as many buy/sell transactions as you wanted?

---

## Problem 3 — Contains Duplicate

**Difficulty:** Easy

### Problem statement

Write a function `containsDuplicate` that returns `true` if any integer appears at least twice in the array. Return `false` if every element is distinct.

### Function signature

```cpp
bool containsDuplicate(vector<int>& nums);
```

### Examples

**Example 1**

```text
Input:  nums = [1, 2, 3, 1]
Output: true
```

**Example 2**

```text
Input:  nums = [1, 2, 3, 4]
Output: false
```

**Example 3**

```text
Input:  nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
Output: true
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[]` | `false` |
| `[7]` | `false` |
| `[-1, 0, -1]` | `true` |
| `[0, 1, 2, 3, 4]` | `false` |

### Constraints

- `0 <= nums.size() <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

**Required complexity:** Aim for `O(n)` average time and `O(n)` auxiliary space.

**Interview follow-up:** Solve it by sorting the array. Compare the time and extra-space costs of both approaches, including whether sorting changes the input.

---

## Problem 4 — Product of Array Except Self

**Difficulty:** Medium

### Problem statement

Write a function `productExceptSelf` that returns an array `answer` such that `answer[i]` equals the product of every element in `nums` except `nums[i]`.

Do not use division. Your solution must run in `O(n)` time.

For the required space complexity, do not count the output array as auxiliary space.

### Function signature

```cpp
vector<int> productExceptSelf(vector<int>& nums);
```

### Examples

**Example 1**

```text
Input:  nums = [1, 2, 3, 4]
Output: [24, 12, 8, 6]
```

**Example 2**

```text
Input:  nums = [-1, 1, 0, -3, 3]
Output: [0, 0, 9, 0, 0]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[2, 3]` | `[3, 2]` |
| `[1, 0]` | `[0, 1]` |
| `[0, 0, 5]` | `[0, 0, 0]` |
| `[1, 1, 1, 1]` | `[1, 1, 1, 1]` |

### Constraints

- `2 <= nums.size() <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix fits in a signed 32-bit integer for the test cases used.

**Required complexity:** `O(n)` time and `O(1)` auxiliary space, excluding the output array.

**Interview follow-up:** Explain how to calculate prefix products in a forward pass and suffix products in a backward pass without storing separate prefix and suffix arrays.

---

## Problem 5 — Maximum Subarray

**Difficulty:** Medium

### Problem statement

Write a function `maxSubArray` that returns the largest possible sum of a **non-empty contiguous subarray**.

A subarray consists of consecutive elements from the original array.

### Function signature

```cpp
int maxSubArray(vector<int>& nums);
```

### Examples

**Example 1**

```text
Input:  nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: [4, -1, 2, 1] has the maximum sum, 6.
```

**Example 2**

```text
Input:  nums = [1]
Output: 1
```

**Example 3**

```text
Input:  nums = [5, 4, -1, 7, 8]
Output: 23
```

### Additional test cases

| Input | Expected output |
|---|---:|
| `[-1, -2, -3]` | `-1` |
| `[0, 0, 0]` | `0` |
| `[1, -1, 1, -1, 1]` | `1` |
| `[-2, -1]` | `-1` |

### Constraints

- `1 <= nums.size() <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Modify the function to return both the maximum sum and the start/end indices of a subarray that achieves it.

---

## Problem 6 — Move Zeroes

**Difficulty:** Easy

### Problem statement

Write a function `moveZeroes` that moves all zeroes to the end of the array while maintaining the relative order of all non-zero elements.

Perform the operation **in place**. Do not return a new array; modify `nums` directly.

### Function signature

```cpp
void moveZeroes(vector<int>& nums);
```

### Examples

**Example 1**

```text
Input:  nums = [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

**Example 2**

```text
Input:  nums = [0]
Output: [0]
```

**Example 3**

```text
Input:  nums = [1, 2, 3]
Output: [1, 2, 3]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[]` | `[]` |
| `[0, 0, 0]` | `[0, 0, 0]` |
| `[1, 0, 2, 0, 3, 0]` | `[1, 2, 3, 0, 0, 0]` |
| `[-1, 0, -2, 0, 4]` | `[-1, -2, 4, 0, 0]` |

### Constraints

- `0 <= nums.size() <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Can you minimize the number of writes when the array contains very few zeroes?

---

## Problem 7 — 3Sum

**Difficulty:** Medium

### Problem statement

Write a function `threeSum` that returns all unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i`, `j`, and `k` are distinct indices.
- `nums[i] + nums[j] + nums[k] == 0`.
- The result must not contain duplicate triplets.

The order of the triplets and the order of values within a triplet do not matter. You may sort the input array.

### Function signature

```cpp
vector<vector<int>> threeSum(vector<int>& nums);
```

### Examples

**Example 1**

```text
Input:  nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

**Example 2**

```text
Input:  nums = [0, 1, 1]
Output: []
```

**Example 3**

```text
Input:  nums = [0, 0, 0]
Output: [[0, 0, 0]]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[]` | `[]` |
| `[1, 2, -2, -1]` | `[]` |
| `[-2, 0, 1, 1, 2]` | `[[-2, 0, 2], [-2, 1, 1]]` |
| `[-1, -1, -1, 2, 2]` | `[[-1, -1, 2]]` |

### Constraints

- `3 <= nums.size() <= 3000`
- `-10^5 <= nums[i] <= 10^5`

**Required complexity:** Aim for `O(n^2)` time.

**Interview follow-up:** Explain how sorting and skipping repeated values prevents duplicate triplets. Why is a typical hash-set approach not necessarily simpler?

---

## Problem 8 — Longest Consecutive Sequence

**Difficulty:** Medium

### Problem statement

Write a function `longestConsecutive` that returns the length of the longest sequence of consecutive integers in an unsorted array.

The consecutive values do not need to appear next to each other in the input array.

Your solution must run in `O(n)` average time.

### Function signature

```cpp
int longestConsecutive(vector<int>& nums);
```

### Examples

**Example 1**

```text
Input:  nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest sequence is [1, 2, 3, 4].
```

**Example 2**

```text
Input:  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
```

**Example 3**

```text
Input:  nums = [1, 0, 1, 2]
Output: 3
```

### Additional test cases

| Input | Expected output |
|---|---:|
| `[]` | `0` |
| `[5]` | `1` |
| `[9, 8, 7, 6, 5]` | `5` |
| `[1, 2, 2, 3, 4, 4, 5]` | `5` |
| `[-2, -1, 0, 1]` | `4` |

### Constraints

- `0 <= nums.size() <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

**Required complexity:** `O(n)` average time and `O(n)` auxiliary space.

**Interview follow-up:** Why should you start counting a sequence only when its current value has no predecessor (`value - 1`) in the set?

---

## Problem 9 — Subarray Sum Equals K

**Difficulty:** Medium

### Problem statement

Write a function `subarraySum` that returns the number of contiguous subarrays whose elements sum to `k`.

A subarray must contain at least one element. The array may contain positive numbers, negative numbers, and zeroes.

### Function signature

```cpp
int subarraySum(vector<int>& nums, int k);
```

### Examples

**Example 1**

```text
Input:  nums = [1, 1, 1], k = 2
Output: 2
Explanation: The two subarrays are [1, 1] at indices [0, 1] and [1, 2].
```

**Example 2**

```text
Input:  nums = [1, 2, 3], k = 3
Output: 2
Explanation: The subarrays are [1, 2] and [3].
```

**Example 3**

```text
Input:  nums = [1, -1, 0], k = 0
Output: 3
```

### Additional test cases

| Input | Expected output |
|---|---:|
| `nums = [], k = 0` | `0` |
| `nums = [1], k = 0` | `0` |
| `nums = [0, 0, 0], k = 0` | `6` |
| `nums = [-1, -1, 1], k = 0` | `1` |
| `nums = [3, 4, 7, 2, -3, 1, 4, 2], k = 7` | `4` |

### Constraints

- `1 <= nums.size() <= 2 * 10^4` for the standard interview version; an empty array may be included in the additional tests.
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

**Required complexity:** Aim for `O(n)` average time and `O(n)` auxiliary space.

**Interview follow-up:** Explain why a sliding-window solution that assumes all numbers are non-negative does not correctly solve the general version with negative values.

---

## Problem 10 — Trapping Rain Water

**Difficulty:** Hard

### Problem statement

Write a function `trap` that takes an array `height`, where each element represents the height of a vertical bar of width `1`.

Return the total amount of water that can be trapped between the bars after raining.

### Function signature

```cpp
int trap(vector<int>& height);
```

### Examples

**Example 1**

```text
Input:  height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
```

**Example 2**

```text
Input:  height = [4, 2, 0, 3, 2, 5]
Output: 9
```

**Example 3**

```text
Input:  height = [1, 0, 1]
Output: 1
```

### Additional test cases

| Input | Expected output |
|---|---:|
| `[]` | `0` |
| `[0, 0, 0]` | `0` |
| `[1, 2, 3, 4]` | `0` |
| `[4, 3, 2, 1]` | `0` |
| `[3, 0, 2, 0, 4]` | `7` |

### Constraints

- `0 <= height.size() <= 2 * 10^5`
- `0 <= height[i] <= 10^5`

**Required complexity:** `O(n)` time. Aim for `O(1)` auxiliary space with the two-pointer approach.

**Interview follow-up:** First solve it using arrays of left and right maximum heights. Then derive the two-pointer solution that avoids those extra arrays.

---

## Submission requirements for all 10 assignments

Each student should submit:

1. The required function implementation in C++.
2. A short explanation of the algorithm and why it works.
3. Time and auxiliary-space complexity.
4. All provided test cases, plus at least two additional edge cases.
5. A brief explanation of edge cases, including empty arrays where permitted, duplicate values, negative values, and integer-overflow risks where relevant.

## Suggested evaluation rubric

| Criterion | Marks |
|---|---:|
| Correct algorithm and output | 40 |
| Edge cases and correctness | 20 |
| Time and space complexity | 15 |
| Code quality and readability | 10 |
| Explanation and interview reasoning | 15 |
| **Total** | **100** |

## Recommended order

Complete Problems 1–3 first, then Problems 4–6, followed by Problems 7–9, and finally Problem 10. The later problems combine multiple techniques and require more careful reasoning about complexity and edge cases.
