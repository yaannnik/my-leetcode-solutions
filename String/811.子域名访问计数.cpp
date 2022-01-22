#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for(string& s : cpdomains) {
            cnt(s);
        }
        vector<string> res;
        for(auto& p : mp) {
            string tmp = "";
            tmp += to_string(p.second);
            tmp += " ";
            tmp += p.first;
            res.emplace_back(tmp);
        }
        return res;
    }

    void cnt(string& s) {
        int cnt = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                cnt = stoi(s.substr(0, i));
            }

            if(s[i] == '.' || s[i] == ' ') {
                left = i + 1;
                if(left < s.size()) {
                    mp[s.substr(left)] += cnt;
                }
            }
        }
    }
};
