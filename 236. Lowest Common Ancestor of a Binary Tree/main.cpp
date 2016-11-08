#include <frequently-used-code-snippets.h>

class Solution {
public:
    // 求 v, w 在以 root 为根节点的二叉树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode *root,
                                   TreeNode *v,
                                   TreeNode *w) {
        if (v == NULL || w == NULL) {
            return NULL;
        }

        // 第 1 步
        if (v == w) {
            return v;
        }

        // 第 2 步
        map<TreeNode*, TreeNode*> mapParents;
        fillMapParents(root, mapParents);   // 填充 map，不在 depth 函数里填充，避免重复计算hhh

        // 第 2.1 步
        int depthV = depth(root, v, mapParents);
        int depthW = depth(root, w, mapParents);

        // 第 2.2 步
        TreeNode *highNode;     // highNode 是深度较小的节点，在树中的位置较高
        TreeNode *lowNode;      // lowNode 是深度较大的节点，在树中的位置较低
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
        traverseUpward(lowNode, depthDiff, mapParents);

        // 第 2.4 步
        if (highNode == lowNode) {
            return highNode;
        }

        // 第 3 步
        while (highNode != lowNode) {
            traverseUpward(highNode, 1, mapParents);
            traverseUpward(lowNode, 1, mapParents);
        }
        return highNode;
    }

    // 填充 map，包含 root
    void fillMapParents(TreeNode *root,
                        map<TreeNode*, TreeNode*>& mapParents) {
        fillMapParentsWithoutRoot(root, mapParents);
        addToMap(mapParents, root, (TreeNode*) NULL);   // 给根节点加上父节点 NULL
    }

    // 填充 map，不包含 root
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
        // 利用 map 往上回溯，求出 node 的深度
        int depth = 1;  // root 深度为 1
        while (node != root) {
            node = mapParents.find(node)->second;
            depth++;
        }
        return depth;
    }

    void traverseUpward(TreeNode*& node,  // 注意这里使用 TreeNode*& 指针引用，如果使用 TreeNode*，只操作了形参，实参是不变的
                        int n,
                        map<TreeNode*, TreeNode*>& mapParents){
        cout << node->val << " 往上 " << n << " 层到达 ";
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
                cout << node->val << " 的父节点是 NULL" << endl;
            }
            else {
                cout << node->val << " 的父节点是 " << parent->val << endl;
            }
        }
        cout << endl;
    }

    void printAllNodesDepth(map<TreeNode*, TreeNode*>& mapParents,
                            TreeNode *root) {
        for (map<TreeNode*, TreeNode*>::iterator iter = mapParents.begin(); iter != mapParents.end(); iter++) {
            TreeNode *node = iter->first;
            int dep = depth(root, node, mapParents);
            cout << node->val << " 的深度为 " << dep << endl;
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

    // 测试 fillMapParents
    Solution sol;
    map<TreeNode*, TreeNode*> mapParents;
    sol.fillMapParents(&n6, mapParents);
    sol.printMapParents(mapParents);

    // 测试 depth
    sol.printAllNodesDepth(mapParents, &n6);

    // 测试 traverseUpward
    TreeNode* tempNode = &n2;
    sol.traverseUpward(tempNode, 1, mapParents);

    // 测试 lowestCommonAncestor
    TreeNode* v = &n2;
    TreeNode* w = &n4;
    TreeNode* lca = sol.lowestCommonAncestor(&n6, v, w);
    cout << endl << v->val << ", " << w->val << " 的 LCA 是 " << lca->val << endl << endl;

    v = &n2;
    w = &n8;
    lca = sol.lowestCommonAncestor(&n6, v, w);
    cout << endl << v->val << ", " << w->val << " 的 LCA 是 " << lca->val << endl << endl;

    return 0;
}