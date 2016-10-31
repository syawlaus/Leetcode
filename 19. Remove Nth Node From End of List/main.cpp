#include <frequently-used-code-snippets.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) {
            return NULL;
        }

        // prevHead ���ڼ�¼ head ����ڣ�ͳһ head �ͺ���ڵ�Ĳ�����ʹ�����нڵ㶼�� prev �ڵ�
        ListNode prevHeadNode(0);
        ListNode *prevHead = &prevHeadNode;
        prevHead->next = head;

        // ������������ź�ָ����ӵ� map ��
        map<int, ListNode*> orderMap;
        ListNode *tempNode = prevHead;
        int order = 1;
        while (tempNode != NULL) {
            addToMap(orderMap, order, tempNode);
            order++;
            tempNode = tempNode->next;
        }
        int length = order - 1;

        // ��ȡ��Ҫ�Ƴ��ĵ����� n ���ڵ��ָ��
        int removeOrder = length - n + 1;
        ListNode *removeNode = orderMap[removeOrder];

        // ���������� n+1 ���͵����� n-1 ���ڵ������
        ListNode *prevRemoveNode = orderMap[removeOrder - 1];
        ListNode *nextRemoveNode = removeNode->next;
        if (prevRemoveNode != NULL) {
            prevRemoveNode->next = nextRemoveNode;
        }

        // �Ƴ������� n ���ڵ�
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