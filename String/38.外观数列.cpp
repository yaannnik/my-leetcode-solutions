#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";

        for(int i = 2; i <= n; i++) {
            string cur = "";
            int left = 0, right = 0;
            while(right < prev.size()) {
                while(right < prev.size() && prev[left] == prev[right]) {
                    right++;
                }
                int cnt = right - left;
                cur += to_string(cnt);
                cur += prev[left];
                left = right;
            }
            prev = cur;
        }

        return prev;
    }
};
