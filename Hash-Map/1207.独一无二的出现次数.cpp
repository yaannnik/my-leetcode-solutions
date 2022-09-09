#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        for(int& num : arr) {
            numFreqs[num]++;
        }
        for(auto& [num, freq] : numFreqs) {
            if(!freqs.count(freq)) {
                freqs.insert(freq);
            } else {
                return false;
            }
        }
        return true;
    }

    unordered_map<int, int> numFreqs;
    unordered_set<int> freqs;
};
