// 2667번: 단지번호붙이기
#include <bits/stdc++.h>
using namespace std;

int n;
int graph[26][26];

// vector<int> result;
int result = 2;
vector<int> v;
int cnt = 0;

bool dfs (int x, int y) {
    if (x <= -1 || x >= n || y <= -1 || y >= n) return false;
    // 현재 노드를 아직 방문하지 않았다면
    if (graph[x][y] == 1) {
        // 해당 노드 방문 처리
        graph[x][y] = result;
        cnt++;
        // 상, 하, 좌, 우 재귀적으로 호출
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

int main(void) {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    
    //
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j)) {
                result++;
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    
    return 0;
}