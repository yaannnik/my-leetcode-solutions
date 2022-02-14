#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        vector<char> balloon = {'b', 'a', 'l', 'o', 'n'};
        for(char& ch : text) {
            mp[ch]++;
        }
        int res = INT_MAX;
        for(char& ch : balloon) {
            if(ch == 'l' || ch == 'o') {
                res = min(res, mp[ch]/2);
            } else {
                res = min(res, mp[ch]);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
