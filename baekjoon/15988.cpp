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

int v[31][31];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N = 30;

    for(int i = 0; i <= N; i++) {
        v[0][i] = 1;
    }

    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= j; i++){
            v[i][j] = v[i - 1][j - 1] + v[i][j - 1];
        }
    }

    int a, b;
    cin >> a >> b;

    cout << v[b-1][a-1] << endl;
    return 0;
}

