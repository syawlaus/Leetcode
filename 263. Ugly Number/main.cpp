#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        // 判断 n 的素数因子乘积是否仅包含 2、3、5
        if (n % 2 == 0) {
            return isUgly(n / 2);
        }

        // 判断 n 的素数因子乘积是否仅包含 3、5
        if (n % 3 == 0) {
            return isUgly(n / 3);
        }

        // 判断 n 的素数因子乘积是否仅包含 5
        if (n % 5 == 0) {
            return isUgly(n / 5);
        }

        // n 的素数因子乘积不包含 2、3、5
        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.isUgly(6) << endl;
    cout << sol.isUgly(8) << endl;
    cout << sol.isUgly(14) << endl;
}