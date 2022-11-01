// 15650번: N과 M (2)
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
int t;

void func(int k, int t) {
    if (k == m) {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout <<endl;
        return;
    }
    for (int i = t; i <= n; i++, t++)
    {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1, t);
            isused[i] = false;
        }
    }    
}

int main() {
    cin >> n >> m;
    func(0, 1);
    return 0;
}