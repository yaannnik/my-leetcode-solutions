#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& num : nums) {
            if(s.count(num)) {
                return num;
            }
            s.insert(num);
        }
        return -1;
    }
};
