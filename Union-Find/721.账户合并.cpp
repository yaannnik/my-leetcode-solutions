#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email2index;
        unordered_map<string, string> email2name;
        int index = 0;
        for(auto& account : accounts) {
            string name = account[0];
            for(int i = 1; i < account.size(); i++) {
                string email = account[i];
                if(!email2index.count(email)) {
                    email2index[email] = index;
                    parent.emplace_back(index);
                    index++;
                }
                email2name[email] = name;
            }
        }

        // 将每个人的账户合并
        for(auto& account : accounts) {
            string name = account[0];
            string first_email = account[1];
            int first_idx = email2index[first_email];
            for(int i = 2; i < account.size(); i++) {
                string email = account[i];
                int idx = email2index[email];
                merge(first_idx, idx);
            }
        }

        // 建root账户到所有账户的映射
        unordered_map<int, vector<string>> index2emails;
        for(auto& [email, idx] : email2index) {
            int root = find(idx);
            index2emails[root].emplace_back(email);
        }

        // 按格式生成答案
        vector<vector<string>> res;
        for(auto& [root, emails] : index2emails) {
            sort(emails.begin(), emails.end());
            vector<string> line;
            string name = email2name[emails[0]];
            line.emplace_back(name);
            for(string& email : emails) {
                line.emplace_back(email);
            }
            res.emplace_back(line);
        }
        return res;
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            if(px < py) {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        }
    }

    vector<int> parent;
};
