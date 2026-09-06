#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
vector<bool> used;

void backtrack(int n) {
    if ((int)path.size() == n) {
        for (int x : path) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        used[i] = true;
        path.push_back(i);

        backtrack(n);

        // 원상 복구가 핵심
        path.pop_back();
        used[i] = false;
    }
}

int main() {
    int n = 3;
    used.assign(n + 1, false);
    backtrack(n);
}
