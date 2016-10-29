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

        // ����������
        int leftMinDepth = NOT_LEAF_NODE;   // ��ֹ��ֻ�����ӽڵ�Ķ������� minDepth �ж�Ϊ 1����Ϊ������ minDepth Ϊ 0��
        if (root->left != NULL) {
            leftMinDepth = minDepth(root->left);
        }

        // ����������
        int rightMinDepth = NOT_LEAF_NODE;  // ��ֹ��ֻ�����ӽڵ�Ķ������� minDepth �ж�Ϊ 1����Ϊ������ minDepth Ϊ 0��
        if (root->right != NULL) {
            rightMinDepth = minDepth(root->right);
        }

        // ���أ�root ֻ��������
        if (leftMinDepth != NOT_LEAF_NODE && rightMinDepth == NOT_LEAF_NODE) {
            return leftMinDepth + 1;
        }
        // ���أ�root ֻ��������
        if (leftMinDepth == NOT_LEAF_NODE && rightMinDepth != NOT_LEAF_NODE) {
            return rightMinDepth + 1;
        }
        // ���أ�root ����������
        else {      // �� leftMinDepth != NOT_LEAF_NODE && rightMinDepth != NOT_LEAF_NODE
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