#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << ' ';

    for (int next : graph[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    graph.resize(6);
    visited.assign(6, false);

    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {1, 5};
    graph[4] = {2};
    graph[5] = {3};

    dfs(1);
    cout << '\n';
}
