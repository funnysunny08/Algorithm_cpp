// 수 묶기
#include <bits/stdc++.h>
using namespace std;

bool desc(int a, int b) { return a > b; }

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    vector<int> pos;
    vector<int> neg;
    bool isZero = false;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            pos.push_back(v[i]);
        }
        else if (v[i] < 0)
        {
            neg.push_back(v[i]);
        }
        else
        {
            isZero = true;
        }
    }
    sort(pos.begin(), pos.end(), desc);
    sort(neg.begin(), neg.end());

    int result = 0;
    int temp;

    for (int i = 0; i < pos.size(); i += 2)
    {
        int a = pos[i];
        int b;
        if (i == pos.size() - 1)
        {
            b = 0;
        }
        else
        {
            b = pos[i + 1];
        }

        if (a > 0 && b > 0)
        {
            temp = a * b;
        }
        else
        {
            temp = a + b;
        }
        result += temp;
    }

    for (int i = 0; i < neg.size(); i += 2)
    {
        int a = neg[i];
        int b;
        if (i == neg.size() - 1)
        {
            b = 0;
        }
        else
        {
            b = neg[i + 1];
        }

        if (a < 0 && b < 0)
        {
            temp = a * b;
        }
        else if (i == neg.size() - 1 && isZero)
        {
            temp = 0;
        }
        else
        {
            temp = a + b;
        }
        result += temp;
    }

    cout << result << endl;

    return 0;
}
