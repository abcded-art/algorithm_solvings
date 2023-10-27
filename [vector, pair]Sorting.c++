#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pair<int, int>> v;
    
    for(int i = 0; i < 10; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool{
        if(a.first != b.first){
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    
    for(auto i : v){
        cout << i.first << ' ' << i.second << endl;
    }
    
    return 0;
}
