#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {3, 5, 1, 4, 2};
    sort(v.begin(), v.end());


    // 오름차순 정렬
    for(int num : v){
        cout << num << " ";
    }

    cout << endl;

    // 내림차순 정렬
    reverse(v.begin(), v.end());
    for(int num : v){
        cout << num << " ";
    }

    return 0;  
}