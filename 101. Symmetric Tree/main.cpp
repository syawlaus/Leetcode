#include <frequently-used-code-snippets.h>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *invertRoot = invertTree(root);
        bool isSym = isSameTree(root, invertRoot);
        return isSym;
    }
private:
    TreeNode* invertTree(TreeNode *root) {
        TreeNode *copyRoot = copyTree(root);
        copyRoot = invertTreeInPlace(copyRoot);
        return copyRoot;
    }

    TreeNode* copyTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *copyRoot = new TreeNode(root->val);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

    TreeNode* invertTreeInPlace(TreeNode *root) {
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
        TreeNode *left = invertTreeInPlace(root->left);

        // 反转右子树
        TreeNode *right = invertTreeInPlace(root->right);

        // 交换左右子结点
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 返回根结点
        return root;
    }

     bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        // 结构不同
        if (p != NULL && q == NULL) {
            return false;
        }
        // 结构不同
        if (p == NULL && q != NULL) {
            return false;
        }
        // 结构相同
        else {      // 即 p != NULL && q != NULL
            // 值不同
            if (p->val != q->val) {
                return false;
            }
            // 值相同
            bool isSameLeft = isSameTree(p->left, q->left);
            bool isSameRight = isSameTree(p->right, q->right);

            if (isSameLeft && isSameRight) {
                return true;
            }
            return false;
        }
    }
};

int main() {
    // 设置二叉树
    TreeNode A(9);

    TreeNode B(71);
    TreeNode C(71);

    TreeNode D(79);
    TreeNode E(79);

    TreeNode F(-76);
    TreeNode G(-43);
    TreeNode H(-43);
    TreeNode I(-76);

    TreeNode J(-52);
    TreeNode K(21);
    TreeNode L(84);
    TreeNode M(-52);


    A.left = &B;
    A.right = &C;

    B.right = &D;
    C.left = &E;

    D.left = &F;
    D.right = &G;
    E.left = &H;
    E.right = &I;

    F.right = &J;
    G.left = &K;
    H.right = &L;
    I.left = &M;

    // Solution
    Solution sol;
    cout << sol.isSymmetric(&A) << endl;
}