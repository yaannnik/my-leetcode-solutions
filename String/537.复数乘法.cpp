#include <string>
#include <utility>
#include <sstream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto [r1, i1] = split(num1);
        auto [r2, i2] = split(num2);
        int rr1 = atoi(r1.c_str()), ii1 = atoi(i1.c_str());
        int rr2 = atoi(r2.c_str()), ii2 = atoi(i2.c_str());
        int rr = (rr1 * rr2) - (ii1 * ii2);
        int ii = (rr1 * ii2) + (rr2 * ii1);
        // cout << rr1 << ", " << ii1 << endl;
        return to_string(rr) + "+" + to_string(ii) + "i";
    }

    pair<string, string> split(string s) {
        stringstream ss(s);
        string r = "", i = "";
        while(getline(ss, i, '+')) {
            if(r == "") {
                r = i;
            }
        }
        i = i.substr(0, i.size()-1);
        return {r, i};
    }
};
