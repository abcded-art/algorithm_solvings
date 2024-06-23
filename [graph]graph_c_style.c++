#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, n;
    int** mat;
    cin >> m >> n;
    mat = new int*[n];
    for(int i = 0 ;i < n; i++){
        mat[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] <<' ';
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        delete[] mat[i];
    }
    delete[] mat;
    return 0;
}
