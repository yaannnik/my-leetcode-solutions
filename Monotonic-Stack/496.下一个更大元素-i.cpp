#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }
        vector<int> res(nums1.size(), -1);
        int i = 0;
        stack<int> st;
        while(i < nums2.size()) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                int top = st.top();
                st.pop();
                if(mp.find(nums2[top]) != mp.end()) {
                    int idx = mp[nums2[top]];
                    res[idx] = nums2[i];
                }
            }
            st.push(i);
            i++;
        }
        return res;
    }
};
