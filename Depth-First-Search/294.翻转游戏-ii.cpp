#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool canWin(string currentState) {
        map<string, bool> mp;
        bool res = dfs(currentState, mp);
        return res;
    }

    bool dfs(string str, map<string, bool>& mp) {
        if(mp.count(str)) {
            return mp[str];
        }
        // 如果还能玩，就继续，只要有一种能赢，就返回true
        for(int i = 0; i + 1 < str.size(); i++) {
            if(str[i] == '+' && str[i+1] == '+') {
                string tmp = str;
                tmp[i] = '-';
                tmp[i+1] = '-';
                if(!dfs(tmp, mp)) {
                    mp[tmp] = false;
                    mp[str] = true;
                    return true;
                }
            }
        }
        // 没法玩，直接返回false
        mp[str] = false;
        return false;
    }
};
