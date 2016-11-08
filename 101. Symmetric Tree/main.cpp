#include <frequently-used-code-snippets.h>
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
};

int main() {
    // ÉèÖÃ¶þ²æÊ÷
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