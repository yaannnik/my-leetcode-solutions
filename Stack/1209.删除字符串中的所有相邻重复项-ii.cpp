#include <string>
#include <stack>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<int> numStack;

        string res = "";

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(!res.empty() && ch == res.back()) {
                numStack.top()++;
                res += ch;
                if(numStack.top() == k) {
                    for(int i = 0; i < k; i++) {
                        res.pop_back();
                    }
                    numStack.pop();
                }
            } else {
                res += ch;
                numStack.push(1);
            }
        }

        return res;
    }
};

class FollowUp {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<int> cnt;
        string res = "";

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(!res.empty() && ch == res.back()) {
                res += ch;
                cnt.top()++;
                if(cnt.top() == k) {
                    for(int j = 0; j < k; j++) {
                        res.pop_back();
                    }
                    cnt.pop();
                    while(i + 1 < n && s[i + 1] == ch) {
                        i++;
                    }
                }
            } else {
                res += ch;
                cnt.push(1);
            }
        }

        return res;
    }
};
