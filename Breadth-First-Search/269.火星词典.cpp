#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> mp;
        for(int i = 0; i < words.size()-1; i++) {
            int len = min(words[i].size(), words[i+1].size());
            for(int j = 0; j < len; j++) {
                if(words[i][j] != words[i+1][j]) {
                    mp[words[i][j]].emplace_back(words[i+1][j]);
                    break;
                } else {
                    if(j == len-1) {
                        if(words[i].size() > words[i+1].size()) {
                            return "";
                        }
                    }
                }
            }
        }
        vector<int> in(26, -1);
        for(auto& word : words) {
            for(int i = 0; i < word.size(); i++) {
                in[word[i]-'a'] = 0;
            }
        }
        for(auto& p : mp) {
            for(int i = 0; i < p.second.size(); i++) {
                in[p.second[i]-'a']++;
            }
        }
        queue<int> qu;
        int cnt = 0;
        string res;
        for(int i = 0; i < 26; i++) {
            if(in[i] == 0) {
                qu.push(i);
            }
            if(in[i] != -1) {
                cnt++;
            }
        }

        while(!qu.empty()) {
            int front = qu.front();
            qu.pop();
            res += 'a'+front;
            for(int i = 0; i < mp['a'+front].size(); i++) {
                in[mp['a'+front][i]-'a']--;
                if(in[mp['a'+front][i]-'a'] == 0) {
                    qu.push(mp['a'+front][i]-'a');
                }
            }
        }
        if(res.size() != cnt) {
            return "";
        }
        return res;
    }
};
