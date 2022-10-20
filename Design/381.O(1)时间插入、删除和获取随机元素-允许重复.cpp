#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedCollection {
public:
    RandomizedCollection() {
        size = 0;
    }

    bool insert(int val) {
        nums.emplace_back(val);
        num2Indexes[val].insert(size);
        size++;
        return num2Indexes[val].size() == 1;
    }

    bool remove(int val) {
        if(!num2Indexes.count(val)) {
            return false;
        }

        if(val == nums.back()) {
            num2Indexes[val].erase(size - 1);
            nums.pop_back();
        } else {
            int idx = *num2Indexes[val].begin();
            nums[idx] = nums.back();
            num2Indexes[val].erase(idx);

            num2Indexes[nums.back()].erase(size - 1);
            num2Indexes[nums.back()].insert(idx);
            nums.pop_back();
        }
        if(num2Indexes[val].size() == 0) {
            num2Indexes.erase(val);
        }
        size--;
        return true;
    }

    int getRandom() {
        return nums[rand() % size];
    }

    unordered_map<int, unordered_set<int>> num2Indexes;
    vector<int> nums;
    int size;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
