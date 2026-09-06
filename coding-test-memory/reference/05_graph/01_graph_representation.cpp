#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> graph(n + 1);

    auto addEdge = [&](int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    };

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);

    for (int node = 1; node <= n; node++) {
        cout << node << ": ";
        for (int next : graph[node]) {
            cout << next << ' ';
        }
        cout << '\n';
    }
}
