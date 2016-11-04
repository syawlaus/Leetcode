#include <frequently-used-code-snippets.h>

class Solution {
public:
    // 思路：
    //     1. 首先把 str 分割出一个个单词，保存到一个 vector<string> 里。
    //     2. 如果 string[] 长度跟 pattern 长度不同，return false
    //     3. 如果长度相同，开始遍历比较
    //        如果 mapA 不存在 c 且 mapB 不存在 word，则分别添加进去
    //        如果 mapA 存在 c 且对应的 value == word，且 mapB 存在 word 且对应的 value == c，则继续遍历下一个 c 和 word
    //        否则 return false
    bool wordPattern(string pattern, string str) {
        // 第 1 步
        vector<string> words = splitString(str);

        // 第 2 步
        if (words.size() != pattern.length()) {
            return false;
        }

        // 第 3 步
        map<char, string> mapA;
        map<string, char> mapB;
        for (int i = 0; i < words.size(); i++) {
            char c = pattern[i];
            string word = words[i];
            int result = matchBijection(mapA, mapB, c, word);
            if (result == 1) {
                continue;
            }
            if (result == 0) {
                addBijection(mapA, mapB, c, word);
            }
            else {
                return false;
            }
        }
        return true;
    }

private:
    // 把 str 分隔为 vector<string>，分隔符为空格
    vector<string> splitString(string str) {
        str += " ";     // 为了把最后一次单词 push_back 到 vector
        vector<string> words;
        char split = ' ';
        string word = "";
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (c != split) {
                word += c;
            }
            else {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        return words;
    }

    // 返回值：
    //     0：两者不存在双射
    //     1：两者存在双射
    //    -1：两者存在一对多映射
    int matchBijection(map<char, string>& mapA,
                       map<string, char>& mapB,
                       char c,
                       string word) {
        if (! containsKeyInMap(mapA, c) &&
            ! containsKeyInMap(mapB, word)) {
            return 0;
        }

        map<char, string>::iterator iterA = mapA.find(c);
        map<string, char>::iterator iterB = mapB.find(word);
        if (iterA != mapA.end() && iterA->second == word &&
            iterB != mapB.end() && iterB->second == c) {
            return 1;
        }
        return -1;
    }

    // 把 <c, word> 添加到 mapA
    // 把 <word, c> 添加到 mapB
    void addBijection(map<char, string>& mapA,
                      map<string, char>& mapB,
                      char c,
                      string word) {
        mapA[c] = word;
        mapB[word] = c;
    }
};

int main() {
    Solution sol;
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;     // 1
    cout << sol.wordPattern("abba", "dog cat cat fish") << endl;    // 0
    cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl;     // 0
    cout << sol.wordPattern("abba", "dog dog dog dog") << endl;     // 0
}