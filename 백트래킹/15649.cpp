// 15649번 - N과 M (1)
#include <bits/stdc++.h>
using namespace std;

int n, m; 
int arr[10]; // 수열을 담을 배열
bool isused[10]; // 특정 수가 쓰였는지

void func(int k) { // 현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수
    if (k == m) { // k == m이 되었을 때 m개를 모두 택했으니 수열을 출력한 뒤 함수를 종료하면 된다.
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n'; 
        return;    
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i]) { // 아직 안 쓰인 수를 찾아낸다.
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0; // 모든 과정을 끝내고 와서 isused --> false 로!
        }
    }   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0); // 수를 한 개도 택하지 않았기 때문에 func(0) 호출
    // func(0)은 arr[0]을 정한 후에 func(1) 호출
}