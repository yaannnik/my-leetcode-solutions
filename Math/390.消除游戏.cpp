using namespace std;

class Solution1 {
public:
    int lastRemaining(int n) {
        int a1 = 1;
        int k = 0, cnt = n, step = 1;
        while (cnt > 1) {
            if (k % 2 == 0) { // 正向
                a1 = a1 + step;
            } else { // 反向
                a1 = (cnt % 2 == 0) ? a1 : a1 + step;
            }
            k++;
            cnt = cnt >> 1;
            step = step << 1;
        }
        return a1;
    }
};

class Solution2 {
public:
    int lastRemaining(int n) {
        deque<int> dq;
        for(int i = 1; i <= n; i++) {
            dq.push_back(i);
        }

        int dir = 0;
        while(dq.size() > 1) {
            int l = dq.size();
            for(int i = 0; i < l; i++) {
                if(dir % 2 == 0) {
                    int p = dq.front();
                    dq.pop_front();
                    if(i % 2 == 1) {
                        dq.push_back(p);
                    }
                } else {
                    int p = dq.back();
                    dq.pop_back();
                    if(i % 2 == 1) {
                        dq.push_front(p);
                    }
                }
            }
            dir++;
        }
        return dq.front();
    }
};
