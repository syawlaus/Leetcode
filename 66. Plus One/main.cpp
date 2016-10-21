#include <iostream>
#include <vector>
#include <math.h>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // �� vector ͷ���� 0
        digits.insert(digits.begin(), 0);

        // ���λ +1
        int lastIndex = digits.size() - 1;
        digits[lastIndex]++;

        // �����λ���
        int carryBit = 0;
        for (int i = lastIndex; i >= 0; i--) {
            digits[i] += carryBit;
            if (digits[i] == 10) {
                carryBit = 1;   // ��һλ��һλ
                digits[i] = 0;  // ���õ�ǰ��λΪ 0
            }
            else {
                carryBit = 0;
                break;
            }
        }

        // ȥ�� vector ͷ�� 0
        if (digits[0] == 0) {
            digits.erase(digits.begin());
        }

        return digits;
    }

    vector<int> plusOne2(vector<int>& digits) {
        // �� digits ת��Ϊ int
        int num = 0;
        int highestPow = digits.size() - 1;     // ��ߴ���
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits[i];
            num += digit * pow(10, highestPow);
            highestPow--;
        }

        // int++
        num++;

        // �� int ת��Ϊ digits
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