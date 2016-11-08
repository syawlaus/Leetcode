#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = 9;
        map<char, bool> numMap;

        // ���������
        for (int row = 0; row < size; row++) {
            // ��鵥��
            numMap.clear();
            for (int col = 0; col < size; col++) {
                if (containsKeyInMap(numMap, board[row][col])) {    // 1~9 ���ֹ�����
                    return false;
                }
                else {
                    addToMap(numMap, board[row][col], true);
                }
            }
        }

        // ���������
        for (int col = 0; col < size; col++) {
            // ��鵥��
            numMap.clear();
            for (int row = 0; row < size; row++) {
                if (containsKeyInMap(numMap, board[row][col])) {    // 1~9 ���ֹ�����
                    return false;
                }
                else {
                    addToMap(numMap, board[row][col], true);
                }
            }
        }

        // ������оŹ���
        int squareSize = 3;
        // 0~6 ��
        for (int row = 0; row < 7; row += 3) {
            // 0~6 ��
            for (int col = 0; col < 7; col += 3) {
                // ��鵥���Ź���
                numMap.clear();
                for (int squareRow = row; squareRow < row + squareSize; squareRow++) {
                    for (int squareCol = col; squareCol < col + squareSize; squareCol++) {
                        if (containsKeyInMap(numMap, board[squareRow][squareCol])) {     // 1~9 ���ֹ�����
                            return false;
                        }
                        else {
                            addToMap(numMap, board[squareRow][squareCol], true);
                        }
                    }
                }
            }
        }
        return true;

    }

private:
    // ���ܣ���� <key, val> �� map
    // ������map, key, val
    // ���أ�void
    void addToMap(map<char, bool>& mapp,
                  char key,
                  bool val) {
        if (key == NULL || key == '.') {
            return;
        }

        map<char, bool>::iterator iter = mapp.find(key);

        // �Ҳ��� key����� <key, val>
        if (iter == mapp.end()) {
            mapp.insert(pair<char, bool>(key, val));
        }
        // �ҵ� key������ val
        else {
            (iter->second) = val;
        }
    }
};

int main() {
    vector<vector<char>> full_filled_board = {
        { '4', '6', '3', '7', '2', '8', '9', '5', '1' },
        { '2', '5', '9', '4', '6', '1', '7', '3', '8' },
        { '7', '8', '1', '3', '5', '9', '6', '4', '2' },
        { '5', '3', '2', '1', '9', '7', '4', '8', '6' },
        { '9', '1', '4', '6', '8', '2', '5', '7', '3' },
        { '6', '7', '8', '5', '4', '3', '1', '2', '9' },
        { '8', '2', '6', '9', '7', '5', '3', '1', '4' },
        { '1', '4', '7', '2', '3', '6', '8', '9', '5' },
        { '3', '9', '5', '8', '1', '4', '2', '6', '7' }
    };

    vector<vector<char>> partially_filled_board = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    Solution sol;
    cout << sol.isValidSudoku(full_filled_board) << endl;
    cout << sol.isValidSudoku(partially_filled_board) << endl;
}