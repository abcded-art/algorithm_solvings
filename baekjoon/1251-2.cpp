#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    string a, b, c;
    set<string> s;

    for(int i = 1; i < input.size() - 1; i++) {
        for(int j = i + 1; j < input.size(); j++){
            a = input.substr(0, i);
            b = input.substr(i, j - i);
            c = input.substr(j, input.size() - j);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            a = a + b + c;
            s.insert(a);
        }
    }

    cout << *s.begin() << endl;
    
}