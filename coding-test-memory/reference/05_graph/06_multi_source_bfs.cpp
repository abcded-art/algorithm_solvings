#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int DY[4] = {-1, 1, 0, 0};
const int DX[4] = {0, 0, -1, 1};

int main() {
    // 1인 모든 칸에서 동시에 출발해 각 0까지의 최단 거리를 구한다.
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}
    };

    int h = grid.size();
    int w = grid[0].size();
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (grid[y][x] == 1) {
                dist[y][x] = 0;
                q.push({y, x});
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + DY[dir];
            int nx = x + DX[dir];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    for (const auto& row : dist) {
        for (int value : row) cout << value << ' ';
        cout << '\n';
    }
}
