#include <set>
#include <utility>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        pair<int, int> event = {start, end};
        // lower_bound: first equal or larger
        auto nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }

        if (nextEvent != calendar.begin()) {
            auto prevEvent = --nextEvent;
            if (prevEvent->second > start) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }

    set<pair<int, int>> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
