// 7983번: 내일 할거야
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(const pair<int, int> &a, const pair<int, int> &b) // vector의 second에 대해 내림차순 정렬
{
    return a.second > b.second;
}

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d, t;
        cin >> d >> t;
        v.push_back(make_pair(d, t)); // (소요 시간, 마감 기한)
    }
    // 기한에 대해 내림차순 정렬
    sort(v.begin(), v.end(), compare);

    int day = v[0].second;

    // 
    for (int i = 0; i < n; i++)
    {
        int dday = v[i].second;
        int time = v[i].first;

        if (dday < day) {
            day = dday - time;
        } else {
            day -= time;
        }
    }
    
    cout << day << endl;   

    return 0;
}