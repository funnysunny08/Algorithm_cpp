#include <bits/stdc++.h>

using namespace std;
// 절대값이 더 작은 값에 우선순위를 높게 주고, 절대값이 같다면 더 작은 값에 우선순위를 높게 준다.
struct compare { 
    bool operator() (int a, int b) {
        if(abs(a) > abs(b))
            return true;
        else if (abs(a) == abs(b))
            if (a > b)
                return true;
            else 
                return false;
        return false;
    }
};

priority_queue<int, vector<int>, compare> pq;

int main() {
    pq.push(50);
    pq.push(-41);
    pq.push(-50);
    pq.push(-100);
    pq.push(500);
    pq.push(41);

    while (!pq.empty())
    {       
        cout << pq.top() << ' ';
        pq.pop();
    }   
    return 0;
}