// 1927번: 최소 힙
#include <bits/stdc++.h>
using namespace std;


priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    // 입력 받기
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        if(x == 0) {
            if(pq.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
    return 0;
}