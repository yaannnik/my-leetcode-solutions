#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size()-1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            int h = citations.size() - mid;

            if(h == citations[mid]) return citations.size()-mid;
            
            if(h < citations[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return citations.size()-l;
    }
};
