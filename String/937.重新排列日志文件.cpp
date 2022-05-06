#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<vector<string>, int>> words;
        vector<string> digits;
        for(int i = 0; i < logs.size(); i++) {
            string s = logs[i];
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == ' ') {
                    if(s[j+1] >= '0' && s[j+1] <= '9') {
                        digits.emplace_back(s);
                    } else {
                        vector<string> tmp = {s.substr(j+1),s.substr(0,j)};
                        words.emplace_back(tmp, i);
                    }
                    break;
                }
            }
        }
        sort(words.begin(), words.end(), cmp);
        vector<string> res;
        for(auto& w: words) {
            res.emplace_back(logs[w.second]);
        }
        for(auto& d: digits) {
            res.emplace_back(d);
        }
        return res;
    }

    bool static cmp(pair<vector<string>, int>& x, pair<vector<string>, int>& y) {
        if(x.first[0] == y.first[0] && x.first[1] == y.first[1]) {
            return x.second < y.second;
        } 
        else if(x.first[0] == y.first[0]) {
            return x.first[1] < y.first[1];
        } 
        else {
            return x.first[0] < y.first[0];
        }
    }
};
