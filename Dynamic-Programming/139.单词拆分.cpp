#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        vector<int> lefts = {0};
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(int i = 0; i < n; i++) {
            for(int& left : lefts) {
                if(dict.count(s.substr(left, i - left + 1))) {
                    dp[i] = true;
                    lefts.emplace_back(i+1);
                    break;
                }
            }
        }
        return dp.back();
    }
};
