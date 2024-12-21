//Prefix Sum Prefix sums are used to calculate cumulative sums efficiently.

#include <vector>
#include <iostream>
using namespace std;

// Function to calculate prefix sums
vector<int> calculatePrefixSum(const vector<int>& nums) {
    vector<int> prefixSum(nums.size());
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    return prefixSum;
}

// Use Case
// Calculate sum of subarray [l, r] in O(1) time.
int getRangeSum(const vector<int>& prefixSum, int l, int r) {
    if (l == 0) return prefixSum[r];
    return prefixSum[r] - prefixSum[l - 1];
}

int main() {
    vector<int> nums = {2, 4, 6, 8, 10};
    vector<int> prefixSum = calculatePrefixSum(nums);

    // Example: Get sum of subarray [1, 3]
    cout << "Sum of subarray [1, 3]: " << getRangeSum(prefixSum, 1, 3) << endl;

    return 0;
}

//Subarray sum problems like Range Sum Query.
//Problems requiring cumulative sums in multiple ranges.