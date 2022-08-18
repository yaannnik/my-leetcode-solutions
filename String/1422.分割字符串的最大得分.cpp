#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zerosFromLeft(n), onesFromRight(n);
        zerosFromLeft[0] = s[0] == '0';
        onesFromRight[n - 1] = s[n - 1] == '1';
        for(int i = 1; i < n; i++) {
            zerosFromLeft[i] = zerosFromLeft[i - 1] + (s[i] == '0');
            onesFromRight[n - 1 - i] = onesFromRight[n - i] + (s[n - 1 - i] == '1');
        }
        int score = 0;
        for(int cut = 0; cut < n - 1; cut++) {
            score = max(score, zerosFromLeft[cut] + onesFromRight[cut+1]);
        }
        return score;
    }
};
