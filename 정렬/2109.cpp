// 2109번: 순회 강연 (실패)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int box[9999];

bool compare(const pair<int, int> &a, const pair<int, int> &b) // vector의 second에 대해 내림차순 정렬
{
    return a.second > b.second;
}

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, d;
        cin >> p >> d;
        v.push_back(make_pair(d, p)); // (day, pay) 형식으로 저장
    }
    // 가장 기한이 긴 day 찾기
    sort(v.begin(), v.end());
    int lastDay = v[n - 1].first;
    // pay에 대해 내림차순 정렬
    sort(v.begin(), v.end(), compare);

    //
    for (int i = 0; i < n; i++)
    {
        int day = v[i].first;
        int pay = v[i].second;

        for (int j = day; j > 0; j--)
        {
            if(box[j] == 0){
                box[j] = pay;
                break;
            }
        }
    }
    int result = 0;
    for (int i = 0; i <= lastDay; i++)
    {
        result += box[i];
    }
    
    cout << result << endl;

    return 0;
}