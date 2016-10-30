#include <frequently-used-code-snippets.h>

class Solution {
public:
    string countAndSay(int n) {
        string sPrev = "1";
        for (int i = 1; i < n; i++) {
            // 每计算下一个 count-and-say 序列，都要重置 prevIndex 和 sNext
            int prevIndex = 0;
            string sNext = "";

            // 使用 sPrev 计算 sNext
            while (prevIndex < sPrev.length()) {
                int count = getConsecutiveCount(sPrev, prevIndex);
                sNext += to_string(count) + sPrev[prevIndex];
                prevIndex += count;
            }
            sPrev = sNext;
        }
        return sPrev;
    }

private:
    // 在 s 中，从 index 开始，返回 index 所在字符后面与之连续相同字符的个数
    int getConsecutiveCount(string& s, int index) {
        if (index >= s.length()) {
            return 0;
        }
        char currCh = s[index];
        int count = 0;
        for (; index < s.length(); index++) {
            if (s[index] == currCh) {
                count++;
            }
            else {
                break;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.countAndSay(1) << endl;
    cout << sol.countAndSay(2) << endl;
    cout << sol.countAndSay(3) << endl;
    cout << sol.countAndSay(4) << endl;
    cout << sol.countAndSay(5) << endl;
    cout << sol.countAndSay(6) << endl;
    cout << sol.countAndSay(7) << endl;
}