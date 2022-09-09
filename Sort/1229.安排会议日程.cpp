#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int idx1 = 0, idx2 = 0;
        int n1 = slots1.size(), n2 = slots2.size();
        while(idx1 < n1 && idx2 < n2) {
            // cout << idx1 << " " << idx2 << endl;
            auto slot1 = slots1[idx1], slot2 = slots2[idx2];
            if(hasOverlapping(slot1, slot2) && calculateOverlapping(slot1, slot2) >= duration) {
                return {max(slot1[0], slot2[0]), max(slot1[0], slot2[0]) + duration};
            }
            if(slot1[1] < slot2[1]) {
                idx1++;
            } else if(slot1[1] > slot2[1]) {
                idx2++;
            } else {
                idx1++;
                idx2++;
            }
        }
        return {};
    }

    bool hasOverlapping(vector<int>& slot1, vector<int>& slot2) {
        int start1 = slot1[0], end1 = slot1[1];
        int start2 = slot2[0], end2 = slot2[1];

        if(end1 < start2 || end2 < start1) {
            return false;
        }
        return true;
    }

    int calculateOverlapping(vector<int>& slot1, vector<int>& slot2) {
        int start1 = slot1[0], end1 = slot1[1];
        int start2 = slot2[0], end2 = slot2[1];

        int start = max(start1, start2);
        int end = min(end1, end2);

        return end - start;
    }
};
