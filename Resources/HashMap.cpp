/*Code: Frequency Count
HashMaps (unordered_map) are useful for counting frequencies or quick lookups.*/

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

// Function to count frequencies of elements
unordered_map<int, int> countFrequencies(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    return freq;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    unordered_map<int, int> freq = countFrequencies(nums);

    // Example: Check frequency of 3
    cout << "Frequency of 3: " << freq[3] << endl;

    return 0;
}
//Problems like Majority Element.
//Handling unique and duplicate elements