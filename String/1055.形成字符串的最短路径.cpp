#include <string>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int res = 0, left = 0, right = 0;
        while(right < target.size()) {
            left = right;
            for(char& ch : source) {
                if(ch == target[right]) {
                    right++;
                }
            }
            if(left == right) {
                return -1;
            }
            res++;
        }
        return res;
    }
};
