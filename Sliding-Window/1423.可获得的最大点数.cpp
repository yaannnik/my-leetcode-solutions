#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k >= cardPoints.size()) {
            return sum;
        }

        int remove = 0;
        int m = cardPoints.size() - k;
        for(int i = 0; i < m; i++) {
            remove += cardPoints[i];
        }

        int left = 0, right = m;
        int minRemove = remove;
        for(; right < cardPoints.size(); right++) {
            remove += cardPoints[right];
            remove -= cardPoints[left];
            left++;
            minRemove = min(minRemove, remove);
        }
        return sum - minRemove;
    }
};
