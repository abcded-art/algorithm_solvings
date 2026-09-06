#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
using namespace std;

using ll = long long;
using Edge = pair<ll, int>; // {비용, 다음 노드}

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n + 1);

    graph[1].push_back({2, 2});
    graph[1].push_back({5, 3});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 4});
    graph[3].push_back({1, 4});
    graph[4].push_back({1, 5});

    // 거리 합이 int 범위를 넘을 수 있으므로 long long을 사용한다.
    const ll INF = numeric_limits<ll>::max() / 4;
    vector<ll> dist(n + 1, INF);

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    int start = 1;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if (curDist != dist[cur]) continue;

        for (auto [cost, next] : graph[cur]) {
            ll nextDist = curDist + cost;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    for (int node = 1; node <= n; node++) {
        if (dist[node] == INF) {
            cout << node << ": unreachable\n";
        } else {
            cout << node << ": " << dist[node] << '\n';
        }
    }
}
