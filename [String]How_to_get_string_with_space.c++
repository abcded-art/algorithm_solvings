#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input = "";
    stack<int> s1, s2;
    while(true){
        getline(cin, input);
        cout << input << endl;
        if (input == ".")
            break;
    }
    return 0;
}
