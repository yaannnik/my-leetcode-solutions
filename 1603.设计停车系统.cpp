/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        capacity[0] = big;
        capacity[1] = medium;
        capacity[2] = small;
    }

    vector<int> capacity = vector<int>(3);
    
    bool addCar(int carType) {
        if(carType > 3) {
            return false;
        }
        if(capacity[carType - 1] > 0) {
            capacity[carType - 1]--;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

