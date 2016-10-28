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

        bool twoNumsLeft = false;   // 猜到最后会剩下两个相邻的数，一奇一偶
        int result = guess(myGuess);
        while (result != GOT_IT) {
            if (result == GUESS_LOWER_NEXT_TIME) {  // 下次往低猜
                high = getAverage(low, high);
            }
            else {                                  // 下次往高猜
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

            // 继续猜
            myGuess = getAverage(low, high);
            result = guess(myGuess);
        }
        return myGuess;
    }

private:
    int getAverage(int low, int high) {
        //return (low + high) / 2;    // 这样会 int 溢出
        return low + (high - low) / 2;
    }
};

int main() {
    Solution sol;
    cout << sol.guessNumber(RANGE) << endl;
}