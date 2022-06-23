#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string tmp = "[.]";
        stringstream ss(address);
        string slice = "";
        string res = "";
        while(getline(ss, slice, '.')) {
            if(res != "") {
                res += tmp;
            }
            res += slice;
        }
        return res;
    }
};
