#include <math.h>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    Solution(ListNode* head) {
        h = head;
    }

    int getRandom() {
        ListNode* ptr = h;
        int res = ptr->val;
        ptr = ptr->next;
        int i = 1, m = 1;
        /**
         * https://www.jianshu.com/p/7a9ea6ece2af
         * 如果接收的数据量小于m，则依次放入蓄水池。
         * 当接收到第i个数据时，i >= m，在[0, i]范围内取以随机数d，若d的落在[0, m-1]范围内，则用接收到的第i个数据替换蓄水池中的第d个数据。
         * 重复步骤2。
         */
        while(ptr) {
            i++;
            // r in [0, i-1]
            int r = rand() % i;
            // if r < m, put into reservior
            if(r < m) {
                res = ptr->val;
            }
            ptr = ptr->next;
        }
        return res;
    }

    ListNode* h;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
