#include <string>
#include <deque>
using namespace std;

class Solution1 {
    // 寻找每一位可能存在的区间内的最小值
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

class Solution2 {
    // 维护一个单调增栈，这样可以保证每一位都是相邻几个数中的最小
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        for(char& ch : num) {
            while(!dq.empty() && ch < dq.back() && k > 0) {
                dq.pop_back();
                k--;
            }
            dq.push_back(ch);
        }

        while(k > 0) {
            k--;
            dq.pop_back();
        }

        string res = "";
        while(!dq.empty()) {
            char ch = dq.front();
            dq.pop_front();
            if(res == "" && ch == '0') {
                continue;
            }
            res += ch;
        }
        return res.size() == 0 ? "0" : res;
    }
};
