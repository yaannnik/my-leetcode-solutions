#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> size2people;
        for(int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            size2people[size].emplace_back(i);
        }
        vector<vector<int>> res;
        for(auto [size, people] : size2people) {
            vector<int>::iterator it = people.begin();
            while(it != people.end()) {
                res.emplace_back(it, it + size);
                it += size;
            }
        }
        return res;
    }
};
