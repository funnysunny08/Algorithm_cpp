// 바닥 공사
#include <bits/stdc++.h>
using namespace std;

int n;
int d[1001];

int main(void) {
    cin >> n;
    // 다이나믹 프로그래밍 진행 (보텀업)
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796;
    }
    cout << d[n] << endl;
}