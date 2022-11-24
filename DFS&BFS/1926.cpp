// 1926번: 도화지
#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[501][501];
int visited[501][501];
vector<int> result;
int cnt;

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs (int x, int y) {
    if (x <= -1 || x >= n || y <= -1 || y >= m) return false;

    if (graph[x][y] == 1 && visited[x][y] == 0) {
        visited[x][y] = 1;
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny);
        }
        return true;
    }
    return false;
}

int main(void) {
    // 입력 받기
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    //
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j)) {
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(result.begin(), result.end(), greater<int>());

    cout << result.size() << endl;
    if (result.size() != 0) {
        cout << result[0] << endl;
    } else {
        cout << 0 << endl;
    }
}