#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        for(char& ch : s) {
            freq[ch - 'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(freq[ch - 'a'] == 1) {
                return i;;
            }
        }
        return -1;
    }
};
