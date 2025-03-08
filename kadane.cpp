
#include <iostream>
#include <vector>
#include <algorithm> // for std::max
#include <limits>    // for std::numeric_limits

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubArray(const std::vector<int>& nums) {
    // Check for empty vector
    if (nums.empty()) {
        std::cerr << "Error: The input array is empty." << std::endl;
        return 0; // or throw an exception
    }

    int max_current = nums[0]; // Maximum sum of the subarray found so far
    int max_global = nums[0];  // Overall maximum sum

    for (size_t i = 1; i < nums.size(); ++i) {
        // Update the maximum sum ending at the current position
        max_current = std::max(nums[i], max_current + nums[i]);

        // Update the global maximum if the current maximum is greater
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example array
    int result = maxSubArray(nums);
    std::cout << "Maximum subarray sum is: " << result << std::endl;
    return 0;
}

