#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

int main() {
    dq.push_front(100);
    dq.push_back(45);
    dq.push_back(20);
    dq.push_front(11);

    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << ' ';
    }

    return 0;
}