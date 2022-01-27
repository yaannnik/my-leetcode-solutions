#include <string>
#include <unordered_map>
using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        duration = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }

    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId) && mp[tokenId] + duration > currentTime) {
            mp[tokenId] = currentTime;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;

        for(auto& p : mp) {
            if(p.second + duration > currentTime) {
                cnt++;
            }
        }

        return cnt;
    }

    int duration = 0;
    unordered_map<string, int> mp;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
