#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        while (n > 1) {
            if (isOdd(n)) {
                return false;
            }
            int m = n / 2;
            if (isOdd(m)) {
                return m == 1;
            }
            else {
                n = m;
            }
        }

        return false;
    }

    bool isOdd(int n) {
        return (n % 2 != 0);
    }
};

int main() {
    Solution sol;
    cout << sol.isPowerOfTwo(0) << endl;
    cout << sol.isPowerOfTwo(1) << endl;
    cout << sol.isPowerOfTwo(2) << endl;
    cout << sol.isPowerOfTwo(3) << endl;
    cout << sol.isPowerOfTwo(4) << endl;
    cout << sol.isPowerOfTwo(5) << endl;
}