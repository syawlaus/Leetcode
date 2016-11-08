#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        int sizeS = s.size();
        int sizeT = t.size();

        // s, t ���Ȳ�ͬ���� t �϶����� s ����λ����
        if (sizeS != sizeT) {
            return false;
        }

        // ��ʼ���������
        bool* markArr = new bool[sizeS];
        for (int i = 0; i < sizeS; i++) {
            markArr[i] = false;
        }

        // ���� t
        for (char ct : t) {
            // �� ct �Ƿ� s ���ַ�
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

        // �� markArr �Ƿ�ȫ�����Ϊ����ʹ�á�
        for (int i = 0; i < sizeS; i++) {
            if (! markArr[i]) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram2(string& s, string& t) {
        // s, t ���Ȳ�ͬ���� t �϶����� s ����λ����
        if (s.size() != t.size()) {
            return false;
        }

        // �� s ȫ���ַ���ӵ� mapS
        map<char, int> mapS;
        for (char cs : s) {
            incrementKeyCountInMap(mapS, cs);
        }

        // �� t ȫ���ַ���ӵ� mapT
        map<char, int> mapT;
        for (char ct : t) {
            incrementKeyCountInMap(mapT, ct);
        }

        // ��� mapS, mapT ���Ȳ�ͬ���� t �϶����� s ����λ����
        int sizeMapS = mapS.size();
        int sizeMapT = mapT.size();
        if (sizeMapS != sizeMapT) {
            return false;
        }

        // �ж� mapT ÿ�� key �Ƿ��� mapS ���У��Ҷ�Ӧ value һ��
        for (map<char, int>::iterator iterT = mapT.begin(); iterT != mapT.end(); iterT++) {
            char keyT = (*iterT).first;
            int valT = (*iterT).second;

            bool foundKeyS = false;
            for (map<char, int>::iterator iterS = mapS.begin(); iterS != mapS.end(); iterS++) {
                char keyS = (*iterS).first;
                int valS = (*iterS).second;

                // �ҵ� keyS
                if (keyS == keyT) {
                    foundKeyS = true;

                    // val ��ȣ�����������һ�� keyT
                    if (valS == valT) {
                        break;
                    }
                    // val ��ͬ���� t ������λ����
                    else {
                        return false;
                    }
                }
            }

            // û���ҵ��� keyT ��ͬ�� keyS���� t ������λ����
            if (! foundKeyS) {
                return false;
            }
        }

        // mapS, mapT ��ȫ��ͬ���� t ����λ����
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