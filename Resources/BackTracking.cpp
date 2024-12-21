/*Code: Permutations
Backtracking is used for generating combinations, permutations, or solving constraint satisfaction problems.*/

#include <vector>
#include <iostream>
using namespace std;

// Function to generate all permutations
void permuteHelper(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        permuteHelper(nums, result, start + 1);
        swap(nums[start], nums[i]); // Backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteHelper(nums, result, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
//Problems like Permutations.
//Sudoku solving or pathfinding with constraints.