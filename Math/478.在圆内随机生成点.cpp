#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {
        double x = 1, y = 1;
        do {
            x = 2.0 * rand() / RAND_MAX - 1;
            y = 2.0 * rand() / RAND_MAX - 1;
        } while(x * x + y * y > 1);
        return {x_center + radius * x, y_center + radius * y};
    }

    double radius;
    double x_center;
    double y_center;
};
