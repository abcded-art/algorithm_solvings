#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next : graph[cur]) {
            if (visited[next]) continue;

            visited[next] = true; // queue에 넣을 때 방문 처리
            q.push(next);
        }
    }
}

int main() {
    vector<vector<int>> graph(6);
    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {1, 5};
    graph[4] = {2};
    graph[5] = {3};

    bfs(graph, 1);
    cout << '\n';
}
