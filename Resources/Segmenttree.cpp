#include <vector>
#include <iostream>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void buildTree(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            buildTree(nums, leftChild, start, mid);
            buildTree(nums, rightChild, mid + 1, end);
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        return queryRange(leftChild, start, mid, l, r) +
               queryRange(rightChild, mid + 1, end, l, r);
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updateTree(leftChild, start, mid, idx, val);
            } else {
                updateTree(rightChild, mid + 1, end, idx, val);
            }

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        buildTree(nums, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(nums);

    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl; // 15
    segTree.update(1, 10);
    cout << "Sum of range [1, 3] after update: " << segTree.query(1, 3) << endl; // 22

    return 0;
}
//Problems like Range Sum Query - Mutable.
//Efficient range queries with dynamic updates