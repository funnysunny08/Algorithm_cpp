// 15652번: N과 M (4)
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int t;

void func(int k, int t) {
    if (k == m) {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;        
    }
    for (int i = t; i <= n; i++, t++)
    {
        arr[k] = i;
        func(k + 1, t);
    }  
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0, 1);
}