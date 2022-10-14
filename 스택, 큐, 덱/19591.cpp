// 19591번: 독특한 계산기 (실패)
#include <bits/stdc++.h>
using namespace std;

string str;
string temp;
deque<string> dq;
long long result;

int main() {
    // 입력받기 + 덱에 집어 넣기
    cin >> str;
    long long length = str.size();

    for (long long i = 0; i < length; i++)
    {
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' && i != 0){
            dq.push_back(temp);
            string s1(1, str[i]);
            dq.push_back(s1);
            temp.clear();
        } else {
            temp += str[i];
        }
    }
    if(!temp.empty()) {
        dq.push_back(temp);
    }

    //
    if (dq.size() == 1) {
        cout << dq[0] << endl;
        return 0;
    }

    while (dq.size() != 1)
    {
        string op1 = dq[1];
        string op2 = dq[dq.size() - 2];
        // 연산자 우선 순위 비교
        if ((op1 == "*" || op1 == "/") && (op2 == "+" || op2 == "-"))
        {   long long r;
            if (op1 == "*")
            {
                r = stoll(dq[0]) * stoll(dq[2]);
            } else if (op1 == "/")  
            {
                r = stoll(dq[0]) / stoll(dq[2]);
            }
            dq.pop_front();
            dq.pop_front();
            dq.pop_front();
            dq.push_front(to_string(r));
            
        } else if ((op2 == "*" || op2 == "/") && (op1 == "+" || op1 == "-"))
        {
            long long r;
            if (op2 == "*") {
                r = stoll(dq[dq.size() - 3]) * stoll(dq[dq.size() - 1]);
            } else if (op2 == "/") {
                r = stoll(dq[dq.size() - 3]) / stoll(dq[dq.size() - 1]);
            }
            dq.pop_back();
            dq.pop_back();
            dq.pop_back();
            dq.push_back(to_string(r));
        } else{ // 비교해야 하는 상황
            long long r1, r2;
            // 왼 쪽 계산해서 r1에 넣기
            if (op1 == "*") {
                r1 = stoll(dq[0]) * stoll(dq[2]);
            } else if (op1 == "/")
            {
                r1 = stoll(dq[0]) / stoll(dq[2]);
            } else if (op1 == "+")        
            {
                r1 = stoll(dq[0]) + stoll(dq[2]);
            } else if (op1 == "-") {
                r1 = stoll(dq[0]) - stoll(dq[2]);
            }

            // 오른쪽 계산해서 r2에 넣기
            if (op2 == "*") {
                r2 = stoll(dq[dq.size() - 3]) * stoll(dq[dq.size() - 1]);
            } else if (op2 == "/")
            {
                r2 = stoll(dq[dq.size() - 3]) / stoll(dq[dq.size() - 1]);
            } else if (op2 == "+")        
            {
                r2 = stoll(dq[dq.size() - 3]) + stoll(dq[dq.size() - 1]);
            } else if (op2 == "-") {
                r2 = stoll(dq[dq.size() - 3]) - stoll(dq[dq.size() - 1]);
            }

            // r1, r2 비교하기

            if (r2 > r1) {
                dq.pop_back();
                dq.pop_back();
                dq.pop_back();
                dq.push_back(to_string(r2));
            } else {
                dq.pop_front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(to_string(r1));
            }
        }
        
        
    }
    
    
    // // 이제 dq에 원소 3개 남았을 때
    // if (dq[1] == "*") {
    //     result = stoll(dq[0]) * stoll(dq[2]);
    // } else if (dq[1] == "/")
    // {
    //     result = stoll(dq[0]) / stoll(dq[2]);
    // } else if (dq[1] == "+")        
    // {
    //     result = stoll(dq[0]) + stoll(dq[2]);
    // } else if (dq[1] == "-") {
    //     result = stoll(dq[0]) - stoll(dq[2]);
    // }
    cout << dq[0] << endl;


    return 0;
}