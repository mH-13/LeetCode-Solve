/*Tries are used to store and search strings efficiently, especially when working with prefixes.

Code: Basic Trie Implementation*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node structure
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children.count(c)) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    // Search a word in the Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children.count(c)) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }

    // Check if a prefix exists
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children.count(c)) {
                return false;
            }
            current = current->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search 'apple': " << trie.search("apple") << endl; // true
    cout << "Search 'app': " << trie.search("app") << endl;     // false
    cout << "Prefix 'app': " << trie.startsWith("app") << endl; // true
    trie.insert("app");
    cout << "Search 'app': " << trie.search("app") << endl;     // true

    return 0;
}

//Problems like Implement Trie (Prefix Tree).
//Prefix-based searches or autocomplete systems.