#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Map {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < words.size(); i++) {
            mp[words[i]].emplace_back(i);
        }
        if(!mp.count(word1) || !mp.count(word2)) {
            return -1;
        }
        vector<int> v1 = mp[word1], v2 = mp[word2];
        int res = words.size();
        for(int num1 : v1) {
            for(int num2 : v2) {
                res = min(res, abs(num1 - num2));
            }
        }
        return res;
    }
};

class Traverse {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1;
        int res = words.size();
        for(int i = 0; i < words.size(); i++) {
            if(words[i] == word1) {
                idx1 = i;
            }
            if(words[i] == word2) {
                idx2 = i;
            }
            if(idx1 >= 0 && idx2 >= 0) {
                res = min(res, abs(idx1 - idx2));
            }
        }
        return res;
    }
};
