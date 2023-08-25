#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words = unordered_set<string>(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) {
            return 0;
        }
        unordered_set<string> beginSet{beginWord}, endSet{endWord};
        int res = 1;
        while(!beginSet.empty()) {
            unordered_set<string> tmpSet;
            res++;
            for(auto& s: beginSet) {
                words.erase(s);
            }
            for (auto& s : beginSet) {
                for (int i = 0; i < s.size(); ++i){
                    string str = s;
                    for (char c = 'a'; c <= 'z'; ++c){
                        str[i] = c;
                        if (words.find(str) == words.end()){
                            continue;
                        }
                        if (endSet.find(str) != endSet.end()){
                            return res;
                        }
                        tmpSet.insert(str);
                    }
                }
            }
            if(tmpSet.size() < endSet.size()) {
                beginSet = tmpSet;
            } else {
                beginSet = endSet;
                endSet = tmpSet;
            }
        }
        return 0;
    }
};
