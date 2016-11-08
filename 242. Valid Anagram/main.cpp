#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        int sizeS = s.size();
        int sizeT = t.size();

        // s, t 长度不同，则 t 肯定不是 s 的易位构词
        if (sizeS != sizeT) {
            return false;
        }

        // 初始化标记数组
        bool* markArr = new bool[sizeS];
        for (int i = 0; i < sizeS; i++) {
            markArr[i] = false;
        }

        // 遍历 t
        for (char ct : t) {
            // 看 ct 是否 s 的字符
            bool isCtFound = false;
            for (int i = 0; i < sizeS; i++) {
                if (ct == s[i] &&
                    ! markArr[i]) {
                    markArr[i] = true;
                    isCtFound = true;
                    break;
                }
            }
            if (! isCtFound) {
                return false;
            }
        }

        // 看 markArr 是否全部标记为“已使用”
        for (int i = 0; i < sizeS; i++) {
            if (! markArr[i]) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram2(string& s, string& t) {
        // s, t 长度不同，则 t 肯定不是 s 的易位构词
        if (s.size() != t.size()) {
            return false;
        }

        // 把 s 全部字符添加到 mapS
        map<char, int> mapS;
        for (char cs : s) {
            incrementKeyCountInMap(mapS, cs);
        }

        // 把 t 全部字符添加到 mapT
        map<char, int> mapT;
        for (char ct : t) {
            incrementKeyCountInMap(mapT, ct);
        }

        // 如果 mapS, mapT 长度不同，则 t 肯定不是 s 的易位构词
        int sizeMapS = mapS.size();
        int sizeMapT = mapT.size();
        if (sizeMapS != sizeMapT) {
            return false;
        }

        // 判断 mapT 每个 key 是否在 mapS 都有，且对应 value 一样
        for (map<char, int>::iterator iterT = mapT.begin(); iterT != mapT.end(); iterT++) {
            char keyT = (*iterT).first;
            int valT = (*iterT).second;

            bool foundKeyS = false;
            for (map<char, int>::iterator iterS = mapS.begin(); iterS != mapS.end(); iterS++) {
                char keyS = (*iterS).first;
                int valS = (*iterS).second;

                // 找到 keyS
                if (keyS == keyT) {
                    foundKeyS = true;

                    // val 相等，继续遍历下一个 keyT
                    if (valS == valT) {
                        break;
                    }
                    // val 不同，则 t 不是易位构词
                    else {
                        return false;
                    }
                }
            }

            // 没有找到与 keyT 相同的 keyS，则 t 不是易位构词
            if (! foundKeyS) {
                return false;
            }
        }

        // mapS, mapT 完全相同，则 t 是易位构词
        return true;
    }
};

int main() {
    Solution sol;
    string s;
    string t;
    bool isAnagram;

    s = "anagram";
    t = "nagaram";
    isAnagram = sol.isAnagram2(s, t);
    cout << isAnagram << endl;

    cout << "------------" << endl;

    s = "cat";
    t = "rat";
    isAnagram = sol.isAnagram2(s, t);
    cout << isAnagram << endl;
}