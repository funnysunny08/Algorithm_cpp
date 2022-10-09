// 2470번: 두 용액
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> m; // 음수
vector<int> p; // 양수 + 0 
int res[2];

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0) {
            p.push_back(x);
        } else if(x < 0) {
            m.push_back(x);
        }
    }
    // 음수 박스 내림차순 정렬
    sort(m.begin(), m.end(), greater<>());
    // 양수 박스 오름차순 정렬
    sort(p.begin(), p.end());

    //
    if(m.size() == 0 || p.size() == 0) { // 둘 중 한 박스가 비어있다면
        if(p.size() == 0){ // 양수 박스가 비어있다면
            res[0] = m[1];
            res[1] = m[0];
        } else {
            res[0] = p[0];
            res[1] = p[1];
        }
    } else {
        int temp = m[0] + p[0];
        int temp2 = m[m.size() - 1] + p[p.size() - 1];
        if(abs(temp) < abs(temp2)) {
            res[0] = m[0];
            res[1] = p[0];
        } else {
            res[0] = m[m.size() - 1];
            res[1] = p[p.size() - 1];
        }
    }
    cout << res[0] << ' ' << res[1] << endl;

    return 0;
}