#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <limits>
#include <numeric>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <climits>
#define endl "\n"
using namespace std;
#define pii pair<int, int>
#define X first
#define Y second

int res1, res2;
int N;
vector<int> v[101];
bool visit[101];
int step[101];
queue<int> q;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> res1 >> res2;
    int m;
    cin >> m;

    for (int i = 0 ; i < m; i ++){
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    q.push(res1);
    visit[res1] = 1;
    while(q.size()){
        int q_value = q.front();
        if(q_value == res2){
            break;
        }
        q.pop();
        for(int i : v[q_value]){
            if(visit[i])
                continue;
            q.push(i);
            step[i] = step[q_value] + 1;
            visit[i] = true;
        }
    }
    if(!step[res2]){
        cout << -1 << endl;
    } else{
        cout << step[res2] << endl;
    }
    return 0;
}

