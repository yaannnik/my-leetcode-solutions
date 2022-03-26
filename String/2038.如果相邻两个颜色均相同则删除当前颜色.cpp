#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int> cnts(2, 0);
        char ptr = 'C';
        int cnt = 0;
        for(char& ch : colors) {
            if(ptr != ch) {
                ptr = ch;
                cnt = 1;
            } else {
                cnt++;
                if(cnt >= 3) {
                    cnts[ch-'A']++;
                }
            }
        }
        return cnts[0] > cnts[1];
    }
};

