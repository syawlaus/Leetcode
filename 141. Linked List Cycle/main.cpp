#include <iostream>
#include <map>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    // O(n) �ռ临�Ӷ�
    //bool hasCycle(ListNode* head) {
    //    map<ListNode*, bool> mapp;
    //    while (head != NULL) {
    //        if (mapp.find(head) != mapp.end()) {  // head �Ѵ���
    //            return true;
    //        }
    //        mapp[head] = true;
    //        head = head->next;
    //    }
    //    return false;
    //}

    // O(1) �ռ临�Ӷ�
    bool hasCycle2(ListNode* head) {
        if (head == NULL) {
            return false;
        }

        ListNode* pi = head;
        ListNode* pi2 = head;
        while (true) {
            // pi  ǰ��һ��
            if (pi->next != NULL) {
                pi = pi->next;
            }
            else {
                return false;
            }

            // pi2 ǰ������
            if (pi2->next != NULL) {
                if (pi2->next->next != NULL) {
                    pi2 = pi2->next->next;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }

            // pi �� pi2 ����
            if (pi == pi2) {
                return true;
            }
        }
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
    n5.next = &n1;

    Solution sol;
    cout << sol.hasCycle2(&n1) << endl;
}