#include <frequently-used-code-snippets.h>

class Solution {
public:
    int trailingZeroes(int n) {
        int num5 = 0;
        for (int i = n / 5; i > 0; i /= 5) {
            num5 += i;
        }
        return num5;
    }
};

int main() {
    Solution sol;
    cout << sol.trailingZeroes(30) << endl;     // 7
    cout << sol.trailingZeroes(50) << endl;     // 12
    cout << sol.trailingZeroes(200) << endl;    // 49
}