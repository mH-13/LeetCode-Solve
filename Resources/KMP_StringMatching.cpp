#include <vector>
#include <iostream>
using namespace std;

// Build prefix table for KMP
vector<int> buildPrefixTable(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;

    for (int i = 1; i < m; ++i) {
        if (pattern[i] == pattern[j]) {
            lps[i] = ++j;
        } else if (j > 0) {
            j = lps[j - 1];
            --i;
        }
    }

    return lps;
}

// KMP Search
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> lps = buildPrefixTable(pattern);
    vector<int> result;
    int i = 0, j = 0;

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        }

        if (j == pattern.size()) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pattern[j]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    return result;
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    vector<int> result = kmpSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }

    return 0;
}
//Problems like Implement strStr().
//Efficient pattern searching in strings