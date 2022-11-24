// 1012번: 유기농 배추
#include <bits/stdc++.h>
using namespace std;

int t; // 테스트 케이스 개수
int n, m, k;
int graph[50][50];
int visited[50][50];

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> ans;

bool dfs (int x, int y, int graph[50][50]) { 
    // 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (x <= -1 || x >= n || y <= -1 || y >= m) return false;
    //
    if (visited[x][y] == 0 && graph[x][y] == 1) { // 방문한 적 없고 배추가 있는 자리라면
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny, graph);
        }
        return true;
    }
    return false;
}

int cabbage (int n, int m, int graph[50][50]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j, graph)) result++;
        }
    }
    return result;
}


int main(void) {
    // 입력 받기
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }
        ans.push_back(cabbage(n, m, graph));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

