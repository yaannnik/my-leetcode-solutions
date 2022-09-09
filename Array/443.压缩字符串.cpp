#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int w = 0, n = chars.size();
        int cnt = 1;
        char prev = chars[0];
        for(int i = 1; i < n; i++) {
            if(chars[i] == prev) {
                cnt++;
            } else {
                chars[w++] = prev;
                if(cnt > 1) {
                    for(char& s : to_string(cnt)) {
                        chars[w++] = s;
                    }
                }


                prev = chars[i];
                cnt = 1;
            }
        }

        chars[w++] = prev;
        if(cnt > 1) {
            for(char& s : to_string(cnt)) {
                chars[w++] = s;
            }
        }

        return w;
    }
};
