#include <iostream>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }

        while (node->next != NULL) {
            // 用后一个结点的 val 覆盖当前 node 的 val
            node->val = node->next->val;

            // 如果当前 node 是倒数第二个结点
            if (node->next->next == NULL) {
                node->next = NULL;
                break;
            }

            // 往后移动当前 node
            node = node->next;
        }
    }
};

int main() {
    ListNode node0(0);
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    // 输出原链表
    printList(&node0);

    Solution sol;
    sol.deleteNode(&node2);

    // 输出结果链表
    printList(&node0);
}