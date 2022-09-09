#include <string>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) {
            return 1;
        } else {
            return 2;
        }
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
