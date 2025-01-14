#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1;
    cin.ignore();
    getline(cin, s2);
    cout << s1 << endl;
    cout << s2 << endl;
}
