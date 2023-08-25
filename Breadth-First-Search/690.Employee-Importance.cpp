#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> id2imp;
        unordered_map<int, vector<int>> id2sub;
        for(auto employee : employees) {
            id2imp[employee->id] = employee->importance;
            id2sub[employee->id] = employee->subordinates;
        }

        queue<int> qu;
        int res = 0;
        qu.emplace(id);

        while(!qu.empty()) {
            int id_ = qu.front();
            qu.pop();
            res += id2imp[id_];
            for(int sub : id2sub[id_]) {
                qu.emplace(sub);
            }
        }
        return res;
    }
};
