#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        id2value[idKey] = value;
        if(!id2value.count(ptr)) {
            return res;
        } else {
            int idx = ptr;
            while(id2value.count(idx)) {
                res.emplace_back(id2value[idx]);
                idx++;
            }
            ptr = idx;
            return res;
        }
    }

    int ptr;
    unordered_map<int, string> id2value;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
