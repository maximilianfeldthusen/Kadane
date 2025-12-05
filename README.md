

# Kadane’s Algorithm Explained in C++

---

## Header Files
```cpp
#include <iostream>   // for input/output (std::cout, std::endl)
#include <vector>     // for std::vector
#include <algorithm>  // for std::max
```

These libraries provide the tools you need:
- Printing to console (`std::cout`, `std::endl`)
- Using dynamic arrays (`std::vector`)
- Comparing values (`std::max`)

---

## Function: `maxSubArray`
```cpp
int maxSubArray(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Input array is empty.");
    }
```

- **Purpose:** Finds the maximum sum of a contiguous subarray using Kadane’s Algorithm.  
- **Empty check:** If the input vector is empty, it throws an exception.

### Initialization
```cpp
int max_current = nums[0];
int max_global = nums[0];
```
- `max_current`: The maximum sum of a subarray ending at the current index.  
- `max_global`: The overall maximum sum found so far.  
- Both start with the first element.

### Loop Through Array
```cpp
for (size_t i = 1; i < nums.size(); ++i) {
    max_current = std::max(nums[i], max_current + nums[i]);
    max_global = std::max(max_global, max_current);
}
```

For each element:
- Decide whether to start a new subarray at `nums[i]` or extend the previous subarray (`max_current + nums[i]`).  
- Update `max_global` if the new `max_current` is larger.  

This is the essence of Kadane’s Algorithm: at each step, you choose the better option (start fresh or continue).

### Return Result
```cpp
return max_global;
```
After scanning the entire array, `max_global` holds the maximum subarray sum.

---

## Main Function
```cpp
int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Maximum subarray sum is: " << maxSubArray(nums) << std::endl;
    return 0;
}
```

- Defines an example array.  
- Calls `maxSubArray(nums)` to compute the maximum sum.  
- Prints the result.

---

## Example Walkthrough
Array: `{ -2, 1, -3, 4, -1, 2, 1, -5, 4 }`

Step-by-step:
- Start: `max_current = -2`, `max_global = -2`  
- At 1: `max_current = max(1, -2+1) = 1`, `max_global = 1`  
- At -3: `max_current = max(-3, 1-3) = -2`, `max_global = 1`  
- At 4: `max_current = max(4, -2+4) = 4`, `max_global = 4`  
- At -1: `max_current = max(-1, 4-1) = 3`, `max_global = 4`  
- At 2: `max_current = max(2, 3+2) = 5`, `max_global = 5`  
- At 1: `max_current = max(1, 5+1) = 6`, `max_global = 6`  
- At -5: `max_current = max(-5, 6-5) = 1`, `max_global = 6`  
- At 4: `max_current = max(4, 1+4) = 5`, `max_global = 6`  

**Final Answer:** `6` (from subarray `[4, -1, 2, 1]`)

---

## Summary
This program uses **Kadane’s Algorithm** to efficiently find the maximum sum of a contiguous subarray in **linear time O(n)**.  
It works by dynamically deciding whether to extend the current subarray or start a new one at each step.



