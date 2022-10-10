#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    pq.push(5);
    pq.push(10);
    pq.push(3);
    pq.push(7);
    while (!pq.empty())
    {       
        cout << pq.top() << ' ';
        pq.pop();
    }   
}