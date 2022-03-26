#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> tmp;
        int res = 0;
        for(string& op : ops) {
            int score = 0;
            if(op != "+" && op != "C" && op != "D") {
                score = stoi(op);
                tmp.emplace_back(score);
            } else if(op == "+") {
                score = *(tmp.end()-1) + *(tmp.end()-2);
                tmp.emplace_back(score);
            } else if(op == "D") {
                score = 2 * tmp.back();
                tmp.emplace_back(score);
            } else {
                score = -tmp.back();
                tmp.erase(tmp.end()-1);
            }
            res += score;
        }
        return res;
    }
};
