#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for(auto& word : words) {
            if(helper(s, word)) {
                res++;
            }
        }
        return res;
    }

    bool helper(string& s, string& word) {
        int i = 0, j = 0;
        int cnts = 1, cntw = 1;
        while(i < s.size() && j < word.size()) {
            // if new letter different, wrong
            if(s[i] != word[j]) {
                return false;
            }
            // count number of continous same letter
            while(i + 1 < s.size() && s[i+1] == s[i]) {
                i++;
                cnts++;
            }
            while(j + 1 < word.size() && word[j+1] == word[j]) {
                j++;
                cntw++;
            }
            // if cnts < cntw or cnts > cntw but cnts < 3, wrong
            if((cnts > cntw && cnts < 3) ||  cnts < cntw) {
                return false;
            }
            // move to next different letter
            cnts = 1;
            cntw = 1;
            i++;
            j++;
        }
        // if one still have letters remaining, wrong
        if(i < s.size() || j < word.size()) {
            return false;
        }
        return true;
    }
};
