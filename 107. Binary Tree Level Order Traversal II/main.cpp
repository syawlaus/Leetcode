#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // ��ʼ��
        vector<vector<int>> vv;
        if (root == NULL)
            return vv;

        vector<TreeNode *> queue;
        vector<int> qLevel;

        queue.push_back(root);
        qLevel.push_back(1);

        // ѭ������ queue �� qLevel
        for (int i = 0; i < queue.size(); i++)
        {
            TreeNode *node = queue[i];
            if (node->left != NULL)
            {
                queue.push_back(node->left);
                qLevel.push_back(qLevel[i] + 1);
            }
            if (node->right != NULL)
            {
                queue.push_back(node->right);
                qLevel.push_back(qLevel[i] + 1);
            }
        }

        // ���� queue �� qLevel ������ vv
        qLevel.insert(qLevel.begin(), 0);   // ͷ���� sentinel Ԫ�أ�����ͳһѭ��
        for (int i = 0; i < queue.size(); i++)
        {
            if (qLevel[i] < qLevel[i + 1])  // �� sentinel Ԫ�غ�����жϾͿ���ͳһ
            {
                vector<int> vNewLevel;
                vv.push_back(vNewLevel);
            }
            vv[vv.size() - 1].push_back(queue[i]->val);
        }

        // ��ת vv
        vector<vector<int>> reverseVv;
        for (int i = vv.size() - 1; i >= 0; i--)
        {
            reverseVv.push_back(vv[i]);
        }

        return reverseVv;
    }

    void BFS(TreeNode *root)
    {
        vector<TreeNode *> queue;
        queue.push_back(root);
        int index = 0;
        while (index < queue.size())
        {
            TreeNode *node = queue[index];
            index++;
            cout << node->val << ' ';

            if (node->left != NULL)
                queue.push_back(node->left);

            if (node->right != NULL)
                queue.push_back(node->right);
        }
    }
};

int main() {
    // ���ö�����
    TreeNode node3(3);
    TreeNode node9(9);
    TreeNode node20(20);
    TreeNode node15(15);
    TreeNode node7(7);

    node3.left = &node9;
    node3.right = &node20;

    node20.left = &node15;
    node20.right = &node7;

    // Solution
    Solution sol;
    vector<vector<int>> vv = sol.levelOrderBottom(&node3);
}