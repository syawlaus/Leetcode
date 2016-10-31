#include <frequently-used-code-snippets.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) {
            return NULL;
        }

        // prevHead 用于记录 head 的入口，统一 head 和后面节点的操作，使得所有节点都有 prev 节点
        ListNode prevHeadNode(0);
        ListNode *prevHead = &prevHeadNode;
        prevHead->next = head;

        // 遍历链表，把序号和指针添加到 map 中
        map<int, ListNode*> orderMap;
        ListNode *tempNode = prevHead;
        int order = 1;
        while (tempNode != NULL) {
            addToMap(orderMap, order, tempNode);
            order++;
            tempNode = tempNode->next;
        }
        int length = order - 1;

        // 获取需要移除的倒数第 n 个节点的指针
        int removeOrder = length - n + 1;
        ListNode *removeNode = orderMap[removeOrder];

        // 建立倒数第 n+1 个和倒数第 n-1 个节点的连接
        ListNode *prevRemoveNode = orderMap[removeOrder - 1];
        ListNode *nextRemoveNode = removeNode->next;
        if (prevRemoveNode != NULL) {
            prevRemoveNode->next = nextRemoveNode;
        }

        // 移除倒数第 n 个节点
        removeNode = NULL;

        return prevHead->next;
    }
};

int main() {
    ListNode A(1);
    ListNode B(2);
    ListNode C(3);
    ListNode D(4);
    ListNode E(5);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;

    Solution sol;
    ListNode *head = sol.removeNthFromEnd(&A, 2);
    printList(head);
}