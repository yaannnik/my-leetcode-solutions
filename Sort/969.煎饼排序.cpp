#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();

        while(n > 1) {
            auto max = max_element(arr.begin(), arr.begin()+n);
            // cout << *max << endl;

            int idx = max - arr.begin();

            if(idx+1 == n) {
                n--;
                continue;
            }

            if(idx == 0) {
                res.emplace_back(n);
                reverse(arr.begin(), arr.begin()+n);
                n--;
                continue;
            }

            res.emplace_back(idx+1);
            reverse(arr.begin(), max+1);

            res.emplace_back(n);
            reverse(arr.begin(), arr.begin()+n);

            n--;
        }
        return res;
    }
};