#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;


bool mySort(const pair<string, int>& a, const pair<string, int>& b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    if(a.first.size() != b.first.size()){
        return a.first.size() > b.first.size();
    }
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    map<string, int> mp;
    
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        if(input.size() < m){
            continue;
        }
        mp[input]++;
    }
    
    vector<pair<string, int>> vec(mp.begin(), mp.end());
    
    sort(vec.begin(), vec.end(), mySort);
    
    for(auto it : vec){
        cout << it.first << endl;
    }
    
    return 0;
}
