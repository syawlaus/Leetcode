#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int temp = num;
        vector<int> vecDigits;

        while (true) {
            // calculate number of digits of num
            int numDigits = getNumDigits(temp, vecDigits);

            // end function
            if (numDigits == 1) {
                // TODO: release vector memory

                return temp;
            }

            // repeatedly add all num's digits
            temp = 0;
            for (int digit : vecDigits) {
                temp += digit;
            }

            // reset vector
            vecDigits.clear();
        }
    }
    
    int getNumDigits(int num, vector<int>& vecDigits) {
        vecDigits.clear();

        while (true) {
            if (num == 0) {
                return vecDigits.size();
            }
            int lastDigis = num % 10;
            vecDigits.push_back(lastDigis);
            num /= 10;
        }
    }

    int addDigits2(int num) {
        while (num / 10 > 0) {      // ��ѭ��
            int temp = num;
            int sum = 0;
            while (temp > 0) {      // ��ѭ��
                int lastDigit = temp % 10;
                sum += lastDigit;
                temp /= 10;
            }
            num = sum;
        }
        return num;
    }

    int addDigits3(int num) {
        // �ݹ��������
        if (num / 10 == 0) {
            return num;
        }

        int sum = 0;
        while (num > 0) {   // ��ѭ��
            int lastDigit = num % 10;
            sum += lastDigit;
            num /= 10;
        }

        // �ݹ飨����ѭ����
        return addDigits(sum);
    }

    int addDigits4(int num) {
        int result = (num - 1) % 9 + 1;
        return result;
    }
};

int main() {
    Solution sol;
    int result = sol.addDigits4(12345);
    cout << result << endl;
}