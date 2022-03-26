#include <string>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        if(instructions.size() == 0) {
            return false;
        }
        vector<char> directs = {'N', 'E', 'S', 'W'};
        pair<int, int> pos = {0, 0};
        int d = 0;
        for(auto& i: instructions) {
            if(i == 'G') {
                switch(directs[d]) {
                    case 'N':
                        pos.second++;
                        break;
                    case 'E':
                        pos.first++;
                        break;
                    case 'S':
                        pos.second--;
                        break;
                    case 'W':
                        pos.first--;
                        break;
                }
            }
            if(i == 'R') {
                if(d == 3) {
                    d = 0;
                } else {
                    d++;
                }
            }
            if(i == 'L') {
                if(d == 0) {
                    d = 3;
                } else {
                    d--;
                }
            }
        }
        if(pos == pair<int, int>(0, 0)){
            return true;
        }
        return d != 0;
    }
};
