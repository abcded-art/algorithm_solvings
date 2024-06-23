#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> visited_order(n + 1, 0);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cout << "graph["<< u << "]: ";
        for(int i = 0; i < graph[u].size(); i++) {
            cout << graph[u][i] << " ";
        }
        cout << endl;
        cout << "graph["<<v<<"]: ";
        for(int i = 0; i < graph[v].size(); i++) {
            cout << graph[v][i] << " ";
        }
        cout << endl;

    }
    
    cout << "----- RESULT ------" << endl;
    
    for(int i = 0; i < n; i++){
        cout << "graph[" << i + 1 << "]: ";
        for(int j = 0; j < graph[i + 1].size(); j++){
            cout << graph[i + 1][j] << " ";
        }
        cout << endl;
    }
    
}
