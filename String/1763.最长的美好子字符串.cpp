#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int max = 0, n = s.size();
        string res = "";
        for(int i = 0; i < n; i++) {
            unordered_set<char> s1, s2;
            /**
             * 验证字符串s是否美好：
             * 使用s构造集合set1，使用s的全大写版构造集合set2，
             * 如果set1的长度恰好是set2的两倍，则易证s是美好字符串。
             */
            for(int j = i; j < n; j++) {
                s1.insert(s[j]);
                s2.insert(s[j] | 32); // ascii小写转大写，32取或
                if(s1.size() == 2 * s2.size() && j - i + 1 > max) {
                    max = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};
