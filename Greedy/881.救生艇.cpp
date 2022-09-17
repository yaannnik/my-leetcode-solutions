#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int left = 0, right = n - 1;
        int res = 0;
        while(left <= right) {
            if(right == left) {
                res++;
                break;
            }
            if(people[left] + people[right] <= limit) {
                // 一大带一小
                res++;
                left++;
                right--;
            } else {
                // 只取大端
                res++;
                right--;
            }
        }
        return res;
    }
};
