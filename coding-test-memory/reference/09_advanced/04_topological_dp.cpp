#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> duration = {0, 3, 2, 4, 2, 1};

    auto addEdge = [&](int before, int after) {
        graph[before].push_back(after);
        indegree[after]++;
    };

    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(3, 5);

    queue<int> q;
    vector<int> finishTime(n + 1, 0);

    for (int node = 1; node <= n; node++) {
        if (indegree[node] == 0) {
            q.push(node);
            finishTime[node] = duration[node];
        }
    }

    int processed = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        processed++;

        for (int next : graph[cur]) {
            finishTime[next] = max(
                finishTime[next], finishTime[cur] + duration[next]
            );

            if (--indegree[next] == 0) q.push(next);
        }
    }

    if (processed != n) {
        cout << "cycle exists\n";
        return 0;
    }

    for (int node = 1; node <= n; node++) {
        cout << node << ": " << finishTime[node] << '\n';
    }
}
