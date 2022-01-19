#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int, int> in;
        unordered_map<int, set<int>> edges;
        for(auto& num : nums) {
            in[num] = 0;
            edges[num] = {};
        }
        for(auto& s : sequences) {
            for(int i = 0; i < s.size()-1; i++) {
                if(edges[s[i]].find(s[i+1]) == edges[s[i]].end()) {
                    in[s[i+1]]++;
                    edges[s[i]].insert(s[i+1]);
                }
            }
        }

        queue<int> qu;
        for(auto& i : in) {
            if(i.second == 0) {
                qu.push(i.first);
            }
        }
        vector<int> res;
        while(!qu.empty()) {
            if(qu.size() > 1) {
                return false;
            }
            int front = qu.front();
            qu.pop();
            res.emplace_back(front);

            if(res.back() != nums[res.size()-1]) {
                return false;
            }

            for(auto& target : edges[front]) {
                in[target]--;
                if(in[target] == 0) {
                    qu.push(target);
                }
            }
        }
        return true;
    }
};
