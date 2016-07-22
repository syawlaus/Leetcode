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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                if (temp->val == temp->next->val) {
                    temp->next = temp->next->next;

                    // 清空重复元素占用的内存
                }
                else {
                    temp = temp->next;
                }
            }
            else {
                return head;
            }
        }
        return head;
    }
};

void printLinkedlist(ListNode* head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main() {
    // init data
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(1);
    ListNode n4(1);
    ListNode n5(1);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    printLinkedlist(&n1);

    // solution
    Solution sol;
    sol.deleteDuplicates(&n1);
    printLinkedlist(&n1);
}