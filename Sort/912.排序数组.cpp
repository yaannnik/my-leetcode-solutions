#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // int n = nums.size();
        // quickSort(nums, 0, n-1);

        vector<int> tmp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, tmp);

        // heapSort(nums);

        return nums;
    }

    void quickSort(vector<int>& nums, int start, int end) {
        if(start > end) {
            return;
        }
        int i = start, j = end;
        while(i < j){
            while(nums[j] >= nums[start] && i < j) {
                j--;
            }

            while(nums[i] <= nums[start] && i < j) {
                i++;
            }

            if(i < j) {
                swap(nums[i],nums[j]);
            }

        }
        swap(nums[start], nums[i]);
        quickSort(nums, start, i - 1);
        quickSort(nums, i + 1, end);
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp) {
        // one element remaining
        if(left >= right) {
            return;
        }
        int mid = left + (right - left)/2;

        mergeSort(nums, left, mid, tmp);
        mergeSort(nums, mid + 1, right, tmp);

        int i = left, j = mid + 1, k = 0;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            tmp[k++] = nums[i++];
        }
        while(j <= right) {
            tmp[k++] = nums[j++];
        }

        for(int n = left; n <= right; n++) {
            nums[n] = tmp[n-left];
        }
    }

    void heapSort(vector<int>& nums) {
        priority_queue<int> qu;
        for(auto& num : nums) {
            qu.emplace(-num);
        }
        int i = 0;
        while(!qu.empty()) {
            int num = qu.top();
            qu.pop();
            nums[i++] = -num;
        }
    }
};

