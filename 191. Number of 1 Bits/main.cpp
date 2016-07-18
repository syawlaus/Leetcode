#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(unsigned n) {
        int sum = 0;
        while (n > 0) {
            int remainder = n % 2;
            if (remainder == 1) {
                sum++;
            }
            n = n / 2;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int hw = sol.hammingWeight(11);
    cout << hw << endl;
}