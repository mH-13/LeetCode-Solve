/*Code: Longest Substring Without Repeating Characters
The sliding window technique is used for problems with continuous subarrays or substrings.*/

#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(const string& s) {
    unordered_set<char> window;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.size(); ++right) {
        while (window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        window.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}


//Problems like Longest Substring Without Repeating Characters.
//Continuous subarray problems.