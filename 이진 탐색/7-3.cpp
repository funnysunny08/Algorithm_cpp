#include <bits/stdc++.h>
using namespace std;

// 이진 탐색(반복문)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target) return mid;
        // mid > target --> 왼쪽 확인
        else if (arr[mid] > target) end = mid - 1;
        // mid < target --> 오른쪽 확인
        else start = mid + 1;
    }
    return  -1;
}

int n, target;
vector<int> arr;

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력 받기
    cin >> n >> target;
    // 전체 원소 입력 받기
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << endl;
    } else {
        cout << result << endl;
    }    
}