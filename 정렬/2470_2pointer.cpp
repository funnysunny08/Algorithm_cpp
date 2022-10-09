// 2470번: 두 용액
#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000;
int n;
vector<int> v;
int result[2];

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // 정렬
    sort(v.begin(), v.end());

    //
    int left = 0;
    int right = v.size() - 1;
    int res = INF;

    while (left < right)
    {
        int temp = v[left] + v[right];
        if (abs(temp) < res) {
            result[0] = v[left];
            result[1] = v[right];
            res = abs(temp);

            if (temp == 0) {
                break;
            }
        }
        
        if (temp < 0){ // temp가 음수면 left++
            left++;
        } else { // temp가 양수면 right--
            right--;
        } 
    }

    cout << result[0] << ' ' << result[1] << endl;

    return 0;
}