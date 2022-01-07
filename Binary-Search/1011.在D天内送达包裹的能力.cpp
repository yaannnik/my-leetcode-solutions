#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = maxVec(weights), right = sumVec(weights);
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(possible(weights, mid, days)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int sumVec(vector<int>& weights) {
        int res = 0;
        for(auto& i : weights) {
            res += i;
        }
        return res;
    }

    int maxVec(vector<int>& weights) {
        priority_queue<int> qu(weights.begin(), weights.end());
        return qu.top();
    }

    bool possible(vector<int>& weights, int capacity, int days) {
        int tmp = capacity;
        int day = 1;
        for(int i = 0; i < weights.size(); i++) {
            //今日可以继续运i
            if(tmp - weights[i] >= 0) {
                tmp -= weights[i];
            } else {
                //今日不能继续运i，将i留到下一天
                day++;
                if(day > days) {
                    return false;
                }
                tmp = capacity - weights[i];
            }
        }
        return true;
    }
};
