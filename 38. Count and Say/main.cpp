#include <frequently-used-code-snippets.h>

class Solution {
public:
    string countAndSay(int n) {
        string sPrev = "1";
        for (int i = 1; i < n; i++) {
            // ÿ������һ�� count-and-say ���У���Ҫ���� prevIndex �� sNext
            int prevIndex = 0;
            string sNext = "";

            // ʹ�� sPrev ���� sNext
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
    // �� s �У��� index ��ʼ������ index �����ַ�������֮������ͬ�ַ��ĸ���
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