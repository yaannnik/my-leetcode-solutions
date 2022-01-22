#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        int zero  = count(s.begin(), s.end(), 'z');
        int two   = count(s.begin(), s.end(), 'w');
        int six   = count(s.begin(), s.end(), 'x');
        int eight = count(s.begin(), s.end(), 'g');
        int seven = count(s.begin(), s.end(), 's') - six;
        int five  = count(s.begin(), s.end(), 'v') - seven;
        int four  = count(s.begin(), s.end(), 'f') - five;
        int three = count(s.begin(), s.end(), 't') - two - eight;
        int one   = count(s.begin(), s.end(), 'o') - zero - two - four;
        int nine  = count(s.begin(), s.end(), 'i') - five - six - eight;

        vector<int> cnt = {zero, one, two, three, four, five, six, seven, eight, nine};
        string res = "";
        for(int i = 0; i < cnt.size(); i++) {
            if(cnt[i] > 0) {
                for(int j = 0; j < cnt[i]; j++) {
                    res += '0' + i;
                }
            }
        }
        return res;
    }
};
