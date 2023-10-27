#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <limits>
#define endl "\n"
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> q;

void dfs(int node){
    visited[node] = true;
    cout << node << " ";
    for(int i = 0; i < graph[node].size(); i++){
        if(!visited[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}

void bfs(int node){
    q.push(node);
    visited[node] = true;
   int it = 0;
    while(!q.empty()){
       cout << "Iterator Queue" << ++it << ": ";
       for(int i = 0; i < q.size(); i++){
           cout << q.front() << " ";
           q.push(q.front()); q.pop();
       }
       cout << endl;
        int here = q.front();
        q.pop();
        cout << here << " ";
        for(auto there : graph[here]){
            if(!visited[there]){
                q.push(there);
                visited[there] = true;
            }
        }
    }
}

void check(){
    for(int i = 1; i < graph.size(); i++){
        cout << "node[" << i << "]: ";
        for(auto linked : graph[i]){
            cout << linked << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, v;
    cin >> n >> m >> v;
    
    graph.resize(n + 1);
    
    for(int i = 0; i < m; i++){
        int U, V;
        cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
    
    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    visited.assign(n + 1, false);
    dfs(v);
    cout << endl;
    
    visited.assign(n + 1, false);
    bfs(v);
    cout << endl;
}

/*

4 5 1
1 2
1 3
1 4
2 4
3 4

5 5 3
5 4
5 2
1 2
3 4
3 1

1000 1 1000
999 1000

*/