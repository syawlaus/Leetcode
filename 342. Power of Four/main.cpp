#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isPowerOfFour(int num) {
        double m = logbase(num, 4);
        double roundM = round(m);
        double absoluteDiff = abs(m - roundM);  // 取两者之差的绝对值
        return (absoluteDiff < EPSILON);
    }

private:
    double EPSILON = 10e-15;
};

int main() {
    Solution sol;
    cout << sol.isPowerOfFour(16) << endl;
    cout << sol.isPowerOfFour(17) << endl;
}