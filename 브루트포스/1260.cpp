#include <bits/stdc++.h>
using namespace std;

int n, m, v; // 노드 수, 간선 수, 시작 노드
vector<int> graph[1001];
bool visitedDFS[1001];
bool visitedBFS[1001];

void DFS(int start)
{
    int x = start;
    cout << x << ' ';
    visitedDFS[x] = true;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if (!visitedDFS[y])
        {
            DFS(y);
        }
    }
}

void BFS(int start)
{
    queue<int> qq;
    qq.push(start);
    visitedBFS[start] = true;

    while (!qq.empty())
    {
        int x = qq.front();
        qq.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if (!visitedBFS[y])
            {
                qq.push(y);
                visitedBFS[y] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < n + 1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(v);
    cout << endl;
    BFS(v);

    return 0;
}