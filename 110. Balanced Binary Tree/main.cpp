#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        // 判断左子树是否平衡
        bool isLeftBalanced = isBalanced(root->left);
        if (! isLeftBalanced) {
            return false;
        }

        // 判断右子树是否平衡
        bool isRightBalanced = isBalanced(root->right);
        if (! isRightBalanced) {
            return false;
        }

        // 左、右子树都平衡，判断两者高度差是否不大于 1
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return (abs(leftHeight - rightHeight) <= 1);
    }
};

int main() {
    TreeNode A(1);
    TreeNode B(2);
    TreeNode C(3);
    TreeNode D(4);
    TreeNode E(5);

    A.left = &B;
    A.right = &C;
    B.left = &D;
    D.left = &E;

    Solution sol;
    cout << sol.isBalanced(&A) << endl;
}