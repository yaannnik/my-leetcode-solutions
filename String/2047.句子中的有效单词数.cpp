#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        int left = -1, right = 0;
        int res = 0;
        int n = sentence.size();
        while(left < n && right < n) {
            if((right == 0 && sentence[right] != ' ') || (right > 0 && sentence[right-1] == ' ' && sentence[right] != ' ')) {
                left = right;
            } else if(right > 0 && sentence[right-1] != ' ' && sentence[right] == ' ') {
                if(validWord(sentence.substr(left, right - left))) {
                    res++;
                }
                left = -1;
            }
            right++;
        }

        if(left != -1 && validWord(sentence.substr(left))) {
            res++;
        }
        return res;
    }

    bool validWord(string s) {
        unordered_set<char> set = {',', '.', '!'};
        int hypen = 1, n = s.size();
        for(int i = 0; i < n; i++) {
            if(isLetter(s[i])) {
                continue;
            } else if(set.count(s[i]) && i == n - 1) {
                continue;
            } else if(s[i] == '-' && hypen > 0 && i > 0 && i < n - 1 && isLetter(s[i-1]) && isLetter(s[i+1])) {
                hypen--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
};
