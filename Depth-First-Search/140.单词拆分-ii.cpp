#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> word;
        dfs(0, word, s, wordDict);
        return res;
    }

    void dfs(int idx, vector<string> words, string& s, vector<string>& wordDict) {
        if(idx == s.size()) {
            string tmp = "";
            for(int i = 0; i < words.size(); i++) {
                tmp += words[i];
                if(i != words.size() - 1) {
                    tmp += " ";
                }
            }
            res.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < wordDict.size(); i++) {
            int l = wordDict[i].size();
            string pattern = wordDict[i];
            if(idx + l - 1 < s.size() && s.substr(idx, l) == pattern) {
                vector<string> words_ = words;
                words_.emplace_back(pattern);
                dfs(idx + l, words_, s, wordDict);
            }
        }
    }

    vector<string> res;
};
