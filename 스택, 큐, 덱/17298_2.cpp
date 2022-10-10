// 17298번: 오큰수 
#include <bits/stdc++.h>
using namespace std;

// vector <int> arr, nge;
int arr[1000001];
int nge[1000001];
stack<int> box;
int n;

int main() {
    // 입력받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //
    for (int i = n - 1; i >= 0; i--)
    {
        while (!box.empty() && box.top() <= arr[i]) // arr[i] 보다 큰 수 만날 때 까지 pop()
        {
            box.pop();
        }
        if (box.empty())
            nge[i] = -1;
        else
            nge[i] = box.top();

        box.push(arr[i]); 
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << ' ';
    }
    
    return 0;
}