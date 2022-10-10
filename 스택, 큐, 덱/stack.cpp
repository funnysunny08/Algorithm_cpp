#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main(void) {
    // 삽입(5) - 삽입(10) - 삽입(3) - 삽입(22) - 삭제() - 삽입(1) - 삽입(4) - 삭제
    s.push(5);
    s.push(10);
    s.push(3);
    s.push(22);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();
    // 스택의 최상단 원소부터 출력
    while (!s.empty()) {
        cout << s.top() << ' '; // 출력 후
        s.pop(); // 삭제
    }
}