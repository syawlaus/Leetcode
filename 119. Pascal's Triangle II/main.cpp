#include <frequently-used-code-snippets.h>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle = generate(rowIndex + 1);
        return triangle[rowIndex];
    }

private:
    vector<vector<int>> generate(int numRows) {
        // 生成杨辉三角，全部元素都为 1
        vector<vector<int>> triangle;
        for (int row = 0; row < numRows; row++) {
            vector<int> rowVec;
            triangle.push_back(rowVec);
            for (int col = 0; col <= row; col++) {
                triangle[row].push_back(1);
            }
        }

        // 对于非边缘的元素，计算其值
        for (int row = 2; row < numRows; row++) {
            for (int col = 1; col < row; col++) {
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
        }

        // 输出杨辉三角
        return triangle;
    }
};

int main() {
    // 生成杨辉三角
    Solution sol;
    printVector(sol.getRow(0));
    printVector(sol.getRow(1));
    printVector(sol.getRow(2));
    printVector(sol.getRow(3));
    printVector(sol.getRow(4));
    printVector(sol.getRow(5));
}