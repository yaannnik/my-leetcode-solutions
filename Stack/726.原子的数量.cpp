#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.size();

        auto getElement = [&]() -> string {
            string element = "";
            element += formula[i];
            i++;
            while(i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                element += formula[i];
                i++;
            }
            return element;
        };

        auto getNum = [&]() -> int {
            if(i == n || formula[i] < '0' || formula[i] > '9') {
                return 1;
            }
            int num = 0;
            while(i < n && formula[i] >= '0' && formula[i] <= '9') {
                num = num * 10 + (formula[i] - '0');
                i++;
            }
            return num;
        };

        stack<unordered_map<string, int>> st;
        st.push({});
        while(i < n) {
            char ch = formula[i];
            if(ch == '(') {
                i++;
                st.push({});
            } else if(ch == ')') {
                i++;
                int num = getNum();
                auto eleNum = st.top();
                st.pop();
                for(auto& [ele, v] : eleNum) {
                    st.top()[ele] += num * v;
                }
            } else {
                string ele = getElement();
                int num = getNum();
                st.top()[ele] += num;
            }
        }

        auto& eleNum = st.top();
        vector<pair<string, int>> pairs;
        for(auto& [ele, v] : eleNum) {
            pairs.emplace_back(ele, v);
        }
        sort(pairs.begin(), pairs.end());

        string res = "";
        for(auto& p : pairs) {
            res += p.first;
            if(p.second > 1) {
                res += to_string(p.second);
            }
        }
        return res;
    }
};
