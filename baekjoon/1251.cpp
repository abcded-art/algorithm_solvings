#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <limits>
#include <numeric>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <climits>
#define endl "\n"
using namespace std;
#define pii pair<int, int>
#define X first
#define Y second

set<string> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    string a, b, c;

    for(int i = 1; i < input.size() - 1; i++){
        for(int j = i + 1; j < input.size(); j++){
            // 0 ~ i - 1
            a = input.substr(0, i);
            // i ~ j - 1
            b = input.substr(i, j - i);
            // j ~ input.size() - 1
            c = input.substr(j, input.size() - j);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            a = a + b + c;
            s.insert(a);
        }
    }

    cout << *s.begin() << endl;
    
    return 0;
}

