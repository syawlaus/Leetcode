#include <frequently-used-code-snippets.h>

class Solution {
public:
    // �� v, w ���� root Ϊ���ڵ�Ķ������������������
    TreeNode* lowestCommonAncestor(TreeNode *root,
                                   TreeNode *v,
                                   TreeNode *w) {
        if (v == NULL || w == NULL) {
            return NULL;
        }

        // �� 1 ��
        if (v == w) {
            return v;
        }

        // �� 2 ��
        map<TreeNode*, TreeNode*> mapParents;
        fillMapParents(root, mapParents);   // ��� map������ depth ��������䣬�����ظ�����hhh

        // �� 2.1 ��
        int depthV = depth(root, v, mapParents);
        int depthW = depth(root, w, mapParents);

        // �� 2.2 ��
        TreeNode *highNode;     // highNode ����Ƚ�С�Ľڵ㣬�����е�λ�ýϸ�
        TreeNode *lowNode;      // lowNode ����Ƚϴ�Ľڵ㣬�����е�λ�ýϵ�
        int depthDiff;

        if (depthV < depthW) {
            highNode = v;
            lowNode = w;
            depthDiff = depthW - depthV;
        }
        else {
            highNode = w;
            lowNode = v;
            depthDiff = depthV - depthW;
        }

        // �� 2.3 ��
        traverseUpward(lowNode, depthDiff, mapParents);

        // �� 2.4 ��
        if (highNode == lowNode) {
            return highNode;
        }

        // �� 3 ��
        while (highNode != lowNode) {
            traverseUpward(highNode, 1, mapParents);
            traverseUpward(lowNode, 1, mapParents);
        }
        return highNode;
    }

    // ��� map������ root
    void fillMapParents(TreeNode *root,
                        map<TreeNode*, TreeNode*>& mapParents) {
        fillMapParentsWithoutRoot(root, mapParents);
        addToMap(mapParents, root, (TreeNode*) NULL);   // �����ڵ���ϸ��ڵ� NULL
    }

    // ��� map�������� root
    void fillMapParentsWithoutRoot(TreeNode* root,
                                   map<TreeNode*, TreeNode*>& mapParents) {
        if (root == NULL) {
            return;
        }

        addToMap(mapParents, root->left, root);
        addToMap(mapParents, root->right, root);

        fillMapParentsWithoutRoot(root->left, mapParents);
        fillMapParentsWithoutRoot(root->right, mapParents);
    }

    int depth(TreeNode *root,
              TreeNode *node,
              map<TreeNode*, TreeNode*>& mapParents) {
        // ���� map ���ϻ��ݣ���� node �����
        int depth = 1;  // root ���Ϊ 1
        while (node != root) {
            node = mapParents.find(node)->second;
            depth++;
        }
        return depth;
    }

    void traverseUpward(TreeNode*& node,  // ע������ʹ�� TreeNode*& ָ�����ã����ʹ�� TreeNode*��ֻ�������βΣ�ʵ���ǲ����
                        int n,
                        map<TreeNode*, TreeNode*>& mapParents){
        cout << node->val << " ���� " << n << " �㵽�� ";
        for (int i = 0; i < n; i++) {
            node = mapParents.find(node)->second;
        }
        cout << node->val << endl;
    }

    void printMapParents(map<TreeNode*, TreeNode*>& mapParents) {
        for (map<TreeNode*, TreeNode*>::iterator iter = mapParents.begin(); iter != mapParents.end(); iter++) {
            TreeNode *node = iter->first;
            TreeNode *parent = iter->second;
            if (parent == NULL) {
                cout << node->val << " �ĸ��ڵ��� NULL" << endl;
            }
            else {
                cout << node->val << " �ĸ��ڵ��� " << parent->val << endl;
            }
        }
        cout << endl;
    }

    void printAllNodesDepth(map<TreeNode*, TreeNode*>& mapParents,
                            TreeNode *root) {
        for (map<TreeNode*, TreeNode*>::iterator iter = mapParents.begin(); iter != mapParents.end(); iter++) {
            TreeNode *node = iter->first;
            int dep = depth(root, node, mapParents);
            cout << node->val << " �����Ϊ " << dep << endl;
        }
        cout << endl;
    }
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

    n6.left = &n2;
    n6.right = &n8;

    n2.left = &n0;
    n2.right = &n4;

    n8.left = &n7;
    n8.right = &n9;

    n4.left = &n3;
    n4.right = &n5;

    // ���� fillMapParents
    Solution sol;
    map<TreeNode*, TreeNode*> mapParents;
    sol.fillMapParents(&n6, mapParents);
    sol.printMapParents(mapParents);

    // ���� depth
    sol.printAllNodesDepth(mapParents, &n6);

    // ���� traverseUpward
    TreeNode* tempNode = &n2;
    sol.traverseUpward(tempNode, 1, mapParents);

    // ���� lowestCommonAncestor
    TreeNode* v = &n2;
    TreeNode* w = &n4;
    TreeNode* lca = sol.lowestCommonAncestor(&n6, v, w);
    cout << endl << v->val << ", " << w->val << " �� LCA �� " << lca->val << endl << endl;

    v = &n2;
    w = &n8;
    lca = sol.lowestCommonAncestor(&n6, v, w);
    cout << endl << v->val << ", " << w->val << " �� LCA �� " << lca->val << endl << endl;

    return 0;
}