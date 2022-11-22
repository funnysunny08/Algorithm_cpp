// 1987번: 알파벳
#include <bits/stdc++.h>
using namespace std;

int r, c;
char graph[20][20];
int result = 0;
vector<char> ck;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool rangeCheck(int x, int y) {
    if (x <= -1 || x >= r || y <= -1 || y >= c) return false;
    return true;
}

bool alphaCheck(int x, int y) {
    for (int i = 0; i < ck.size(); i++) {
        if (graph[x][y] == ck[i]) return false;
    }
    return true;
}

void dfs (int x, int y, int find_path) {
    result = max(result, find_path);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (rangeCheck(nx, ny) && alphaCheck(nx, ny)) {
            ck.push_back(graph[nx][ny]);
            dfs(nx, ny, find_path + 1);
            ck.pop_back();
        }
    }
}

int main(void) {
    // 입력 받기
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }
    // 
    ck.push_back(graph[0][0]);
    dfs(0, 0, 1);
    printf("%d\n", result);
}