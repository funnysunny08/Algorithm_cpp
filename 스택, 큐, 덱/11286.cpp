// 11286번: 절댓값 힙
#include <bits/stdc++.h>
using namespace std;

int n;
// bool compare(int a, int b) // vector의 second에 대해 내림차순 정렬
// {
//     if (abs(a) < abs(b)){
//         return true;
//     } else if (abs(a) == abs(b)) {
//         if (a < b){
//             return true;
//         } else {
//             return false;
//         }
//     } else{
//         return false;
//     }
// }

// class comp{
// public:
// 	bool operator()(const int& a, const int& b)
// 	{
//         if (abs(a) >= abs(b)){
//             if (abs(a) == abs(b)){
//                 if (a > b){
//                     return true;
//                 }
//                 return false;
//             }
//             return true;
//         }
//         return false;
// 	}
// };
struct comp {
    bool operator()(int a, int b)
	{
        // if (abs(a) >= abs(b)){
        //     if (abs(a) == abs(b)){
        //         if (a > b){
        //             return true;
        //         }
        //         return false;
        //     }
        //     return true;
        // }
        // return false;
        if (abs(a) == abs(b)) 
            return a > b;
        else return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, comp> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 0){
            if (pq.empty()) {
                cout << '0' << endl;
            } else{
                cout << pq.top() << endl;
                pq.pop();
            }

            
        } else{
            pq.push(x);
        }
    }
    

    return 0;
}