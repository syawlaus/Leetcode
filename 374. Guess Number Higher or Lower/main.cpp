#include <frequently-used-code-snippets.h>

#define GUESS_LOWER_NEXT_TIME -1
#define GUESS_HIGHER_NEXT_TIME 1
#define GOT_IT 0

#define RANGE 2147483647
#define PICK  2147483647

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
    if (PICK < num) {
        return -1;
    }
    if (PICK > num) {
        return 1;
    }
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int myGuess = getAverage(low, high);

        bool twoNumsLeft = false;   // �µ�����ʣ���������ڵ�����һ��һż
        int result = guess(myGuess);
        while (result != GOT_IT) {
            if (result == GUESS_LOWER_NEXT_TIME) {  // �´����Ͳ�
                high = getAverage(low, high);
            }
            else {                                  // �´����߲�
                if (twoNumsLeft) {
                    myGuess = high;
                    break;
                }
                else {
                    low = myGuess;
                }
            }

            if (high - low <= 1) {
                twoNumsLeft = true;
            }

            // ������
            myGuess = getAverage(low, high);
            result = guess(myGuess);
        }
        return myGuess;
    }

private:
    int getAverage(int low, int high) {
        //return (low + high) / 2;    // ������ int ���
        return low + (high - low) / 2;
    }
};

int main() {
    Solution sol;
    cout << sol.guessNumber(RANGE) << endl;
}