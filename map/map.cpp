#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m[5] = "five";
    m[3] = "three";
    m[8] = "eight";
    m[4] = "four";

    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    for(auto it : m){
        cout << it.first << "->" << it.second << endl;
    }

    map<int, string, greater<int>> m;

    m[5] = "five";
    m[3] = "three";
    m[8] = "eight";
    m[4] = "four";

    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}
