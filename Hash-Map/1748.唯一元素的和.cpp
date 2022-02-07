#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_set<int> st;
        int res = 0;
        for(int& num : nums) {
            if(st.count(num) && st.count(-num)) {
                continue; // 出现第二次以上
            }
            if(st.count(num)) {
                st.insert(-num);
                res += -num; // 出现第二次
            } else {
                st.insert(num);
                res += num; //出现第一次
            }
        }
        return res;
    }
};
