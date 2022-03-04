#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool IsOperator(const string& s) const
    {
        return s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")";
    }

    int Priority(const string& s) const
    {
        if (s == "*" || s == "/")
        {
            return 1;
        }
        else if (s == "+" || s == "-")
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

public:
    int calculate(string s) {
        vector<string> infix;
        StrToVector(s, infix);
        // for (string& i : infix)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        stack<string> s1;
        InfixToSuffix(infix, s1);
        stack<long> res;
        while (!s1.empty())
        {
            // cout << "curr " << s1.top() << endl;
            if (!IsOperator(s1.top()))
            {
                res.push(stol(s1.top()));
            }
            else
            {
                long num2 = res.top();
                res.pop();
                long num1 = res.top();
                res.pop();
                long temp = 0;
                if (s1.top() == "+")
                {
                    temp = num1 + num2;
                }
                else if (s1.top() == "-")
                {
                    temp = num1 - num2;
                }
                else if (s1.top() == "*")
                {
                    temp = num1 * num2;
                }
                else
                {
                    temp = num1 / num2;
                }
                res.push(temp);
                // cout << num1 << s1.top() << num2 << " into " << temp <<" res.top() " << res.top() << endl;
            }
            s1.pop();
        }
        // cout << endl;

        return res.top();
    }

    // 需要忽略空格
    void StrToVector(const string& s, vector<string>& infix)
    {
        int n = s.size();
        string num = "";
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (i < n-1 && s[i+1] >= '0' && s[i+1] <= '9')
                {
                    num += s[i];
                }
                else
                {
                    num += s[i];
                    infix.push_back(num);
                    num.clear();
                }
            }
            else
            {
                string op = "";
                op += s[i];
                infix.emplace_back(op);
            }
        }
    }

    void InfixToSuffix(const vector<string>& infix, stack<string>& s1)
    {
        stack<string> s2;
        int n = infix.size();
        for (int i = 0; i < n; ++i)
        {
            if (IsOperator(infix[i]))
            {
                if (s1.empty() || infix[i] == "(")
                {
                    s1.push(infix[i]);
                }
                else
                {
                    if (infix[i] != ")")
                    {
                        // 优先级判断
                        while (!s1.empty() && Priority(s1.top()) >= Priority(infix[i]))
                        {
                            s2.push(s1.top());
                            s1.pop();
                        }
                        // 这里肯定是大于优先级了，所以入s2
                        s1.push(infix[i]);
                    }
                    else
                    {
                        // 遇到 ）
                        while ( !s1.empty() && s1.top() != "(")
                        {
                            s2.push(s1.top());
                            s1.pop();
                        }
                        // 弹出 s1的 (
                        s1.pop();
                    }
                }
            }
            else
            {
                s2.push(infix[i]);
            }
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // cout << "s2 pop ";
        while (!s2.empty())
        {
            // cout << s2.top() << " ";
            s1.push(s2.top());
            s2.pop();
        }
        // cout << endl;
    }
};
