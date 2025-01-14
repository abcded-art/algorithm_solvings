#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

void PrintResult(vector<int>& v){
    for(int num : v){
        cout << num << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v;

    cout << "Working" << endl;
    
    v = {3, 5, 1, 4, 2};

    // Sorting vector
    sort(v.begin(), v.end()); // up
    sort(v.begin(), v.end(), greater<>()); // down
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool{
        return a < b; // up
    });

    // Reversing vector
    reverse(v.begin(), v.end());
    
    // Printing vector
    PrintResult(v);
    
    // Erasing index element
    v.erase(v.begin() + 3);
    
    // Printing vector
    PrintResult(v);
    
    // Erasing specific area
    v.erase(v.begin() + 1, v.begin() + 3);
    
    // Printing vector
    PrintResult(v);
    
    // Adding elements
    v.insert(v.end(), {1, 2, 3});
    
    // Printing vector
    PrintResult(v);
    
    // Removing elements which have specific value
    v.erase(remove(v.begin(), v.end(), 3), v.end());
    
    // Printing vector
    PrintResult(v);
    
    // Removing all elements
    v.clear();
    
    // Printing vector
    PrintResult(v);
    return 0;
}
