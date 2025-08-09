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
#define pii pair<double, int>
#define X first
#define Y second

void getResult(int a, int b){
    if(b - a > 0){
        cout << 1 << endl;
    } else if(b - a < 0){
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    int a, b;
    int past;

    vector<pii> tv;

    cin >> a >> b;
    tv.push_back({a,b});

    for(int i = 1; i < N; i++){
        cin >> a >> b;
        
        tv.push_back({a,b});
    }

    int q, info;
    cin >> q;

    for(int i = 0; i < q; i++){
        double input;
        cin >> input;
        info = (input);
        int p = lower_bound(tv.begin(), tv.end(), make_pair(input, 0))-tv.begin();
        getResult(tv[p-1].Y, tv[p].Y);
    }

    return 0;

}

