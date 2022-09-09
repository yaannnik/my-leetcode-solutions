#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word = "";
        int res = INT_MAX;
        int idx = 1;
        while(getline(ss, word, ' ')) {
            if(word.size() >= searchWord.size() && word.substr(0, searchWord.size()) == searchWord) {
                res = min(res, idx);
            }
            idx++;
        }
        return res == INT_MAX ? -1 : res;
    }
};
