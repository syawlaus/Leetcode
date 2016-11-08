#include <frequently-used-code-snippets.h>

class Solution {
public:
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
    vector<vector<int>> triangle = sol.generate(5);
    
    // ��ӡ�������
    for (int row = 0; row < triangle.size(); row++) {
        printVector(triangle[row]);
    }
}