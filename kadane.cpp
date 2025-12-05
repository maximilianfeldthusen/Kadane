
#include <iostream>
#include <vector>
#include <algorithm> // for std::max

// Function to implement Kadane's Algorithm
int maxSubArray(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Input array is empty.");
    }

    int max_current = nums[0];
    int max_global = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        // Update the maximum sum ending at the current position
        max_current = std::max(nums[i], max_current + nums[i]);

        // Update the global maximum if needed
        max_global = std::max(max_global, max_current);
    }
    return max_global;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example array
    std::cout << "Maximum subarray sum is: " << maxSubArray(nums) << std::endl;
    return 0;
}

