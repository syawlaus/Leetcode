#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        // n = 1 »ò 2
        if (n <= 2) {
            return n;
        }
        // n >= 3
        int a = 1;
        int b = 2;
        int count = 3;
        while (count <= n) {
            int temp = b;
            b = a + b;
            a = temp;
            count++;
        }
        return b;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 9; i++) {
        cout << sol.climbStairs(i) << endl;
    }
    return 0;
}