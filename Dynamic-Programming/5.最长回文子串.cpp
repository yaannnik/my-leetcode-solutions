#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for(int l = 1; l <= n; l++) {
            for(int i = 0; i < n; i++) {
                // s.substr(i, l);
                int j = i + l - 1;
                if(j >= n) {
                    break;
                }
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    // for l <= 3, s[i] == s[j] => s.substr(i, l) is palindrome
                    if(l <= 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        int max = 0;
        string str = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] && j - i + 1 > max) {
                    max = j - i + 1;
                    str = s.substr(i, j - i + 1);
                }
            }
        }
        return str;
    }

    string longestPalindromeExpander(string s) {
        int max = 0;
        string str = "";
        for(int i = 0; i < s.size(); i++) {
            vector<int> loc;
            loc = expander(i, i, s);
            if(loc[1] - loc[0] + 1 > max) {
                str = s.substr(loc[0], loc[1] - loc[0] + 1);
                max = loc[1] - loc[0] + 1;
            }
            if(i + 1 < s.size() && s[i] == s[i+1]) {
                loc = expander(i, i + 1, s);
                if(loc[1] - loc[0] + 1 > max) {
                    str = s.substr(loc[0], loc[1] - loc[0] + 1);
                    max = loc[1] - loc[0] + 1;
                }
            }
        }
        return str;
    }

    vector<int> expander(int left, int right, string& s) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left --;
            right++;
        }
        return {left + 1, right - 1};
    }
};