#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    //
    int start = 0;
    int end = 1e9;
    //
    int result = 0;
    while (start <= end) {
        long long int total = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) total += arr[i] - mid;
        }
        if (total < m) { // 떡의 양이 부족한 경우 더 많이 자르기 (왼쪽 부분 탐색)
            end = mid - 1;
        } else { // 떡의 양이 충분한 경우 덜 자르기 (오른쪽 부분 탐색)
            result = mid;
            start = mid + 1;
        }
    }
    cout << result << endl;    
}