// 효율적인 화폐 구성
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // DP 테이블 초기화
    vector<int> d(m + 1, 10001);

    // 다이나믹 프로그래밍 진행 (보텀업)
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= m; j++) {
            // (i - k)원을 만드는 방법이 존재하는 경우
            if (d[j - arr[i]] != 10001) {
                d[j] = min(d[j], d[j - arr[i]] + 1);
            }
        }    
    }
    
    // 결과 출력
    if (d[m] == 10001) {
        cout << -1 << endl;
    } else {
        cout << d[m] << endl;
    }
}