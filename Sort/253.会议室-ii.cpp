#include <vector>
#include <queue>
using namespace std;

class Solution1 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<vector<int>>> meeting_rooms = {{intervals[0]}};
        for(int i = 1; i < intervals.size(); i++) {
            bool fit = false;
            for(auto& meeting_room : meeting_rooms) {
                vector<int> last = meeting_room.back();
                if(intervals[i][0] >= last[1]) {
                    meeting_room.emplace_back(intervals[i]);
                    fit = true;
                    break;
                }
            }
            if(!fit) {
                meeting_rooms.push_back({intervals[i]});
            }
        }
        return meeting_rooms.size();
    }
};

struct cmp {
    bool operator() (int& a, int& b) {
        return a > b;
    }
};

class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        priority_queue<int, vector<int>, cmp> pq;
        for(int i = 0; i < n; i++) {
            auto interval = intervals[i];
            int left = interval[0], right = interval[1];
            if(pq.empty() || left < pq.top()) {
                pq.push(right);
            } else {
                int oldRight = pq.top();
                pq.pop();
                pq.push(right);
            }
        }
        return pq.size();
    }
};
