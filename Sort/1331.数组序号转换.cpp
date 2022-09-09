#include <vector>
#include <numeric>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int prev = INT_MIN;
        int rank = 0;
        int n = arr.size();
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        // 将数组序号排序
        sort(indexes.begin(), indexes.end(), [&](int& a, int& b) {
            return arr[a] < arr[b];
        });
        // for(int& index : indexes) {
        //     cout << index << " ";
        // }
        vector<int> res(n);
        for(int& index : indexes) {
            if(arr[index] > prev) {
                prev = arr[index];
                rank++;
            }
            res[index] = rank;
        }
        return res;
    }
};

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

class Solution1 {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i = 0; i < n; i++) {
            pq.emplace(arr[i], i);
        }
        vector<int> res(n);
        int rank = 0;
        int prev = INT_MIN;
        while(!pq.empty()) {
            auto [num, index] = pq.top();
            pq.pop();

            if(num > prev) {
                prev = num;
                rank++;
            }
            res[index] = rank;
        }
        return res;
    }
};
