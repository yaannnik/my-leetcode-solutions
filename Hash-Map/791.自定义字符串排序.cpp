#include<unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        for(int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&](char& a, char& b) {
            return mp[a] < mp[b];
        });
        return s;
    }

    unordered_map<char, int> mp;
};
