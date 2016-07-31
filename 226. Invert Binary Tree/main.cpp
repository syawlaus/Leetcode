#include <iostream>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // root 为空结点
        if (root == NULL) {
            return NULL;
        }

        // root 是叶子节点
        if (root->left == NULL &&
            root->right == NULL) {
            return root;
        }

        // 反转左子树
        TreeNode* left = invertTree(root->left);

        // 反转右子树
        TreeNode* right = invertTree(root->right);

        // 交换左右子结点
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 返回根结点
        return root;
    }
};