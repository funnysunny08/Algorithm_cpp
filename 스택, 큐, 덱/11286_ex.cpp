#include <bits/stdc++.h>
using namespace std;

class comp{
public:
	bool operator()(const int& a, const int& b)
	{
        if (abs(a) >= abs(b)){
            if (abs(a) == abs(b)){
                if (a < b){
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
	}
};
priority_queue<int, vector<int>, comp> pq;

int main() {
    pq.push(4);
    pq.push(-4);
    pq.push(5);
    pq.push(10);
    pq.push(3);
    pq.push(-10);

    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    
    

}