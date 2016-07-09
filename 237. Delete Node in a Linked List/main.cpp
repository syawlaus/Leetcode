#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }

        while (node->next != NULL) {
            // �ú�һ������ val ���ǵ�ǰ node �� val
            node->val = node->next->val;

            // �����ǰ node �ǵ����ڶ������
            if (node->next->next == NULL) {
                node->next = NULL;
                break;
            }

            // �����ƶ���ǰ node
            node = node->next;
        }
    }
};

void printSingleLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << "address: " << head << endl;
        cout << "    val: " << head->val << endl;
        cout << "   next: " << head->next << endl;
        head = head->next;
    }
    cout << "-------------------" << endl;
}

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

    // ���ԭ����
    printSingleLinkedList(&node0);

    Solution sol;
    sol.deleteNode(&node0);

    // ����������
    printSingleLinkedList(&node0);
}