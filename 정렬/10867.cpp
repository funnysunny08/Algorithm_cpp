// 10867번: 중복 빼고 정렬하기
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    // 오름차순 정렬
    sort(v.begin(), v.end()); 

    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }   

    return 0;
}