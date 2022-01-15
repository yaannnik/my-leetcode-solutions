#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * We can use a stack that stores nodes in monotone decreasing order of value.
 * When we see a node_j with a larger value, every node_i in the stack has next_larger(node_i) = node_j .
 */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int n = listLen(head);
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        ListNode* ptr = head;
        int cnt = 0;
        while(ptr) {
            while(!st.empty() && ptr->val > st.top().second) {
                res[st.top().first] = ptr->val;
                st.pop();
            }
            st.push(pair<int,int>(cnt, ptr->val));
            cnt++;
            ptr = ptr->next;
        }
        return res;
    }

    int listLen(ListNode* head) {
        ListNode* ptr = head;
        int len = 0;
        while(ptr) {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
};
