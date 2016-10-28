#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        // �ж��������Ƿ�ƽ��
        bool isLeftBalanced = isBalanced(root->left);
        if (! isLeftBalanced) {
            return false;
        }

        // �ж��������Ƿ�ƽ��
        bool isRightBalanced = isBalanced(root->right);
        if (! isRightBalanced) {
            return false;
        }

        // ����������ƽ�⣬�ж����߸߶Ȳ��Ƿ񲻴��� 1
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return (abs(leftHeight - rightHeight) <= 1);
    }

private:
    int getHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        return MAX_TWO(leftHeight, rightHeight) + 1;
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
    cout << sol.isBalanced(&A);
}