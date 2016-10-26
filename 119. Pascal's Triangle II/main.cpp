#include <frequently-used-code-snippets.h>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle = generate(rowIndex + 1);
        return triangle[rowIndex];
    }

private:
    vector<vector<int>> generate(int numRows) {
        // ����������ǣ�ȫ��Ԫ�ض�Ϊ 1
        vector<vector<int>> triangle;
        for (int row = 0; row < numRows; row++) {
            vector<int> rowVec;
            triangle.push_back(rowVec);
            for (int col = 0; col <= row; col++) {
                triangle[row].push_back(1);
            }
        }

        // ���ڷǱ�Ե��Ԫ�أ�������ֵ
        for (int row = 2; row < numRows; row++) {
            for (int col = 1; col < row; col++) {
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
        }

        // ����������
        return triangle;
    }
};

int main() {
    // �����������
    Solution sol;
    printVector(sol.getRow(0));
    printVector(sol.getRow(1));
    printVector(sol.getRow(2));
    printVector(sol.getRow(3));
    printVector(sol.getRow(4));
    printVector(sol.getRow(5));
}