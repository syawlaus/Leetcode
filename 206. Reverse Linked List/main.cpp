#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLinkedlist(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    // 方法一：反转指针
    //ListNode* reverseList(ListNode* head) {
    //    if (head == NULL) {
    //        return NULL;
    //    }

    //    // 把各个节点地址添加到 vector
    //    vector<ListNode*> nodes;
    //    nodes.push_back(NULL);  // 作为首元素在反转后的 *next
    //    while (head->next != NULL) {
    //        nodes.push_back(head);
    //        head = head->next;
    //    }

    //    // 此时 head->next == NULL，即是到达末尾元素
    //    ListNode* tail = head;  // 用来返回的
    //    for (int i = nodes.size() - 1; i >= 0; i--) {
    //        head->next = nodes[i];
    //        head = head->next;
    //    }

    //    return tail;
    //}

    // 方法一：反转值
    ListNode* reverseList2(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        // 遍历整个 Linkedlist，把各个节点的 val 保存到 vector
        vector<int> nodeVals;
        ListNode* tempHead = head;
        while (tempHead != NULL) {
            nodeVals.push_back(tempHead->val);
            tempHead = tempHead->next;
        }

        // 遍历一次 Linkedlist，把 vector 的 val 倒序赋值到各个节点
        tempHead = head;
        int lastIdx = nodeVals.size() - 1;
        while (tempHead != NULL) {
            tempHead->val = nodeVals[lastIdx];
            lastIdx--;
            tempHead = tempHead->next;
        }

        return head;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    printLinkedlist(&n1);

    Solution sol;
    ListNode* head;

    //head = sol.reverseList(&n1);
    //printLinkedlist(head);

    head = sol.reverseList2(&n1);
    printLinkedlist(head);
}