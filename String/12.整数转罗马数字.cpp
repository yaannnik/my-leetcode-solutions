#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<int> store = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int size = store.size();
        for(int i = 0; i < size; i++){
            while(store[i] <= num){
                res += strs[i];
                num -= store[i];
            }
        }
        return res;
    }
};
