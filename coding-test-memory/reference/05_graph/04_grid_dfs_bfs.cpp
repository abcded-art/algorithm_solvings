#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int DY[4] = {-1, 1, 0, 0};
const int DX[4] = {0, 0, -1, 1};

void bfs(const vector<vector<int>>& grid, int startY, int startX) {
    if (grid.empty() || grid[0].empty()) return;

    int h = grid.size();
    int w = grid[0].size();
    if (startY < 0 || startY >= h || startX < 0 || startX >= w) return;
    if (grid[startY][startX] == 0) return;

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    queue<pair<int, int>> q;
    q.push({startY, startX});
    visited[startY][startX] = true;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        cout << '(' << y << ',' << x << ") ";

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + DY[dir];
            int nx = x + DX[dir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (grid[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    cout << '\n';
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1}
    };

    bfs(grid, 0, 0);
}
