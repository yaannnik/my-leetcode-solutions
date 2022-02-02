#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.find(ch) == word.npos) {
            return word;
        }
        int i = 0;
        for(; i < word.size(); i++) {
            if(word[i] == ch) {
                break;
            }
        }
        for(int j = 0; j < (i + 1) / 2; j++) {
            swap(word[j], word[i-j]);
        }
        return word;
    }
};
