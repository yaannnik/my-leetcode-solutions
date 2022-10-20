#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word = "";
        int length = 0;
        while(getline(ss, word, ' ')) {
            if(word.size() > 0) {
                length = word.size();
            }
        }
        return length;
    }
};
