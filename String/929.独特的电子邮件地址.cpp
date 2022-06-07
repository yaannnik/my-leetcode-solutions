#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> address;
        for(string& email : emails) {
            string tmp = validAddress(email);
            address.insert(tmp);
        }
        return address.size();
    }

    string validAddress(string& email) {
        int at = email.find("@");
        string local = email.substr(0, at);
        string field = email.substr(at + 1);
        // cout << local << " " << field << endl;

        // local
        string local_ = "";
        for(char& ch : local) {
            if(ch == '+') {
                break;
            }
            if(ch == '.') {
                continue;
            }
            local_ += ch;
        }

        string valid_address = "";
        valid_address += local_;
        valid_address += "@";
        valid_address += field;
        // cout << valid_address << endl;
        return valid_address;
    }
};
