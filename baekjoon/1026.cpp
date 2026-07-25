#include <iostream>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;

typedef struct Test{
    int t1;
    int t2;
} Test;

bool operator<(Test test1, Test test2){
    if(test1.t1 * test2.t1 < test1.t2 * test2.t2)
        return true;
    return false;
};

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> a;
    vector<int> b;
    
    for(auto i = 0; i < N; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end(), less<int>());

    for(auto i = 0; i < N; i++){
        int input;
        cin >> input;
        b.push_back(input);
    }
    sort(b.begin(), b.end(), greater<int>());

    int result = 0;
    for(auto i = 0; i < N; i++){
        result += a[i] * b[i];
    }

    cout << result << endl;

    return 0;
}
