#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:

    double EPSILON = 10e-15;

    //bool isPowerOfThree(int n) {
    //    if (n < 1) {
    //        return false;
    //    }

    //    if (n == 1) {
    //        return true;
    //    }

    //    while (n > 1) {
    //        int remainder = n % 3;
    //        if (remainder == 0) {
    //            n = n / 3;
    //        }
    //        else {
    //            return false;
    //        }
    //    }
    //    return true;
    //}

    bool isPowerOfThree2(int n) {
        double m = logbase(n, 3);
        double roundM = round(m);
        double absoluteDiff = abs(m - roundM);  // 取两者之差的绝对值
        return (absoluteDiff < EPSILON);

    }

    // log 换底公式
    double logbase(double a, double base) {
        return log(a) / log(base);
    }
};

int main() {
    Solution sol;
    cout << sol.isPowerOfThree2(1162261466) << endl;
}