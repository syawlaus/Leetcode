#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n < 1) {
            return false;
        }

        vector<int> v;
        while (true) {
            int sumSquare = getSumSquare(n);
            if (sumSquare == 1) {
                cout << "sumSquare == 1，return true" << endl;
                return true;
            }
            if (containsElementInVector(v, sumSquare)) {    // 死循环
                cout << "vector 已存在 " << sumSquare << "，死循环，return false" << endl;
                return false;
            }

            v.push_back(sumSquare);
            cout << "vector 添加 " << sumSquare << endl;

            n = sumSquare;  // 更新 n
        }
    }

    // 求 n 各位数字的平方和
    int getSumSquare(int n) {
        int sumSquare = 0;
        while (n > 0) {
            int digit = n % 10;
            sumSquare += digit * digit;
            n /= 10;
        }
        return sumSquare;
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(19) << endl << endl;
    cout << sol.isHappy(20) << endl << endl;
}