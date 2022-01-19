#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num2.size();
        string res = "0";
        for(int i = 0; i < n; i++) {
            res = strAdd(res, strMultiply(num1, num2[n-i-1], i));
        }
        return res;
    }

    string strMultiply(string nums, char num, int index) {
        if(nums == "0" || num == '0') {
            return "0";
        }
        int add = 0;
        int n = nums.size();
        string res = "";
        for(int i = 0; i < nums.size(); i++) {
            res = to_string(((nums[n-i-1] - '0') * (num - '0') + add) % 10) + res;
            add = ((nums[n-i-1] - '0') * (num - '0') + add) / 10;
        }
        res = add == 0 ? res : to_string(add) + res;
        return index == 0 ? res : res + string(index, '0');
    }

    string strAdd(string num1, string num2) {
        int i = 0, j = 0;
        int m = num1.size(), n = num2.size();
        string res = "";
        int add = 0;
        while(i < m && j < n) {
            res = to_string((num1[m-i-1] - '0' + num2[n-j-1] - '0' + add) % 10) + res;
            add = (num1[m-i-1] - '0' + num2[n-j-1] - '0' + add) / 10;
            i++;
            j++;
        }
        while(i < m) {
            res = to_string((num1[m-i-1] - '0' + add) % 10) + res;
            add = (num1[m-i-1] - '0' + add) / 10;
            i++;
        }
        while(j < n) {
            res = to_string((num2[n-j-1] - '0' + add) % 10) + res;
            add = (num2[n-j-1] - '0' + add) / 10;
            j++;
        }

        res = add == 0 ? res : to_string(add) + res;
        return res;
    }
};
