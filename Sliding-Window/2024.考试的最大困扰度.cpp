#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> mp;
        int left = 0, res = 0;
        for(int right = 0; right < answerKey.size(); right++) {
            mp[answerKey[right]]++;
            while(min(mp['T'], mp['F']) > k) {
                mp[answerKey[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
