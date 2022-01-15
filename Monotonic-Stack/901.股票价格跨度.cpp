#include<vector>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        if(last == price) {
            st.emplace_back(price);
            cnt++;
            return cnt;
        }
        cnt = 1;
        int pivot = st.size()-1;
        while(pivot >= 0 && st[pivot] <= price) {
            pivot--;
            cnt++;
        }
        st.emplace_back(price);
        last = price;
        return cnt;
    }

    vector<int> st;
    int cnt;
    int last;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
