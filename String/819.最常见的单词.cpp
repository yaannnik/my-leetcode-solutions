#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res = "";
        int cnt = 0;
        unordered_map<string, int> mp;
        unordered_set<string> ban;
        for(string& str : banned) {
            ban.insert(str);
        }
        vector<string> v;
        string tmp = "";
        for(char& ch : paragraph) {
            if(isAlpha(ch)) {
                tmp += ch;
            } else {
                if(tmp != "") {
                    v.emplace_back(tmp);
                    tmp = "";
                } else {
                    continue;
                }
            }
        }
        if(tmp != "") {
            v.emplace_back(tmp);
        }
        for(string& str : v) {
            // cout << str << endl;
            str = lower(str);
            if(!ban.count(str)) {
                mp[str]++;
                if(mp[str] > cnt) {
                    cnt = mp[str];
                    res = str;
                }
            }
        }
        return res;
    }

    string lower(string s) {
        for(char& ch : s) {
            if(ch >= 'A' && ch <= 'Z') {
                ch = 'a' + (ch - 'A');
            }

        }
        return s;
    }

    bool isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};
