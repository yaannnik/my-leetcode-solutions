#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& s : strs) {
            string key = getKey(s);
            mp[key].emplace_back(s);
        }
        vector<vector<string>> res;
        for(auto& [key, v] : mp) {
            res.push_back(v);
        }
        return res;
    }

    string getKey(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};
