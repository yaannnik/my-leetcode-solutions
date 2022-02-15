#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mp;
        for(auto& path : paths) {
            stringstream ss(path);
            string sys = "", file = "";
            while(getline(ss, file, ' ')) {
                if(sys == "") {
                    sys = file;
                } else {
                    int left = file.find('('), right = file.find(')');
                    string name = file.substr(0, left);
                    string content = file.substr(left + 1, right - left - 1);
                    mp[content].emplace_back(sys + "/" + name);
                }
            }
        }
        vector<vector<string>> res;
        for(auto& [content, files] : mp) {
            if(files.size() > 1) {
                res.emplace_back(files);
            }
        }
        return res;
    }
};
