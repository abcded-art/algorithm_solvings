#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v;
    string s;
    
    std::getline(cin, s);
    stringstream ss(s);
    string t;
    while(getline(ss, t, ',')){
        t.erase(remove_if(t.begin(), t.end(), ::isspace), t.end());
        v.push_back(stoi(t));
    }
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}
