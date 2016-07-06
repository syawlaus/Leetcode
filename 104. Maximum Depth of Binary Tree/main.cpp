#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // root Ϊ�ս��
        if (root == NULL) {
            return 0;
        }

        // root ��Ҷ�ӽڵ�
        if (root->left == NULL &&
            root->right == NULL) {
            return 1;
        }

        // ���� root ���������
        int leftMaxDepth = maxDepth(root->left);

        // ���� root ���������
        int rightMaxDepth = maxDepth(root->right);

        // �Ե�ǰ�ڵ�Ϊ���ڵ������������ = max(��ǰ�ڵ��������������, ��ǰ�ڵ��������������) + 1
        return (leftMaxDepth >= rightMaxDepth) ? (leftMaxDepth + 1) : (rightMaxDepth + 1);
    }
};

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);

    node1.left = &node2;
    node1.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.left = &node6;
    node3.right = &node7;

    node4.left = &node8;

    Solution sol;
    int maxDepth = sol.maxDepth(&node1);
    cout << maxDepth << endl;
}