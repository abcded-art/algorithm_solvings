#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool field[50][50];
bool visited[50][50];

int T, M, N, K;

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < M && ny >= 0 && ny < N && field[nx][ny] && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int iter = 0; iter < T; iter++){
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }
        int ans = 0;
        for(int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if(field[i][j] == true && !visited[i][j]){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;

        memset(field, false, sizeof(field));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}