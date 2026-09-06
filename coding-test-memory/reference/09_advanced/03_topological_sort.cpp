#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    auto addEdge = [&](int from, int to) {
        graph[from].push_back(to);
        indegree[to]++;
    };

    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(3, 5);

    queue<int> q;

    for (int node = 1; node <= n; node++) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);

        for (int next : graph[cur]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if ((int)order.size() != n) {
        cout << "cycle exists\n";
        return 0;
    }

    for (int x : order) cout << x << ' ';
    cout << '\n';
}
