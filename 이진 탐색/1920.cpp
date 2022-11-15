// 1920번: 수 찾기
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;

int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++)
    {
        int result = binarySearch(a, b[i], 0, n -1);
        if (result == -1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}
