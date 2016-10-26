#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0) {
            return false;
        }
        int originN = n;
        int m = 0;
        while (n > 0) {
            m = m * 10 + n % 10;
            n /= 10;
        }
        return m == originN;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome(-2147447412) << endl;
}