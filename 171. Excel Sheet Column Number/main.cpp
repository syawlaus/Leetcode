#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        char* letterArr = &s[0];
        int size = s.size();

        // ���� char ���飬ȡÿ����ĸ������(letter - 64) * (26 ^ pow)
        // index ԽС����ĸ����ʾ�� 26 ����Խ��
        // ���磬��ĸ index = 0��size = 2���� 26 ���� = size - 1 - index
        int sum = 0;
        for (int i = 0; i < size; i++) {
            char letter = letterArr[i];
            int pow26 = size - 1 - i;
            sum += (letter - 64) * pow(26, pow26);
        }
        return sum;
    }
};

int main() {
    Solution sol;

    string str = "A";
    cout << str << " -> " << sol.titleToNumber(str) << endl;

    str = "B";
    cout << str << " -> " << sol.titleToNumber(str) << endl;

    str = "AA";
    cout << str << " -> " << sol.titleToNumber(str) << endl;

    str = "AB";
    cout << str << " -> " << sol.titleToNumber(str) << endl;
}