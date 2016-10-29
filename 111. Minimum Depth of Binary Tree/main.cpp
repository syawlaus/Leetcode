#include <frequently-used-code-snippets.h>

#define NOT_LEAF_NODE -1

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        if (isLeafNode(root)) {
            return 1;
        }

        // 处理左子树
        int leftMinDepth = NOT_LEAF_NODE;   // 防止把只有左子节点的二叉树的 minDepth 判断为 1（因为右子树 minDepth 为 0）
        if (root->left != NULL) {
            leftMinDepth = minDepth(root->left);
        }

        // 处理右子树
        int rightMinDepth = NOT_LEAF_NODE;  // 防止把只有右子节点的二叉树的 minDepth 判断为 1（因为左子树 minDepth 为 0）
        if (root->right != NULL) {
            rightMinDepth = minDepth(root->right);
        }

        // 返回：root 只有左子树
        if (leftMinDepth != NOT_LEAF_NODE && rightMinDepth == NOT_LEAF_NODE) {
            return leftMinDepth + 1;
        }
        // 返回：root 只有右子树
        if (leftMinDepth == NOT_LEAF_NODE && rightMinDepth != NOT_LEAF_NODE) {
            return rightMinDepth + 1;
        }
        // 返回：root 有左右子树
        else {      // 即 leftMinDepth != NOT_LEAF_NODE && rightMinDepth != NOT_LEAF_NODE
            return MIN_TWO(leftMinDepth, rightMinDepth) + 1;
        }
    }
};

int main() {
    TreeNode A(5);
    TreeNode B(4);
    TreeNode C(8);
    TreeNode D(11);
    TreeNode E(13);
    TreeNode F(4);
    TreeNode G(7);
    TreeNode H(2);
    TreeNode I(1);

    A.left = &B;
    A.right = &C;
    B.left = &D;
    C.left = &E;
    C.right = &F;
    D.left = &G;
    D.right = &H;
    F.right = &I;

    Solution sol;
    cout << sol.minDepth(&A) << endl;
}