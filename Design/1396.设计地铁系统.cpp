#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        idx2StationTime[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string start = idx2StationTime[id].first;
        string end = stationName;
        int startTime = idx2StationTime[id].second;
        int endTime = t;
        string trip = start + "-" + end;
        trip2TimeCount[trip].first += endTime - startTime;
        trip2TimeCount[trip].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        string trip = startStation + "-" + endStation;
        int time = trip2TimeCount[trip].first;
        int count = trip2TimeCount[trip].second;
        return time * 1.0 / count;
    }

    unordered_map<int, pair<string, int>> idx2StationTime;
    unordered_map<string, pair<int, int>> trip2TimeCount;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
