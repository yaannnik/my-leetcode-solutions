#include <limits.h>
using namespace std;

class ArrayReader {
  public:
    int get(int index);
};

class Solution {
public:
    int search(ArrayReader& reader, int target) {
        int i = 0, j = 10000;
        while(i <= j) {
            int mid = i + (j-i)/2;
            //j停留在INT_MAX的前一个
            if(reader.get(mid) == INT_MAX) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        int left = 0, right = j;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(reader.get(mid) == target) {
                return mid;
            }
            if(reader.get(mid) < target) {
                left = mid + 1;
            }
            if(reader.get(mid) > target) {
                right = mid - 1;
            }
        }
        return -1;
    }
};
