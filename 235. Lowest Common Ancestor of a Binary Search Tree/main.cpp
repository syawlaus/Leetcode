#include <iostream>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    // 求 v, w 在以 root 为根节点的二叉搜索树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* v,
                                   TreeNode* w) {
        if (v == NULL || w == NULL) {
            return NULL;
        }

        // 第 1 步
        if (v == w) {
            return v;
        }

        // 第 2、3 步
        while (true) {
            int result = subtree(root, v, w);
            if (result == TWO_LEFT) {
                root = root->left;
            }
            else if (result == TWO_RIGHT) {
                root = root->right;
            }
            else {      // result == ONE_LEFT_ONE_RIGHT
                return root;
            }
        }
    }

    // 判断 v, w 在 root 的哪棵子树下
    int subtree(TreeNode* root,
        TreeNode* v,
        TreeNode* w) {

        //  v, w 都在 root 左子树
        if (root->val > v->val &&
            root->val > w->val) {
            return TWO_LEFT;
        }

        // v, w 都在 root 右子树
        if (root->val < v->val &&
            root->val < w->val) {
            return TWO_RIGHT;
        }

        // v, w 分别在 root 左、右子树
        return ONE_LEFT_ONE_RIGHT;
    }

private:
    const int TWO_LEFT = 1;
    const int TWO_RIGHT = 2;
    const int ONE_LEFT_ONE_RIGHT = 3;
};

int main() {
    // init data
    TreeNode n6(6);
    TreeNode n2(2);
    TreeNode n8(8);
    TreeNode n0(0);
    TreeNode n4(4);
    TreeNode n7(7);
    TreeNode n9(9);
    TreeNode n3(3);
    TreeNode n5(5);

    n6.left  = &n2;
    n6.right = &n8;

    n2.left  = &n0;
    n2.right = &n4;

    n8.left  = &n7;
    n8.right = &n9;

    n4.left  = &n3;
    n4.right = &n5;

    // LCA
    Solution sol;
    TreeNode* root = &n6;
    TreeNode* v = &n2;
    TreeNode* w = &n4;
    TreeNode* lca = sol.lowestCommonAncestor(root, v, w);
    cout << v->val << ", " << w->val << " 的 LCA 是 " << lca->val << endl;

    v = &n2;
    w = &n8;
    lca = sol.lowestCommonAncestor(root, v, w);
    cout << v->val << ", " << w->val << " 的 LCA 是 " << lca->val << endl;

    return 0;
}