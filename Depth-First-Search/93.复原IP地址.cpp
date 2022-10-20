#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, "");
        return res;
    }

    void dfs(string s, int idx, string ip) {
        if(idx == s.size() && ip.size() == s.size() + 3) {
            res.push_back(ip);
            return;
        }

        string seg = "";

        for(int i = idx; i < min(idx + 3, (int)s.size()); i++) {
            seg += s[i];
            int num = stoi(seg);

            if(seg != "0" && seg[0] == '0') {
                return;
            }

            if(0 <= num && num <= 255) {
                string tmpIp = ip;
                if(tmpIp != "") {
                    tmpIp += '.';
                }
                tmpIp += seg;
                dfs(s, i + 1, tmpIp);
            }
        }
    }

    vector<string> res;
};
