#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, F;
    cin >> N >> F;

    N = (N / 100) * 100;

    int ans = 0;
    for(int i = 0; i <= 100; i++) {
        if(N % F == 0) {
            ans = i;
            break;
        }
        N++;
    }
    if(ans < 10) {
        cout << '0' << ans << endl;
    } else {
        cout << ans << endl;
    }
}