# C++ Linked List Assignments — MAANG Interview Level

This assignment set contains **10 linked-list problems** designed for engineering students preparing for MAANG-level coding interviews. The format follows the style of NeetCode and LeetCode: a clear problem statement, function signature, examples, expected output, constraints, and test cases.

The problems progress from fundamental pointer manipulation to advanced interview patterns. Students should implement the required function rather than write an entirely new program for every problem.

## Assignment overview

| # | Problem | Difficulty | Main concept |
|---:|---|---|---|
| 1 | Reverse a Linked List | Easy | Iterative pointer manipulation |
| 2 | Detect a Cycle in a Linked List | Medium | Fast and slow pointers |
| 3 | Find the Middle of a Linked List | Easy | Two-pointer technique |
| 4 | Remove the Nth Node from the End | Medium | Two pointers and dummy node |
| 5 | Merge Two Sorted Linked Lists | Easy | In-place list merging |
| 6 | Remove Duplicates from a Sorted Linked List | Easy | Safe node deletion |
| 7 | Reorder a Linked List | Medium | Middle + reverse + merge |
| 8 | Check Whether a Linked List Is a Palindrome | Medium | Reverse second half |
| 9 | Find the Intersection of Two Linked Lists | Medium | Pointer switching and shared nodes |
| 10 | Reverse Nodes in K-Group | Hard | Advanced pointer manipulation |

## Common C++ definition

Use the following node definition for all 10 assignments unless a problem explicitly states otherwise.

```cpp
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
```

**Input convention:** Lists are represented as arrays for readability. For example, `[1, 2, 3]` means `1 -> 2 -> 3 -> NULL`. The driver code converts the array into a linked list before calling your function.

---

## Problem 1 — Reverse a Linked List

**Difficulty:** Easy

### Problem statement

Write a function `reverseList` that takes the head of a singly linked list and reverses the list in place. Return the new head of the reversed list.

You must not create new list nodes.

### Function signature

```cpp
ListNode* reverseList(ListNode* head);
```

### Examples

**Example 1**

```text
Input:  head = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
```

**Example 2**

```text
Input:  head = [1, 2]
Output: [2, 1]
```

**Example 3**

```text
Input:  head = []
Output: []
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[7]` | `[7]` |
| `[1, 1, 2]` | `[2, 1, 1]` |
| `[-3, 0, 8]` | `[8, 0, -3]` |

### Constraints

- `0 <= n <= 10^5`
- `-10^4 <= Node.val <= 10^4`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Can you solve it recursively? What is the recursion-space complexity?

---

## Problem 2 — Detect a Cycle in a Linked List

**Difficulty:** Medium

### Problem statement

Write a function `hasCycle` that determines whether a linked list contains a cycle.

A cycle exists if following `next` pointers eventually leads back to a previously visited node. The input may contain a cycle, so do not traverse the list indefinitely.

The input parameter `pos` is used only by the driver to construct a cycle. It represents the zero-based index of the node that the last node points to. If `pos = -1`, the list has no cycle.

### Function signature

```cpp
bool hasCycle(ListNode* head);
```

### Examples

**Example 1**

```text
Input:  head = [3, 2, 0, -4], pos = 1
Output: true
Explanation: The last node points to the node at index 1.
```

**Example 2**

```text
Input:  head = [1, 2], pos = 0
Output: true
```

**Example 3**

```text
Input:  head = [1], pos = -1
Output: false
```

### Additional test cases

| Input | Expected output |
|---|---|
| `head = [], pos = -1` | `false` |
| `head = [5], pos = 0` | `true` |
| `head = [1, 2, 3, 4], pos = -1` | `false` |

### Constraints

- `0 <= n <= 10^5`
- The list may contain a cycle.
- Do not modify the list.

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** If a cycle exists, write another function to return the node where the cycle begins.

---

## Problem 3 — Find the Middle of a Linked List

**Difficulty:** Easy

### Problem statement

Write a function `middleNode` that returns the middle node of a singly linked list.

If the list has an even number of nodes, return the **second middle node**.

### Function signature

```cpp
ListNode* middleNode(ListNode* head);
```

### Examples

**Example 1**

```text
Input:  head = [1, 2, 3, 4, 5]
Output: [3, 4, 5]
Explanation: The middle node contains 3.
```

**Example 2**

```text
Input:  head = [1, 2, 3, 4, 5, 6]
Output: [4, 5, 6]
Explanation: The second middle node contains 4.
```

**Example 3**

```text
Input:  head = [9]
Output: [9]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[1, 2]` | `[2]` |
| `[1, 2, 3, 4]` | `[3, 4]` |
| `[]` | `[]` |

### Constraints

- `0 <= n <= 10^5`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Explain why a slow pointer moving one step and a fast pointer moving two steps finds the middle in one traversal.

---

## Problem 4 — Remove the Nth Node from the End

**Difficulty:** Medium

### Problem statement

Write a function `removeNthFromEnd` that removes the `n`-th node from the end of a singly linked list and returns the updated head.

You must handle removing the first node and the last node.

Assume `n` is valid and does not exceed the list length.

### Function signature

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n);
```

### Examples

**Example 1**

```text
Input:  head = [1, 2, 3, 4, 5], n = 2
Output: [1, 2, 3, 5]
Explanation: The node with value 4 is removed.
```

**Example 2**

```text
Input:  head = [1], n = 1
Output: []
```

**Example 3**

```text
Input:  head = [1, 2], n = 2
Output: [2]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `head = [1, 2, 3], n = 1` | `[1, 2]` |
| `head = [1, 2, 3], n = 3` | `[2, 3]` |
| `head = [1, 2, 3, 4], n = 4` | `[2, 3, 4]` |

### Constraints

- `1 <= n <= length of list <= 10^5`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Why does a dummy node simplify deletion when the node to remove is the head?

---

## Problem 5 — Merge Two Sorted Linked Lists

**Difficulty:** Easy

### Problem statement

Write a function `mergeTwoLists` that merges two sorted singly linked lists into one sorted list.

Return the head of the merged list. Reuse the existing nodes instead of creating replacement nodes.

If both lists contain the same value, either order is acceptable.

### Function signature

```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
```

### Examples

**Example 1**

```text
Input:
list1 = [1, 2, 4]
list2 = [1, 3, 4]

Output: [1, 1, 2, 3, 4, 4]
```

**Example 2**

```text
Input:
list1 = []
list2 = [0]

Output: [0]
```

**Example 3**

```text
Input:
list1 = []
list2 = []

Output: []
```

### Additional test cases

| `list1` | `list2` | Expected output |
|---|---|---|
| `[1]` | `[2]` | `[1, 2]` |
| `[1, 5, 9]` | `[2, 3, 10]` | `[1, 2, 3, 5, 9, 10]` |
| `[-5, 0]` | `[-3, 1]` | `[-5, -3, 0, 1]` |

### Constraints

- `0 <= m, n <= 10^4`
- Both lists are sorted in non-decreasing order.

**Required complexity:** `O(m+n)` time and `O(1)` auxiliary space for an iterative solution.

**Interview follow-up:** Implement a recursive solution and compare its stack-space complexity.

---

f## Problem 6 — Remove Duplicates from a Sorted Linked List

**Difficulty:** Easy

### Problem statement

Write a function `deleteDuplicates` that removes duplicate values from a sorted linked list.

Keep exactly one occurrence of each distinct value. Preserve the original order of the remaining nodes.

### Function signature

```cpp
ListNode* deleteDuplicates(ListNode* head);
```

### Examples

**Example 1**

```text
Input:  head = [1, 1, 2]
Output: [1, 2]
```

**Example 2**

```text
Input:  head = [1, 1, 2, 3, 3]
Output: [1, 2, 3]
```

**Example 3**

```text
Input:  head = []
Output: []
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[1]` | `[1]` |
| `[2, 2, 2, 2]` | `[2]` |
| `[-3, -3, 0, 0, 5]` | `[-3, 0, 5]` |

### Constraints

- `0 <= n <= 10^5`
- The list is sorted in non-decreasing order.

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** How would the problem change if *every value that appears more than once* had to be removed entirely? For example, `[1, 1, 2, 3, 3]` should become `[2]`.

---

## Problem 7 — Reorder a Linked List

**Difficulty:** Medium

### Problem statement

Write a function `reorderList` that reorders a linked list in place according to this pattern:

`L0 -> L1 -> ... -> L(n-1)`

becomes

`L0 -> L(n-1) -> L1 -> L(n-2) -> ...`

Do not change node values or allocate new list nodes.

Since the list is reordered in place, the function returns `void`.

### Function signature

```cpp
void reorderList(ListNode* head);
```

### Examples

**Example 1**

```text
Input:  head = [1, 2, 3, 4]
Output: [1, 4, 2, 3]
```

**Example 2**

```text
Input:  head = [1, 2, 3, 4, 5]
Output: [1, 5, 2, 4, 3]
```

**Example 3**

```text
Input:  head = [1]
Output: [1]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[1, 2]` | `[1, 2]` |
| `[1, 2, 3]` | `[1, 3, 2]` |
| `[1, 2, 3, 4, 5, 6]` | `[1, 6, 2, 5, 3, 4]` |

### Constraints

- `1 <= n <= 5 * 10^4`
- Node values may be duplicated.
- You must reorder the existing nodes in place.

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Solve the problem by combining three operations: finding the middle, reversing the second half, and alternating nodes from each half.

---

## Problem 8 — Check Whether a Linked List Is a Palindrome

**Difficulty:** Medium

### Problem statement

Write a function `isPalindrome` that returns `true` if the linked list reads the same forwards and backwards, and `false` otherwise.

For the optimal solution, use `O(1)` auxiliary space rather than copying all node values into an array.

### Function signature

```cpp
bool isPalindrome(ListNode* head);
```

### Examples

**Example 1**

```text
Input:  head = [1, 2, 2, 1]
Output: true
```

**Example 2**

```text
Input:  head = [1, 2]
Output: false
```

**Example 3**

```text
Input:  head = [1, 2, 3, 2, 1]
Output: true
```

### Additional test cases

| Input | Expected output |
|---|---|
| `[]` | `true` |
| `[7]` | `true` |
| `[1, 2, 3, 1]` | `false` |
| `[1, 1, 1, 1]` | `true` |
| `[-1, 2, -1]` | `true` |

### Constraints

- `0 <= n <= 10^5`
- `-10^5 <= Node.val <= 10^5`

**Required complexity:** `O(n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Can you restore the original list structure after checking whether it is a palindrome?

---

## Problem 9 — Find the Intersection of Two Linked Lists

**Difficulty:** Medium

### Problem statement

Write a function `getIntersectionNode` that returns the actual intersection node of two singly linked lists, or `nullptr` if they do not intersect.

Two lists intersect only when they share the **same node in memory**, not merely when their node values are equal.

The lists may have different lengths.

### Function signature

```cpp
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
```

### Examples

**Example 1**

```text
Input:
listA = [4, 1, 8, 4, 5]
listB = [5, 6, 1, 8, 4, 5]

Shared node begins at value 8.

Output: intersection node with value 8
```

**Example 2**

```text
Input:
listA = [1, 2, 3]
listB = [4, 5, 6]

Output: nullptr
```

**Example 3**

```text
Input:
listA = [2, 6, 4]
listB = [1, 5]

Output: nullptr
```

### Additional test cases

| Scenario | Expected output |
|---|---|
| Both heads point to the same node | That shared node |
| Lists intersect at the final node | The shared final node |
| Equal values but separate node allocations | `nullptr` |
| One list is empty | `nullptr` |

### Constraints

- `0 <= m, n <= 3 * 10^4`
- Each list has no cycle.
- The lists must not be modified.

**Required complexity:** `O(m+n)` time and `O(1)` auxiliary space.

**Interview follow-up:** Explain why switching each pointer to the other list's head after reaching `nullptr` allows the pointers to meet at the intersection.

**Important testing note:** The driver must construct the shared tail using the same allocated node objects for both lists. Two separate lists containing the same values do not constitute an intersection.

---

## Problem 10 — Reverse Nodes in K-Group

**Difficulty:** Hard

### Problem statement

Write a function `reverseKGroup` that reverses the nodes of a linked list in groups of size `k`.

If the remaining number of nodes is less than `k`, leave those nodes unchanged.

Reverse the links between existing nodes. Do not change node values or allocate replacement list nodes.

### Function signature

```cpp
ListNode* reverseKGroup(ListNode* head, int k);
```

### Examples

**Example 1**

```text
Input:  head = [1, 2, 3, 4, 5], k = 2
Output: [2, 1, 4, 3, 5]
```

**Example 2**

```text
Input:  head = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
```

**Example 3**

```text
Input:  head = [1, 2, 3, 4, 5, 6], k = 3
Output: [3, 2, 1, 6, 5, 4]
```

**Example 4**

```text
Input:  head = [1, 2, 3], k = 1
Output: [1, 2, 3]
```

### Additional test cases

| Input | Expected output |
|---|---|
| `head = [], k = 2` | `[]` |
| `head = [1], k = 2` | `[1]` |
| `head = [1, 2, 3, 4], k = 4` | `[4, 3, 2, 1]` |
| `head = [1, 2, 3, 4, 5], k = 5` | `[5, 4, 3, 2, 1]` |
| `head = [1, 2, 3, 4, 5, 6, 7], k = 3` | `[3, 2, 1, 6, 5, 4, 7]` |

### Constraints

- `0 <= n <= 5000`
- `1 <= k <= n` when the list is non-empty.
- Node values are integers.
- Nodes must be rearranged in place.

**Required complexity:** `O(n)` time. Aim for `O(1)` auxiliary space with an iterative solution.

**Interview follow-up:** How will you reconnect each reversed group to both the preceding group and the unreversed suffix without losing any nodes?

---

## Submission requirements for all 10 assignments

Each student should submit:

1. The required function implementation in C++.
2. A short explanation of the algorithm and pointer manipulation.
3. Time and auxiliary-space complexity.
4. All provided test cases, plus at least two additional edge cases.
5. A short explanation of why the solution works and what could cause a null-pointer dereference or lost node.

## Suggested evaluation rubric

| Criterion | Marks |
|---|---:|
| Correct algorithm and output | 40 |
| Pointer safety and edge cases | 20 |
| Time and space complexity | 15 |
| Code quality and readability | 10 |
| Explanation and interview reasoning | 15 |
| **Total** | **100** |

## Recommended order

Complete Problems 1–6 first, then Problems 7–9, and finally Problem 10. The later problems deliberately combine techniques from the earlier assignments.

This set is suitable for a C++ engineering assignment pack: the problem statements specify the required functions, examples show expected outputs, and the additional test cases can be used to evaluate correctness without prescribing the implementation.
