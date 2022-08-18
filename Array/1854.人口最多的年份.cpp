#include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101, 0);
        for(vector<int>& log : logs) {
            int start = log[0], end = log[1] - 1;
            for(int y = start; y <= end; y++) {
                years[y-1950]++;
            }
        }
        int res = max_element(years.begin(), years.end()) - years.begin();
        return res + 1950;
    }
};
