#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> mp;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            if(!valid(words[i], words[i+1])) {
                return false;
            }
        }
        return true;
    }

    bool valid(string first, string second) {
        int n = min(first.size(), second.size());
        int i = 0;
        while(first[i] == second[i]) {
            i++;
        }
        if(i == n) {
            return first.size() < second.size();
        }
        return mp[first[i]] <= mp[second[i]];
    }
};
