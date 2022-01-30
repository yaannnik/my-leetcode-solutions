#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1, mp2;
        mapWords(s1, mp1);
        mapWords(s2, mp2);
        vector<string> res;
        for(auto& p : mp1) {
            if(p.second == 1 && !mp2.count(p.first)) {
                res.emplace_back(p.first);
            }
        }
        for(auto& p : mp2) {
            if(p.second == 1 && !mp1.count(p.first)) {
                res.emplace_back(p.first);
            }
        }
        return res;
    }

    void mapWords(string& str, unordered_map<string, int>& mp) {
        stringstream in(str);
        string word;
        while(getline(in, word, ' ')) {
            mp[word]++;
        }
    }
};
