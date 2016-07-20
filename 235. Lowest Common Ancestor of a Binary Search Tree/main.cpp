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

        // 第 1 步
        if (v == w) {
            return v;
        }

        // 第 2 步
        map<TreeNode*, TreeNode*> mapParents;
        fillMapParents(root, mapParents);   // 生成 map
        addToMap(root, NULL, mapParents);   // 给根节点加上父节点 NULL

        // 第 2.1 步
        int depthV = depth(root, v, mapParents);
        int depthW = depth(root, w, mapParents);

        // 第 2.2 步
        TreeNode* highNode;     // highNode 是深度较小的节点，在树中的位置较高
        TreeNode* lowNode;      //  lowNode 是深度较大的节点，在树中的位置较低
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

        // 第 2.3 步
        lowNode = traverseUpward(lowNode, depthDiff, mapParents);

        // 第 2.4 步
        if (highNode == lowNode) {
            return highNode;
        }

        // 第 3 步
        while (highNode != lowNode) {
            highNode = traverseUpward(highNode, 1, mapParents);
            lowNode = traverseUpward(lowNode, 1, mapParents);
        }
        return highNode;
    }

    int depth(TreeNode* root,
              TreeNode* node,
              map<TreeNode*, TreeNode*>& mapParents) {
        // 利用 map 往上回溯，求出 node 的深度
        int depth = 1;  // root 深度为 1
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
        cout << node->val << " 往上 " << n << " 层到达 ";
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
        cout << node->val << " 的父节点是 " << parent->val << endl;
    }
    cout << endl;
}

void printAllNodesDepth(map<TreeNode*, TreeNode*>& mapParents,
                        TreeNode* root,
                        Solution sol) {
    for (map<TreeNode*, TreeNode*>::iterator iter = mapParents.begin(); iter != mapParents.end(); iter++) {
        TreeNode* node = iter->first;
        int depth = sol.depth(root, node, mapParents);
        cout << node->val << " 的深度为 " << depth << endl;
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

    // 测试 fillMapParents
    Solution sol;
    map<TreeNode*, TreeNode*> mapParents;
    sol.fillMapParents(&n6, mapParents);
    printMapParents(mapParents);

    // 测试 depth
    printAllNodesDepth(mapParents, &n6, sol);
    
    // 测试 traverseUpward
    sol.traverseUpward(&n2, 1, mapParents);
    
    // 测试 lowestCommonAncestor
    TreeNode* v = &n2;
    TreeNode* w = &n4;
    TreeNode* lca = sol.lowestCommonAncestor(&n6, v, w);
    cout << endl << v->val << ", " << w->val << " 的 LCA 是 " << lca->val << endl;

    return 0;
}