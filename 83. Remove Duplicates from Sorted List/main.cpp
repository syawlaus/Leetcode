#include <iostream>
#include <frequently-used-code-snippets.h>
using namespace std;

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
    printList(&n1);

    // solution
    Solution sol;
    sol.deleteDuplicates(&n1);
    printList(&n1);
}