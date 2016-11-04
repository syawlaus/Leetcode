#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                bracketStack.push(c);
                continue;
            }
            if (c == ')' &&
                ! bracketStack.empty() &&
                bracketStack.top() == '(') {
                bracketStack.pop();
                continue;
            }
            if (c == ']' &&
                ! bracketStack.empty() &&
                bracketStack.top() == '[') {
                bracketStack.pop();
                continue;
            }
            if (c == '}' &&
                ! bracketStack.empty() &&
                bracketStack.top() == '{') {
                bracketStack.pop();
                continue;
            }
            return false;
        }
        return bracketStack.empty();
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("(]{)") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("([)]{}") << endl;
    cout << sol.isValid("[") << endl;
    cout << sol.isValid("]") << endl;
}