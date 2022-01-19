#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        if(s1 == s2 || (s2.size() == 1 && s1.find(s2[0]) != string::npos)) {
            return s2;
        }
        int start = 0, end = s1.size()-1;
        int p1 = 0, p2 = 0;
        while(p1 < s1.size()) {
            if(s1[p1] == s2[p2]) {
                p2++;
            }
            if(p2 == s2.size()) {
                int right = p1; // 记下当前子序列尾的位置
                p2--; // 向前还原一步，p2在s2最后一个
                while(p2 >= 0) {
                    if(s1[p1] == s2[p2]) {
                        p2--;
                    }
                    p1--;
                }
                p1++;
                if(right - p1 + 1 < end - start + 1) {
                    start = p1;
                    end = right;
                }
                p2 = 0;
            }
            p1++;
        }
        return end - start + 1 == s1.size() ? "" : s1.substr(start, end - start + 1);
    }
};
