#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }

        // ��� root ��Ҷ�ӽڵ�
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }

        // �ж�������
        if (root->left != NULL) {
            bool hasLeftPathSum = hasPathSum(root->left, sum - root->val);
            if (hasLeftPathSum) {
                return true;
            }
        }

        // �ж�������
        if (root->right != NULL) {
            bool hasRightPathSum = hasPathSum(root->right, sum - root->val);
            if (hasRightPathSum) {
                return true;
            }
        }

        return false;
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
    cout << sol.hasPathSum(&A, 27) << endl;
    cout << sol.hasPathSum(&A, 22) << endl;
    cout << sol.hasPathSum(&A, 26) << endl;
    cout << sol.hasPathSum(&A, 18) << endl;
    cout << sol.hasPathSum(&A, 17) << endl;
    cout << sol.hasPathSum(&A, 19) << endl;
}