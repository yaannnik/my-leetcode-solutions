#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            if(ch == '+' || ch == '-' || ch == '*') {
                auto res1 = diffWaysToCompute(expression.substr(0, i));
                auto res2 = diffWaysToCompute(expression.substr(i + 1));
                for(int& r1 : res1) {
                    for(int& r2 : res2) {
                        if(ch == '+') {
                            res.push_back(r1 + r2);
                        } else if(ch == '-') {
                            res.push_back(r1 - r2);
                        } else {
                            res.push_back(r1 * r2);
                        }
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};
