#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n - 1 < ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string &word: words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            for (int start = i; start + m * n - 1 < ls; start += n) {
                if (start != i) {
                    string added = s.substr(start + (m - 1) * n, n);
                    if (++differ[added] == 0) {
                        differ.erase(added);
                    }
                    string removed = s.substr(start - n, n);
                    if (--differ[removed] == 0) {
                        differ.erase(removed);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};

