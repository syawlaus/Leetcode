#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string& s) {
        int len = s.length();
        int head = 0;
        int tail = len - 1;

        while (head < tail) {
            // swap
            char temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;

            // update indices
            head++;
            tail--;
        }

        return s;
    }

    string reverseString2(string& s) {
        char *pHead = &s[0];

        int len = s.length();
        char *pTail = &s[len - 1];

        while (pHead < pTail) {
            // swap chars which pHead & pTail point to
            char temp = *pHead;
            *pHead = *pTail;
            *pTail = temp;

            // update pHead & pTail
            pHead++;
            pTail--;
        }

        return s;
    }

    string reverseString3(const string& s) {    // 既然不操作 s，那么就不允许修改 s
        string newStr;
        int len = s.length();
        for (int tail = len - 1; tail >= 0; tail--) {
            newStr += s[tail];
        }
        return newStr;
    }
};

int main() {
    string s = "hello";
    cout << "original string: " << s << endl;

    Solution sol;
    string newStr = sol.reverseString3(s);
    cout << "reversed string: " << newStr << endl;
}