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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    int arr[N];
    int i_arr[N];

    int p_input;

    for (int i = 0; i < N; i++){
        int input;
        cin >> input;
        
        i_arr[i] = input;
    }

    if(i_arr[0]>i_arr[1])
        arr[0] = 1;
    else
        arr[0] = 0;

    for(int i = 1; i < N - 1; i++){
        if(i_arr[i + 1] - i_arr[i] < 0){
            arr[i] = arr[i - 1] + 1;
        }
        else
            arr[i]=arr[i-1];
    }  

    if(N != 1)
        arr[N - 1] = arr[N - 2];

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        
        if(y == x){
            cout << 0 << endl;
        }
        else{
            if(x == 1){
                cout << (arr[y - 2]);
            } else {
                cout << (arr[y - 2] - arr[x - 2]);
            }

            cout << endl;
        }
    }
}

