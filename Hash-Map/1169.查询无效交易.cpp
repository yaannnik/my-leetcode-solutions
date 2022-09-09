#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Transaction {
public:
    Transaction(string info) {
        stringstream ss(info);
        string sec = "";
        vector<string> vec;
        while(getline(ss, sec, ',')) {
            vec.emplace_back(sec);
        }
        name = vec[0];
        time = atoi(vec[1].c_str());
        amount = atoi(vec[2].c_str());
        city = vec[3];
        record = info;
    }

    string name;
    int time;
    int amount;
    string city;
    string record;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        unordered_map<string, vector<Transaction>> id2transaction;

        for(string& info : transactions) {
            Transaction trans = Transaction(info);
            id2transaction[trans.name].emplace_back(trans);
        }

        for(auto [id, trans] : id2transaction) {
            int n = trans.size();
            vector<bool> valid(n, true);

            for(int i = 0; i < n; i++) {
                if(trans[i].amount > 1000) {
                    valid[i] = false;
                }
                for(int j = i + 1; j < n; j++) {
                    if(trans[i].city != trans[j].city && abs(trans[i].time - trans[j].time) <= 60) {
                        valid[i] = false;
                        valid[j] = false;
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                if(!valid[i]) {
                    res.emplace_back(trans[i].record);
                }
            }
        }
        return res;
    }
};
