#include <iostream>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // root Ϊ�ս��
        if (root == NULL) {
            return NULL;
        }

        // root ��Ҷ�ӽڵ�
        if (root->left == NULL &&
            root->right == NULL) {
            return root;
        }

        // ��ת������
        TreeNode* left = invertTree(root->left);

        // ��ת������
        TreeNode* right = invertTree(root->right);

        // ���������ӽ��
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // ���ظ����
        return root;
    }
};