#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left <= right) {
            while(left < n && !isLetter(s[left]) && !isNumber(s[left])) {
                left++;
            }
            while(right >= 0 && !isLetter(s[right]) && !isNumber(s[right])) {
                right--;
            }

            int left_idx = 0, right_idx = 0;
            if(left < n) {
                if('A' <= s[left] && s[left] <= 'Z') {
                    left_idx = s[left] - 'A';
                } else {
                    left_idx = s[left] - 'a';
                }
            }

            if(right >= 0) {
                if('A' <= s[right] && s[right] <= 'Z') {
                    right_idx = s[right] - 'A';
                } else {
                    right_idx = s[right] - 'a';
                }
            }


            if(left_idx != right_idx) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }

    bool isLetter(char& ch) {
        return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
    }

    bool isNumber(char& ch) {
        return '0' <= ch && ch <= '9';
    }
};
