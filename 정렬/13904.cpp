// 13904번: 과제
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;
int work[9999];
int result;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int main() {
    // 입력받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    // 가장 긴 day 찾기
    sort(v.begin(), v.end());
    int lastDay = v[n - 1].first;
    // 점수를 기준으로 내림차순
    sort(v.begin(), v.end(), compare);
    //
    for (int i = 0; i < n; i++)
    {
        int day = v[i].first;
        int score = v[i].second;
        for (int j = day; j > 0; j--)
        {
            if(work[j] == 0) {
                work[j] = score;
                break;
            }
        }        
    }
    
    for (int i = 0; i <= lastDay; i++)
    {
        result += work[i];
    }
    
    cout << result <<endl;

    
    return 0;
}