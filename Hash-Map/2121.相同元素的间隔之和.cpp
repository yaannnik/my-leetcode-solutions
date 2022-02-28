#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> res(n);
        map<int, long long> sum;
        map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            if(cnt.count(arr[i])) {
                res[i] += abs((long long)i * cnt[arr[i]] - sum[arr[i]]);
            }
            sum[arr[i]] += i;
            cnt[arr[i]]++;
        }

        sum.clear();
        cnt.clear();
        for(int i = n - 1; i >= 0; i--) {
            if(cnt.count(arr[i])) {
                res[i] += abs((long long)i * cnt[arr[i]] - sum[arr[i]]);
            }
            sum[arr[i]] += i;
            cnt[arr[i]]++;
        }
        return res;
    }
};
