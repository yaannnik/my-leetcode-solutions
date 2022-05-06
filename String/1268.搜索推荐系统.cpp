#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        if(products.empty()) {
            return {};
        }
        sort(products.begin(), products.end());
        // cout << products[0] << endl;
        vector<vector<string>> res;
        int n = searchWord.size();
        for(int i = 0; i < n; i++) {
            vector<string> tmp;
            for(auto& s: products) {
                if(i < s.size() && s.substr(0, i+1) == searchWord.substr(0, i+1)) {
                    tmp.emplace_back(s);
                }
            }
            if(tmp.size() >= 3) {
                res.emplace_back(tmp.begin(), tmp.begin()+3);
            } else {
                res.emplace_back(tmp.begin(), tmp.end());
            }
            
        }
        return res;
    }
};
