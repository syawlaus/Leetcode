#include <frequently-used-code-snippets.h>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int lastIndex = findLastNonEmptySpaceIndex(s);
        for (int i = lastIndex; i >= 0 && s[i] != ' '; i--) {
            length++;
        }
        return length;
    }

private:
    const int UNDEFINED = -1;

    int findLastNonEmptySpaceIndex(string& s) {
        int i = UNDEFINED;
        for (i = s.size() - 1; i >= 0 && s[i] == ' '; i--) {

        }
        return i;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("Hello world") << endl;
    cout << sol.lengthOfLastWord("Helloworld") << endl;
    cout << sol.lengthOfLastWord("abc     ") << endl;
    cout << sol.lengthOfLastWord(" ") << endl;
}