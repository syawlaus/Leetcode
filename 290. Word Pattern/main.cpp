#include <frequently-used-code-snippets.h>

class Solution {
public:
    // ˼·��
    //     1. ���Ȱ� str �ָ��һ�������ʣ����浽һ�� vector<string> �
    //     2. ��� string[] ���ȸ� pattern ���Ȳ�ͬ��return false
    //     3. ���������ͬ����ʼ�����Ƚ�
    //        ��� mapA ������ c �� mapB ������ word����ֱ���ӽ�ȥ
    //        ��� mapA ���� c �Ҷ�Ӧ�� value == word���� mapB ���� word �Ҷ�Ӧ�� value == c�������������һ�� c �� word
    //        ���� return false
    bool wordPattern(string pattern, string str) {
        // �� 1 ��
        vector<string> words = splitString(str);

        // �� 2 ��
        if (words.size() != pattern.length()) {
            return false;
        }

        // �� 3 ��
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
    // �� str �ָ�Ϊ vector<string>���ָ���Ϊ�ո�
    vector<string> splitString(string str) {
        str += " ";     // Ϊ�˰����һ�ε��� push_back �� vector
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

    // ����ֵ��
    //     0�����߲�����˫��
    //     1�����ߴ���˫��
    //    -1�����ߴ���һ�Զ�ӳ��
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

    // �� <c, word> ��ӵ� mapA
    // �� <word, c> ��ӵ� mapB
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