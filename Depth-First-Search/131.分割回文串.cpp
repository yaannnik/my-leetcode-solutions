#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        dfs(s, 0, s.size()-1, tmp);
        return res;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void dfs(string s, int start, int end, vector<string>& tmp) {
        if(start > end) {
            res.emplace_back(tmp);
            return;
        }

        for(int i = 1; i <= end - start + 1; i++) {
            if(isPalindrome(s.substr(start, i))) {
                tmp.emplace_back(s.substr(start, i));
                dfs(s, start+i, end, tmp);
                tmp.erase(tmp.end()-1);
            }
        }
    }
};
