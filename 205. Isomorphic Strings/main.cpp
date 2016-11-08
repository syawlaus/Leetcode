#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const char *sArr = s.c_str();
        const char *tArr = t.c_str();
        int len = s.length();
        map<char, char> isomoMap;

        for (int i = 0; i < len; i++) {
            char sc = sArr[i];
            char tc = tArr[i];
            if (isomoMap.find(sc) == isomoMap.end()) {      // sc �����ڣ��ж�����ӵ� sc �� tc �Ƿ��ѱ�ʹ��
                if (containsValueInMap(isomoMap, tc)) {
                    return false;
                }
                isomoMap.insert(pair<char, char>(sc, tc));
            }
            else {      // sc �Ѵ��ڣ��ж�ͬһ�� sc �Ƿ��Ӧ������ͬ�� tc
                char old_tc = (isomoMap.find(sc))->second;
                if (tc != old_tc) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isIsomorphic("", "") << endl;
    cout << sol.isIsomorphic("egg", "add") << endl;
    cout << sol.isIsomorphic("foo", "bar") << endl;
    cout << sol.isIsomorphic("paper", "title") << endl;
    cout << sol.isIsomorphic("ab", "aa") << endl;
}