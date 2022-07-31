#include <string>
using namespace std;

class Solution {
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) {
            return "";
        }
        int n = palindrome.size();

        char ch = 'a';
        string tmp;
        for(int j = 0; j < n; j++) {
            if(n % 2 == 1 && j == n / 2) {
                continue;
            }
            tmp = palindrome;
            if(tmp[j] > ch) {
                tmp[j] = ch;
                return tmp;
            }
        }
        tmp[n-1] = 'b';
        if(tmp != palindrome) {
            return tmp;
        }

        return "";
    }
};
