#include <vector>
using namespace std;

class Solution {
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
