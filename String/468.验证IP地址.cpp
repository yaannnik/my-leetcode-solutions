#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.size() > 39 || !isalnum(queryIP.back()))
        {
            return "Neither";
        }
        for(int i = 1; i < 5; i++){
            if(queryIP[i] == '.') {
                return checkIpV4(queryIP);
            }
            if(queryIP[i] == ':') {
                return checkIpV6(queryIP);
            }
        }
        return "Neither";
    }

    string checkIpV4(string& ip) {
        stringstream in(ip);
        for(int i = 0; i < 4; i++) {
            string piece;
            getline(in, piece, '.');
            if(piece.size() < 1 || piece.size() > 3) {
                return "Neither";
            }
            for(auto& e : piece) {
                if(!isdigit(e)) {
                    return "Neither";
                }
            }
            if(stoi(piece) > 255 || (piece.size() > 1 && piece.front() == '0')) {
                return "Neither";
            }
        }
        return in.eof() ? "IPv4" : "Neither";
    }

    string checkIpV6(string& ip){
        stringstream in(ip);
        for(int i=0;i < 8; i++){
            string piece;
            getline(in,piece,':');
            if(piece.size() < 1 || piece.size() > 4) {
                return "Neither";
            }
            for(auto& e : piece) {
                if(!isalnum(e) || (isalpha(e) && tolower(e) > 'f')) {
                    return "Neither";
                }
            }
        }
        return in.eof() ? "IPv6" : "Neither";
    }
};
