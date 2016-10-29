#include <frequently-used-code-snippets.h>

class Solution {
public:
    string getHint(string secret, string guess) {
        const char *secretArr = secret.c_str();
        const char *guessArr = guess.c_str();
        int len = secret.length();

        int numA = 0;
        int numB = 0;
        map<char, int> mapGuess;
        map<char, int> mapSecret;

        // 遍历 guess 和 secret
        for (int i = 0; i < len; i++) {
            if (guessArr[i] == secretArr[i]) {  // guessArr[i] 是公牛
                numA++;
            }
            else {                              // guessArr[i] 是母牛
                incrementKeyCountInMap(mapGuess, guessArr[i]);
                incrementKeyCountInMap(mapSecret, secretArr[i]);
            }
        }

        // 遍历 mapGuess
        for (map<char, int>::iterator iterGuess = mapGuess.begin(); iterGuess != mapGuess.end(); iterGuess++) {
            for (map<char, int>::iterator iterSecret = mapSecret.begin(); iterSecret != mapSecret.end(); iterSecret++) {
                char guessChar = iterGuess->first;
                char secretChar = iterSecret->first;
                if (guessChar == secretChar) {
                    int guessCount = iterGuess->second;
                    int secretCount = iterSecret->second;
                    numB += MIN_TWO(guessCount, secretCount);
                }
            }
        }

        return to_string(numA) + "A" + to_string(numB) + "B";
    }
};

int main() {
    Solution sol;
    cout << sol.getHint("1807", "7810") << endl;
    cout << sol.getHint("1123", "0111") << endl;
}