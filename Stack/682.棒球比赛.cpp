#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> record;
        int res = 0;
        for(string& op : ops) {
            if(op == "C") {
                int c = record.top();
                record.pop();
                res -= c;
            } else if(op =="D") {
                int d = record.top();
                record.push(d * 2);
                res += (d * 2);
            } else if(op == "+") {
                int x = record.top();
                record.pop();
                int y = record.top();
                record.push(x);
                record.push(x + y);
                res += (x + y);
            } else {
                int s = atoi(op.c_str());
                record.push(s);
                res += s;
            }
        }
        return res;
    }
};
