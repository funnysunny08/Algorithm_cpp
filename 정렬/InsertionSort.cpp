#include <bits/stdc++.h>

using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main() {
    for (int i = 1; i < n; i++)
    {   
        for (int j = i; j > 0; j--)
        {
            // 한 칸씩 왼쪽으로 이동 (자기 왼쪽 데이터랑 swap)
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
            // 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
            else break;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}