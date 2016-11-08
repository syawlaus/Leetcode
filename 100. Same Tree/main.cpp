#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }

        // 结构不同
        if (p != NULL && q == NULL) {
            return false;
        }

        // 结构不同
        if (p == NULL && q != NULL) {
            return false;
        }

        else {      // 即 p != NULL && q != NULL
            // 值不同
            if (p->val != q->val) {
                return false;
            }

            bool isSameLeft = isSameTree(p->left, q->left);
            bool isSameRight = isSameTree(p->right, q->right);

            if (isSameLeft && isSameRight) {
                return true;
            }
            return false;
        }
    }
};

int main() {

    // P 树
    //      1
    //     / \
    //   2     3
    //  / \   / \
    // 4   5 6   7

    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(6);
    TreeNode p7(7);

    p1.left  = &p2;
    p1.right = &p3;

    p2.left  = &p4;
    p2.right = &p5;

    p3.left  = &p6;
    p3.right = &p7;

    // Q 树
    //      1
    //     / \
    //   2     3
    //  / \   /
    // 4   5 6

    TreeNode q1(1);
    TreeNode q2(2);
    TreeNode q3(3);
    TreeNode q4(4);
    TreeNode q5(5);
    TreeNode q6(6);

    q1.left  = &q2;
    q1.right = &q3;

    q2.left  = &q4;
    q2.right = &q5;
    
    q3.left  = &q6;

    // 判断 P、Q 树是否相等
    Solution sol;
    bool isSame = sol.isSameTree(&p1, &q1);
    cout << isSame << endl;
}