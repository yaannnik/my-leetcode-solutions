#include<string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) {
            return "0";
        }
        int lm = n - k, lt = 0;
        int left = 0;
        string res = "";
        while(lt < lm) {
            int start = left;
            int tmp = 10;
            for(int i = start; i < n - lm + lt + 1; i++) {
                if(num[i]-'0' < tmp) {
                    tmp = num[i]-'0';
                    left = i + 1;
                }
            }
            lt++;
            if(tmp == 0 && res.size() == 0) {
                continue;
            }
            res += ('0'+tmp);
        }
        return res.size() == 0 ? "0" : res;
    }
};
