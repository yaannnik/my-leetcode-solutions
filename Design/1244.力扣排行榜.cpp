#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct cmp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Leaderboard {
public:
    Leaderboard() {
        players = vector<int>(10000, 0);
    }

    void addScore(int playerId, int score) {
        players[playerId] += score;
    }

    int top(int K) {
        vector<int> tmp = players;
        sort(tmp.begin(), tmp.end(), [&](int& a, int& b) {
            return a > b;
        });
        int score = 0;
        for(int i = 0; i < K; i++) {
            score += tmp[i];
        }
        return score;
    }

    void reset(int playerId) {
        players[playerId] = 0;
    }

    vector<int> players;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

class Leaderboard1 {
public:
    Leaderboard1() {

    }

    void addScore(int playerId, int score) {
        if(id2score.count(playerId)) {
            int score_ = id2score[playerId];
            scoreId.erase({-score_, playerId});
        }
        id2score[playerId] += score;
        scoreId.insert({-id2score[playerId], playerId});
    }

    int top(int K) {
        int sum = 0, cnt = 0;
        for(auto& [score, _] : scoreId) {
            sum -= score;
            cnt++;
            if(cnt == K) {
                break;
            }
        }
        return sum;
    }

    void reset(int playerId) {
        scoreId.erase({-id2score[playerId], playerId});
        id2score.erase(playerId);
    }

    unordered_map<int, int> id2score;
    set<pair<int, int>> scoreId;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */