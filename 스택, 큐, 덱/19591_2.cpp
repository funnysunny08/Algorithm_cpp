// 19591번: 독특한 계산기
#include <bits/stdc++.h>
using namespace std;

string str;
string temp;
deque<string> dq;

long long calc(string num1, string oper, string num2) {
    long long ret;
    if (oper == "*") {
        ret = stoll(num1) * stoll(num2);
    } else if (oper == "/") {
        ret = stoll(num1) / stoll(num2);  
    } else if (oper == "+") {
        ret = stoll(num1) + stoll(num2);
    } else if (oper == "-") {
        ret = stoll(num1) - stoll(num2);
    }
    return ret;
}

int priority(string oper) { 
    if (oper == "*" || oper == "/")
        return 1;
    else
        return 2;
}

int main() {
    // 입력받기
    cin >> str;
    // 덱에 집어넣기
    for (long long i = 0; i < str.length(); i++)
    {
        if ((str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') && i != 0){
            dq.push_back(temp);
            string s(1, str[i]);
            dq.push_back(s);
            temp.clear();
        } else {
            temp += str[i];
            if (i == str.length() - 1) {
                dq.push_back(temp);
            }
        }
    }

    while (dq.size() != 1)
    {
        string op1 = dq[1];
        string op2 = dq[dq.size() - 2];
        long long res1;
        long long res2;

        if ((priority(op1) * priority(op2)) == 2) {
            if (priority(op1) == 1) {
                res1 = calc(dq[0], dq[1], dq[2]);
                dq.pop_front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(to_string(res1));
            } else {
                res2 = calc(dq[dq.size() - 3], dq[dq.size() - 2], dq[dq.size() - 1]);
                dq.pop_back();
                dq.pop_back();
                dq.pop_back();
                dq.push_back(to_string(res2));
            }
        } else {
            res1 = calc(dq[0], dq[1], dq[2]);
            res2 = calc(dq[dq.size() - 3], dq[dq.size() - 2], dq[dq.size() - 1]);

            if (res2 > res1) {
                dq.pop_back();
                dq.pop_back();
                dq.pop_back();
                dq.push_back(to_string(res2));
            } else {
                dq.pop_front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(to_string(res1));
            }
        }
    }
    
    cout << stoll(dq[0]) << endl;

    return 0;
}