// 1로 만들기
#include <bits/stdc++.h>
using namespace std;

int d[30001]; // DP 테이블 초기화
int x;

int main(void) {
    cin >> x;
    // 다이타믹 프로그래밍 진행 (보텀업)
    for (int i = 2; i <= x; i++)
    {
        // 현재의 수에서 1을 빼는 경우
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) 
            d[i] = min(d[i], d[i / 2] + 1);
        if (i % 3 == 0) 
            d[i] = min(d[i], d[i / 3] + 1);
        if (i % 5 == 0) 
            d[i] = min(d[i], d[i / 5] + 1);
    }
    cout << d[x] << endl;
}
