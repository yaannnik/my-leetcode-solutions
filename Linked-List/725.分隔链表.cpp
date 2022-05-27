#include "ListNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        if(!head) {
            return res;
        }

        int len = 0;
        ListNode* ptr = head;
        while(ptr) {
            len++;
            ptr = ptr->next;
        }

        int part = 0;
        vector<int> parts(k, 0);
        for(int i = 0; i < len % k; i++) {
            parts[i] = 1;
        }
        if(len >= k) {
            for(int i = 0; i < k; i++) {
                parts[i] += len / k;
            }
        }

        ListNode* dummy = new ListNode(-1, head);
        ListNode *slow = dummy, *fast = dummy;

        for(int i = 0; i < k; i++) {
            if(slow->next) {
                cout << slow->next->val << endl;
            }
            int part = parts[i];
            for(int j = 0; j < part; j++) {
                fast = fast->next;
            }
            if(slow->next) {
                cout << slow->next << endl;
            }

            res[i] = slow->next;

            dummy->next = fast->next;
            fast->next = nullptr;

            slow = dummy;
            fast = slow;

        }

        return res;
    }
};
