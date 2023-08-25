#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

// This is the HtmlParser's API interface.
// You should not implement it, or speculate about its implementation
class HtmlParser {
public:
    vector<string> getUrls(string url);
};


class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string head = startUrl.substr(0,startUrl.find("/", 7));

        unordered_set<string> visited;
        queue<string> qu;

        qu.push(startUrl);
        visited.insert(startUrl);
        // 队列内可能有重复，必须先去重

        vector<string> res;

        while(!qu.empty()){
            string front = qu.front();
            qu.pop();

            res.emplace_back(front);
            vector<string> links = htmlParser.getUrls(front);

            for(int i = 0; i < links.size(); i++){
                string domain = links[i].substr(0, links[i].find("/", 7));
                if(!visited.count(links[i]) && head == domain){
                    qu.push(links[i]);
                    visited.insert(links[i]);
                }
            }
        }
        return res;
    }
};
