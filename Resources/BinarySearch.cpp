/*Code: Find Element in Rotated Array
Binary search is used to find elements in sorted or rotated arrays.*/

#include <vector>
#include <iostream>
using namespace std;

// Function to search in a rotated sorted array
int searchRotatedArray(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1; // Not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Index of target: " << searchRotatedArray(nums, target) << endl;

    return 0;
}


//Problems like Search in Rotated Sorted Array.
//Finding elements in sorted arrays.