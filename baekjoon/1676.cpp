#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int N, cnt = 0;
    cin >> N;

    cnt += N / 5;
    cnt += N / 25;
    cnt += N / 125;
    
    cout << cnt << endl;

    return 0;
}