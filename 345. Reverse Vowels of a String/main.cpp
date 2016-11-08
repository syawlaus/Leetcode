#include <frequently-used-code-snippets.h>

class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        if (len <= 1) {
            return s;
        }

        char *pHead = &s[0];
        char *pTail = &s[len - 1];

        while (true) {
            findNextVowelForward(pHead);
            findNextVowelBackward(pTail);
            if (pHead < pTail) {
                swapVowel(pHead, pTail);
                pHead++;
                pTail--;
            }
            else {
                break;
            }
        }
        return s;
    }

private:
    void findNextVowelForward(char*& pHead) {
        while (true) {
            if (isVowel(*pHead)) {
                return;
            }
            pHead++;
        }
    }

    void findNextVowelBackward(char*& pTail) {
        while (true) {
            if (isVowel(*pTail)) {
                return;
            }
            pTail--;
        }
    }

    void swapVowel(char*& pHead,
                   char*& pTail) {
        char temp = *pHead;
        *pHead = *pTail;
        *pTail = temp;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseVowels("") << endl;
    cout << sol.reverseVowels("hello") << endl;
    cout << sol.reverseVowels("leetcode") << endl;
}