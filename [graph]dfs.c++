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

void dfs(int here, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& visit_order);

int order = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> visit_order(n + 1, 0);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i < n + 1; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    /*
    for(int i = 1; i < n + 1; i++){
        cout << "Graph[" << i << "]: ";
        if(!graph[i].empty()){
            for(int j = 0; j < graph[i].size(); j++){
                cout << graph[i][j] << " ";
            }
        }
        else{
            cout << "NULL";
        }
        cout << endl;
    }*/
    
    visited[r] = true;
    visit_order[r] = ++order;
    
    dfs(r, graph, visited, visit_order);
    for(int i = 1; i <= n; i++){
        cout << visit_order[i] << endl;
    }
    /*
    for(int i = 1; i <= n; i++){
        cout << "visit_order[" << i << "]: " << visit_order[i] << " ";
    }*/
}

void dfs(int here, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& visit_order){
    visited[here] = true;
    for(int i = 0; i < graph[here].size(); i++){
        if(!visited[graph[here][i]]){
            visit_order[graph[here][i]] = ++order;
            dfs(graph[here][i], graph, visited, visit_order);
        }
    }
}

