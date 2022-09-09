#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countDistinct(string s) {
        unordered_set<string_view> m;
        string_view tmp, ss = s;
        int i = 0, j = 1;
        while(i < s.size()){
            for(j = i; j < s.size(); j++){
                tmp = ss.substr(i, j - i + 1);
                m.insert(tmp);
            }
            i++;
        }
        return m.size();
    }
};
