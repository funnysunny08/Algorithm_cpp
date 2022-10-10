// 17298번: 오큰수 (실패)
#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s, result;
deque<int> box;
vector<int> nge;

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    //
    while (!s.empty())
    {
        int num = s.top(); // 스택의 최상단 원소 꺼내옴
        s.pop();
        box.push_front(num);
        bool ck = false;
        for (int i = 0; i < box.size(); i++)
        {
            if (num < box[i]) {
                result.push(box[i]);
                ck = true;
                break;
            }
        }        
        if (ck == false)
            result.push(-1);
    }
    
    while (!result.empty())
    {
        cout << result.top() << ' ';
        result.pop();
    }   
    return 0;
}