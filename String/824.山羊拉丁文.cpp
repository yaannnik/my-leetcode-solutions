#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string toGoatLatin(string sentence) {
        vector<string> sv;
        stringstream ss(sentence);
        string tmp = "", res = "";
        while(getline(ss, tmp, ' ')) {
            sv.emplace_back(tmp);
        }
        for(int i = 0; i < sv.size(); i++) {
            sv[i] = helper(sv[i], i);
            res += sv[i];
            if(i != sv.size() - 1) {
                res += " ";
            }
        }
        return res;
    }

    string helper(string s, int k) {
        bool flag = vowel.count(s[0]);
        if(!flag) {
            s = s.substr(1) + s[0];
        }
        s += "ma";
        for(int i = 0; i <= k; i++) {
            s += "a";
        }
        return s;
    }
};
