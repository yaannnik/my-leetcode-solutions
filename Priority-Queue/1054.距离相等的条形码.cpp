#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int& num : barcodes) {
            mp[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(auto& p : mp) {
            pq.push(p);
        }
        while(!pq.empty()) {
            auto [num1, cnt1] = pq.top();
            pq.pop();
            // 如果num1不能用，再用第二多的num2
            if(!res.empty() && num1 == res.back()) {
                auto [num2, cnt2] = pq.top();
                pq.pop();
                res.emplace_back(num2);
                cnt2--;
                if(cnt2 > 0) {
                    pq.push({num2, cnt2});
                }
            } else { // num1能用
                res.emplace_back(num1);
                cnt1--;
            }
            if(cnt1 > 0) {
                pq.push({num1, cnt1});
            }
        }
        return res;
    }

    struct compare {
        bool operator ()(const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        }
    };
};
