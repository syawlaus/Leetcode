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

        // �ж� n �Ľ����� 2��3��5
        if (n % 2 == 0) {
            return isUgly(n / 2);
        }

        // �ж� n �Ľ����� 3��5
        if (n % 3 == 0) {
            return isUgly(n / 3);
        }

        // �ж� n �Ľ����� 5
        if (n % 5 == 0) {
            return isUgly(n / 5);
        }

        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.isUgly(6) << endl;
    cout << sol.isUgly(8) << endl;
    cout << sol.isUgly(14) << endl;
}