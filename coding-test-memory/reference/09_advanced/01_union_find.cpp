#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    UnionFind(int n) : parent(n + 1), rankValue(n + 1, 0) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankValue[a] < rankValue[b]) swap(a, b);

        parent[b] = a;
        if (rankValue[a] == rankValue[b]) {
            rankValue[a]++;
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    UnionFind uf(5);
    uf.unite(1, 2);
    uf.unite(2, 3);

    cout << boolalpha << uf.connected(1, 3) << '\n';
    cout << boolalpha << uf.connected(1, 5) << '\n';
}
