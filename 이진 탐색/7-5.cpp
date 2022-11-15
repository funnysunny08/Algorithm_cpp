#include <bits/stdc++.h>
using namespace std;

vector<int> product;
vector<int> order;

int binarySearch (vector<int> &arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) return mid;
        else if(arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;    
}

int main(void) {
    // 입력 받기
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        product.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        order.push_back(x);
    }
    sort(product.begin(), product.end());

    //
    for (int i = 0; i < m; i++)
    {
        int result = binarySearch(product, order[i], 0, product.size() - 1);
        if (result == -1) {
            cout << "no ";
        } else {
            cout << "yes ";
            product.erase(product.begin() + result - 1);
        }
    }    
}