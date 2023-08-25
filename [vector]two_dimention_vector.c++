#include <iostream>
#include <vector>
using namespace std;

int main(){
    int rows = 3, cols = 5;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols ;j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols ;j++){
            cout << matrix[i][j] << " ";
        } 
        cout << endl;
    }
}