#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        for(string& word : words) {
            st.insert(toMorse(word));
        }
        return st.size();
    }

    string toMorse(string word) {
        string res = "";
        for(char& ch : word) {
            res += morse[ch - 'a'];
        }
        return res;
    }
};
