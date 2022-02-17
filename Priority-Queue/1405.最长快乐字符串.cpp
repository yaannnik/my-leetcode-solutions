#include <string>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> qu;
        if(a > 0) {
            qu.push({a, 'a'});
        }
        if(b > 0) {
            qu.push({b, 'b'});
        }
        if(c > 0) {
            qu.push({c, 'c'});
        }

        string res = "";

        while(!qu.empty()) {
            // 先弹出最多的
            int cnt = qu.top().first;
            char ch = qu.top().second;
            qu.pop();

            if(res.size() > 0 && ch == res[res.size()-1]) {
                // 最多的不能用
                if(!qu.empty()) {
                    // 有第二多的，一次用一个
                    int cnt_ = qu.top().first;
                    char ch_ = qu.top().second;
                    qu.pop();
                    res += ch_;
                    cnt_--;
                    // 剩余的放回
                    if(cnt_ > 0) {
                        qu.push({cnt_, ch_});
                    }
                } else {
                    // 没有第二多的，返回结果
                    return res;
                }
            } else {
                // 最多的可以用
                res += ch;
                cnt--;
                if(cnt > 0) {
                    //最多的多于1个可以再用1个
                    res += ch;
                    cnt--;
                }
            }
            // 剩余的放回
            if(cnt > 0) {
                qu.push({cnt, ch});
            }
        }
        return res;
    }
};
