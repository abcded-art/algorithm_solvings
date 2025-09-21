#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> v;
    int input;

    cin >> input;
    v.push_back(input);
    cin >> input;
    v.push_back(input);
    cin >> input;
    v.push_back(input);
    
    sort(v.begin(), v.end(), greater<int>());

    cout << v[1] << endl;
    
    return 0;
}