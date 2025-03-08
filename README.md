## Documentation

### Kadane

This C++ code implements a solution to the "Maximum Subarray Problem" using Kadane's Algorithm, which efficiently finds the maximum sum of a contiguous subarray within a one-dimensional array of numbers. Here's a detailed breakdown of the code:

### Header Files
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::max
#include <limits>    // for std::numeric_limits
```
- `#include <iostream>`: This is included to allow for input and output operations, such as `std::cout` and `std::cerr`.
- `#include <vector>`: This is included to use the `std::vector` container for dynamic arrays.
- `#include <algorithm>`: This is included to use the `std::max` function, which returns the greater of two values.
- `#include <limits>`: Although it's included, it's not used in the code provided. It typically is used to define limits for types (like maximum and minimum values).

### Function Definition
```cpp
int maxSubArray(const std::vector<int>& nums) {
```
- This line defines a function `maxSubArray` that takes a constant reference to a vector of integers `nums` and returns an integer, which is the maximum subarray sum.

### Error Handling
```cpp
if (nums.empty()) {
    std::cerr << "Error: The input array is empty." << std::endl;
    return 0; // or throw an exception
}
```
- Before processing, the function checks if the input array is empty. If it is, it outputs an error message to the standard error stream and returns 0. This is essential to avoid accessing elements in an empty vector.

### Variable Initialization
```cpp
int max_current = nums[0]; // Maximum sum of the subarray found so far
int max_global = nums[0];  // Overall maximum sum
```
- `max_current` keeps track of the maximum sum of the subarray that ends at the current index while iterating through the array.
- `max_global` maintains the overall maximum sum encountered so far.

### Iteration through the Array
```cpp
for (size_t i = 1; i < nums.size(); ++i) {
```
- A loop starts from the second element (index 1) of the array and goes to the end. The reason for starting at index 1 is that index 0 is already used for initialization.

### Update Maximum Sums
```cpp
max_current = std::max(nums[i], max_current + nums[i]);
```
- This line updates `max_current` to be the maximum of the current element `nums[i]` and the sum of `max_current` plus `nums[i]`. This decision checks:
  - If starting a new subarray at `nums[i]` is better than continuing the existing one.
  
```cpp
if (max_current > max_global) {
    max_global = max_current;
}
```
- If the `max_current` (the maximum subarray sum that ends at the current index) is greater than `max_global`, it updates `max_global` with the value of `max_current`.

### Return Statement
```cpp
return max_global;
```
- After the loop finishes, the function returns `max_global`, which holds the maximum sum of any contiguous subarray found in the input array.

### Main Function
```cpp
int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example array
    int result = maxSubArray(nums);
    std::cout << "Maximum subarray sum is: " << result << std::endl;
    return 0;
}
```
- The `main` function initializes a vector `nums` with a sample array of integers, calls the `maxSubArray` function with this vector, and stores the result.
- Finally, it prints the result to the console, indicating the maximum subarray sum.

### Summary
The code effectively implements Kadane's Algorithm to determine the maximum sum of a contiguous subarray in linear time (O(n)), making it efficient for large datasets. It handles edge cases, such as empty input, and outputs the result clearly.


![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
