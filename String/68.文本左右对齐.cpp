#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int left = 0, right = 0;
        int tmp = 0;
        while(right < words.size()) {
            if(tmp + words[right].size() > maxWidth) {
                right--;
                //"a   b   c"
                // space num == words num - 1
                string line = "";
                if(right == left) {
                    // only one word
                    line = words[left];
                    while(line.size() < maxWidth) {
                        line += " ";
                    }
                } else {
                    // more than one word
                    int space_cnt = right - left; // number of total spaces, equals to number of words - 1
                    int space_len = maxWidth - tmp + space_cnt + 1; // number of total " "s

                    int len_space = space_len / space_cnt; // how many " " in each space
                    int extra_space = space_len % space_cnt; // how many spaces need extra one " "

                    for(int i = left; i <= right; i++) {
                        line += words[i];
                        if(i != right) {
                            for(int j = 0; j < len_space; j++) {
                                line += " ";
                            }
                            if(extra_space > 0) {
                                line += " ";
                                extra_space--;
                            }
                        }
                    }
                }
                res.emplace_back(line);

                left = right + 1;
                tmp = 0;
            }
            else if(tmp + words[right].size() == maxWidth) {
                // "a b c"
                string line = "";
                for(int i = left; i <= right; i++) {
                    line += words[i];
                    if(i != right) {
                        line += " ";
                    }
                }
                res.emplace_back(line);
                left = right+1;
                tmp = 0;
            }
            else {
                tmp += words[right].size() + 1;
            }
            right++;
        }

        if(left < words.size()) {
            string line = "";
            for(int i = left; i <= words.size() - 1; i++) {
                line += words[i];
                if(i != words.size() - 1 && line.size() < maxWidth) {
                    line += " ";
                }
            }
            while(line.size() < maxWidth) {
                line += " ";
            }
            res.emplace_back(line);
        }

        return res;
    }
};
