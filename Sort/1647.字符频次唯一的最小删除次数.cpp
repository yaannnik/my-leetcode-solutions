#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    int minDeletions(string s) {
        vector<int> freqs(26);
        for(char& ch : s) {
            freqs[ch - 'a']++;
        }
        sort(freqs.begin(), freqs.end(), [&](int& a, int& b) {
            return a > b;
        });

        int mostFreq = freqs[0] - 1;
        int res = 0;
        for(int i = 1; i < 26; i++) {
            if(freqs[i] > mostFreq) {
                res += freqs[i] - mostFreq;
                freqs[i] = mostFreq;
            }
            mostFreq = max(0, freqs[i] - 1);
        }
        return res;
    }
};

class Solution2 {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char& ch : s) {
            mp[ch]++;
        }
        sort(s.begin(), s.end(), [&](char& a, char& b) {
            return a == b ? mp[a] < mp[b] : a < b;
        });

        int res = 0;
        unordered_set<int> uniqueFreqs;
        // cout << s << endl;
        for(int i = 0; i < s.size(); i++) {
            while(i > 0 && s[i] == s[i-1]) {
                i++;
            }
            int freq = mp[s[i]];
            while(uniqueFreqs.count(freq)) {
                freq--;
                res++;
            }
            if(freq != 0) {
                uniqueFreqs.insert(freq);
            }
        }
        return res;
    }
};
