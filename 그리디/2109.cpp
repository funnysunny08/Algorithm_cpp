// 순회 강연
#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    // day가 가장 짧은 것이 top으로 가게 함.
    int result = 0;
    int p, d;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> d;
        pq.push(pair<int, int>(p, d));
    }

    int today = 1;
    while (pq.size() > 1)
    {
        if (today > pq.top().second)
        {
            pq.pop();
        }
        else
        {
            int aDay = pq.top().first;
        }
        today++;
    }

    return 0;
}