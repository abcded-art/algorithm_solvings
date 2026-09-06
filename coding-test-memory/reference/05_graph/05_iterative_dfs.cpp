#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (visited[cur]) continue;

        visited[cur] = true;
        cout << cur << ' ';

        // 재귀 DFS와 같은 순서를 원하면 인접 노드를 역순으로 넣는다.
        for (int i = (int)graph[cur].size() - 1; i >= 0; i--) {
            int next = graph[cur][i];
            if (!visited[next]) st.push(next);
        }
    }
    cout << '\n';
}

int main() {
    vector<vector<int>> graph(6);
    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {1, 5};
    graph[4] = {2};
    graph[5] = {3};
    dfs(graph, 1);
}
