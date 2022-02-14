#include <string>
using namespace std;

class Solution {
public:
    string encode(int num) {
        num += 1;
        string code = "";
        while(num > 1) {
            code = to_string(num % 2) + code;
            num >>= 1;
        }
        return code;
    }
};
