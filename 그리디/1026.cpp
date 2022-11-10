// 보물
#include <bits/stdc++.h>
using namespace std;

bool desc(int a, int b) { return a > b; }

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), desc);

    for (int i = 0; i < n; i++)
    {
        sum += v1[i] * v2[i];
    }
    cout << sum << endl;

    return 0;
}
