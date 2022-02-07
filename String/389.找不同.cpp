#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> mark(26, 0);
        for(char& ch : t) {
            mark[ch-'a']++;
        }
        for(char& ch : s) {
            mark[ch-'a']--;
        }
        char ch = max_element(mark.begin(), mark.end()) - mark.begin() + 'a';
        return ch;
    }
};
