#include <string>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int eq = equation.find('=');
        int leftx = 0, leftNum = 0;
        int rightx = 0, rightNum = 0;

        int num = 0, sign = 1;
        bool hasNum = false;
        for(int i = 0; i < eq; i++) {
            if(equation[i] == 'x') {
                if(!hasNum) {
                    leftx += sign * 1;
                } else {
                    leftx += sign * num;
                }

                num = 0;
                hasNum = false;
            } else if(equation[i] == '+' || equation[i] == '-') {
                // cout << "num: " << num << endl;
                leftNum += sign * num;
                if(equation[i] == '-') {
                    sign = -1;
                } else {
                    sign = 1;
                }

                num = 0;
                hasNum = false;
            } else {
                num = num * 10 + (equation[i] - '0');
                hasNum = true;
            }
        }
        leftNum += sign * num;

        num = 0;
        sign = 1;
        hasNum = false;
        for(int i = eq + 1; i < equation.size(); i++) {
            if(equation[i] == 'x') {
                if(!hasNum) {
                    rightx += sign * 1;
                } else {
                    rightx += sign * num;
                }

                num = 0;
                hasNum = false;
            } else if(equation[i] == '+' || equation[i] == '-') {
                // cout << "num: " << num << endl;
                rightNum += sign * num;
                if(equation[i] == '-') {
                    sign = -1;
                } else {
                    sign = 1;
                }

                num = 0;
                hasNum = false;
            } else {
                num = num * 10 + (equation[i] - '0');
                hasNum = true;
            }
        }
        rightNum += sign * num;

        int cntx = leftx - rightx;
        int cntNum = rightNum - leftNum;
        cout << cntx << "x = " << cntNum << endl;

        if(cntx == 0) {
            return cntNum == 0 ? "Infinite solutions" : "No solution";
        }


        int x = cntNum / cntx;
        string res = "x=" + to_string(x);
        return res;
    }
};
