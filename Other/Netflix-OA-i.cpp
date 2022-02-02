#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> func(vector<int>& times) {
        int n = times.size();
        vector<int> res = times;
        queue<int> qu;
        qu.push(0);
        int finish = 0;
        for(int i = 1; i < n; i++) {
            while(times[i] >= finish && !qu.empty()) {
                int top = qu.front();
                qu.pop();
                finish = max(finish + 300, times[top] + 300);
                res[top] = finish;
            }
            if(qu.size() <= 10) {
                qu.push(i);
            }
        }
        while(!qu.empty()) {
            int top = qu.front();
            qu.pop();
            finish = max(finish + 300, times[top] + 300);
            res[top] = finish;
        }
        return res;
    }
};

int main() {
    vector<int> times = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    Solution sol;
    vector<int> res = sol.func(times);
    for(int& i : res) {
        cout << i << endl;
    }
    return 0;
}
