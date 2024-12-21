/*Code: Union-Find with Path Compression
Union-Find (Disjoint Set Union) is used for connectivity problems.*/

#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

int main() {
    UnionFind uf(5);

    uf.unite(0, 1);
    uf.unite(1, 2);

    cout << "Are 0 and 2 connected? " << (uf.find(0) == uf.find(2)) << endl;
    cout << "Are 3 and 4 connected? " << (uf.find(3) == uf.find(4)) << endl;

    return 0;
}
//Problems like Accounts Merge.
//Cycle detection in graphs.