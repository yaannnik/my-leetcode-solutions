#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> res;
    unordered_map<char, vector<char>> mp;
    vector<string> letterCombinations(string digits) {
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        if(digits.size() == 0) {
            return {};
        }
        dfs("", digits, 0);
        return res;
    }

    void dfs(string tmp, string digits, int idx) {
        if(tmp.size() == digits.size()) {
            res.emplace_back(tmp);
        }
        for(int i = 0; i < mp[digits[idx]].size(); i++) {
            dfs(tmp + mp[digits[idx]][i], digits, idx+1);
        }
        return;
    }
};
