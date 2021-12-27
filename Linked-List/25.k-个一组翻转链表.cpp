#include<utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pe = head;
        ListNode* dummy = new ListNode(-1), *pd = dummy;
        dummy->next = head;
        while(pe) {
            ListNode* ps = pe;
            int i = 0;
            for(; i < k && pe; i++) {
                pe = pe->next;
            }
            if(!pe && i < k) {
                pd->next = ps;
                break;
            }
            auto p = reverseGroup(ps, pe);
            pd->next = p.first;
            pd = p.second;
        }
        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverseGroup(ListNode* start, ListNode* end) {
        ListNode* H = new ListNode(-1);
        H->next = nullptr;
        ListNode* ptr = start;
        while(ptr != end) {
            ListNode* nex = ptr->next;
            ptr->next = H->next;
            H->next = ptr;
            ptr = nex;
        }
        return {H->next, start};
    }
};