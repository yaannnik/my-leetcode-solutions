#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string& op : operations) {
            if(op[1] == '+') {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};
