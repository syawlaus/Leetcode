#include <frequently-used-code-snippets.h>

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        if (root == NULL) {
            return paths;
        }

        if (root->left == NULL && root->right == NULL) {
            paths.push_back(to_string(root->val));
        }

        // 处理左子树
        vector<string> leftPaths;
        if (root->left != NULL) {
            leftPaths = binaryTreePaths(root->left);
        }
        for (string leftPath : leftPaths) {
            string path = to_string(root->val) + "->" + leftPath;
            paths.push_back(path);
        }

        // 处理右子树
        vector<string> rightPaths;
        if (root->right != NULL) {
            rightPaths = binaryTreePaths(root->right);
        }
        for (string rightPath : rightPaths) {
            string path = to_string(root->val) + "->" + rightPath;
            paths.push_back(path);
        }

        return paths;
    }
};

int main() {
    TreeNode A(1);
    TreeNode B(2);
    TreeNode C(3);
    TreeNode D(5);

    A.left = &B;
    A.right = &C;
    B.right = &D;

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(&A);
    printVector(paths);
}