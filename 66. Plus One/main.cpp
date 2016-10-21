#include <iostream>
#include <vector>
#include <math.h>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 在 vector 头插入 0
        digits.insert(digits.begin(), 0);

        // 最低位 +1
        int lastIndex = digits.size() - 1;
        digits[lastIndex]++;

        // 处理进位情况
        int carryBit = 0;
        for (int i = lastIndex; i >= 0; i--) {
            digits[i] += carryBit;
            if (digits[i] == 10) {
                carryBit = 1;   // 下一位进一位
                digits[i] = 0;  // 重置当前数位为 0
            }
            else {
                carryBit = 0;
                break;
            }
        }

        // 去掉 vector 头的 0
        if (digits[0] == 0) {
            digits.erase(digits.begin());
        }

        return digits;
    }

    vector<int> plusOne2(vector<int>& digits) {
        // 把 digits 转化为 int
        int num = 0;
        int highestPow = digits.size() - 1;     // 最高次幂
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits[i];
            num += digit * pow(10, highestPow);
            highestPow--;
        }

        // int++
        num++;

        // 把 int 转化为 digits
        vector<int> newDigits;
        while (num > 0) {
            newDigits.insert(newDigits.begin(), num % 10);
            num /= 10;
        }
        return newDigits;
    }
};

int main() {
    int array[] = { 9, 9 };
    vector<int> v = convertArrayToVector(array, ARRAY_LENGTH(array));

    Solution sol;
    sol.plusOne2(v);
}