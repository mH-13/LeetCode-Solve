/*Code: Finding Pair with Target Sum
The two-pointer technique is effective for sorted arrays.*/

#include <vector>
#include <iostream>
using namespace std;

// Function to find indices of the two numbers that sum up to the target
pair<int, int> twoSumTwoPointers(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left, right};
        else if (sum < target) left++;
        else right--;
    }

    return {-1, -1}; // No solution
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6};
    int target = 6;

    pair<int, int> result = twoSumTwoPointers(nums, target);
    cout << "Indices: " << result.first << ", " << result.second << endl;

    return 0;
}

//Problems like Two Sum II.
//Finding subarray bounds or solving sliding window problems.