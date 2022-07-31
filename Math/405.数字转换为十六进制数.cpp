#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        unordered_map<int, char> mp = {{10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}};

        string res = "";
        for(int i = 7; i >= 0; i--) {
            int mod = (num >> (4 * i)) & 0x0f;
            if(res.empty() && mod == 0) {
                continue;
            }
            if(mod < 10) {
                res += to_string(mod);
            } else {
                res += mp[mod];
            }
        }
        return res.empty() ? "0" : res;
    }
};
