#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0, right = 0;
        int res = 0;
        for(; left < s.size(); left++) {
            //删除前一个
            if(left > 0) {
                chars.erase(s[left-1]);
            }
            //快指针在没有重复的情况下先一直往后走
            while(right < s.size() && chars.find(s[right]) == chars.end()) {
                chars.insert(s[right]);
                right++;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
