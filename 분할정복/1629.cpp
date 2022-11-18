// 1629번: 곱셈
#include <bits/stdc++.h>
using namespace std;

long long a, b, c, k;

long long power(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    k = power(b / 2) % c;
    if (b % 2 == 0) return k * k % c;
    return k * k % c * a % c;
}

int main(void) {
    // 입력 받기
    cin >> a >> b >> c;
    //
    cout << power(b);
    return 0;
}