#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3);
        int left = 0, right = 0;
        int n = s.size();
        int res = 0;
        while(right < n) {
            freq[s[right] - 'a']++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0 && right >= left) {
                freq[s[left] - 'a']--;
                left++;
                // (n - 1) - right + 1
                res += (n - right);
            }

            right++;
        }
        return res;
    }
};