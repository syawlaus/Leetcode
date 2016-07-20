#include <iostream>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* v,
                                   TreeNode* w) {
        if (v == NULL || w == NULL) {
            return NULL;
        }

        // �� 1 ��
        if (v == w) {
            return v;
        }

        // �� 2 ��
        map<TreeNode*, TreeNode*> mapParents;
        fillMapParents(root, mapParents);   // ���� map
        addToMap(root, NULL, mapParents);   // �����ڵ���ϸ��ڵ� NULL

        // �� 2.1 ��
        int depthV = depth(root, v, mapParents);
        int depthW = depth(root, w, mapParents);

        // �� 2.2 ��
        TreeNode* highNode;     // highNode ����Ƚ�С�Ľڵ㣬�����е�λ�ýϸ�
        TreeNode* lowNode;      //  lowNode ����Ƚϴ�Ľڵ㣬�����е�λ�ýϵ�
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
        lowNode = traverseUpward(lowNode, depthDiff, mapParents);

        // �� 2.4 ��
        if (highNode == lowNode) {
            return highNode;
        }

        // �� 3 ��
        while (highNode != lowNode) {
            highNode = traverseUpward(highNode, 1, mapParents);
            lowNode = traverseUpward(lowNode, 1, mapParents);
        }
        return highNode;
    }

    int depth(TreeNode* root,
              TreeNode* node,
              map<TreeNode*, TreeNode*>& mapParents) {
        // ���� map ���ϻ��ݣ���� node �����
        int depth = 1;  // root ���Ϊ 1
        while (node != root) {
            node = mapParents.find(node)->second;
            depth++;
        }
        return depth;
    }

    void fillMapParents(TreeNode* root,
                        map<TreeNode*, TreeNode*>& mapParents) {
        if (root == NULL) {
            return;
        }

        addToMap(root->left, root, mapParents);
        addToMap(root->right, root, mapParents);

        fillMapParents(root->left, mapParents);
        fillMapParents(root->right, mapParents);
    }

    void addToMap(TreeNode* keyNode,
                  TreeNode* valNode,
                  map<TreeNode*, TreeNode*>& mapParents) {
        if (keyNode == NULL) {
            return;
        }
        if (mapParents.find(keyNode) == mapParents.end()) {
            mapParents.insert(pair<TreeNode*, TreeNode*>(keyNode, valNode));
        }
    }

    TreeNode* traverseUpward(TreeNode* node,
                        int n,
                        map<TreeNode*, TreeNode*>& mapParents){
        cout << node->val << " ���� " << n << " �㵽�� ";
        for (int i = 0; i < n; i++) {
            node = mapParents.find(node)->second;
        }
        cout << node->val << endl;
        return node;
    }
};

void printMapParents(map<TreeNode*, TreeNode*>& mapParents) {
    for (map<TreeNode*, TreeNode*>::iterator iter = mapParents.begin(); iter != mapParents.end(); iter++) {
        TreeNode* node = iter->first;
        TreeNode* parent = iter->second;
        cout << node->val << " �ĸ��ڵ��� " << parent->val << endl;
    }
    cout << endl;
}

void printAllNodesDepth(map<TreeNode*, TreeNode*>& mapParents,
                        TreeNode* root,
                        Solution sol) {
    for (map<TreeNode*, TreeNode*>::iterator iter = mapParents.begin(); iter != mapParents.end(); iter++) {
        TreeNode* node = iter->first;
        int depth = sol.depth(root, node, mapParents);
        cout << node->val << " �����Ϊ " << depth << endl;
    }
    cout << endl;
}

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

    // ���� fillMapParents
    Solution sol;
    map<TreeNode*, TreeNode*> mapParents;
    sol.fillMapParents(&n6, mapParents);
    printMapParents(mapParents);

    // ���� depth
    printAllNodesDepth(mapParents, &n6, sol);
    
    // ���� traverseUpward
    sol.traverseUpward(&n2, 1, mapParents);
    
    // ���� lowestCommonAncestor
    TreeNode* v = &n2;
    TreeNode* w = &n4;
    TreeNode* lca = sol.lowestCommonAncestor(&n6, v, w);
    cout << endl << v->val << ", " << w->val << " �� LCA �� " << lca->val << endl;

    return 0;
}