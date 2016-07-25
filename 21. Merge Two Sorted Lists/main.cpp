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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {

        if (h1 == NULL && h2 == NULL) {
            return NULL;
        }

        ListNode* L = new ListNode(INIT_VAL);   // 实例化 ListNode 对象
        ListNode* head = L;

        // 合并 h1 和 h2 到 L
        while (true) {
            if (h1 == NULL || h2 == NULL) {
                break;
            }

            int val1 = h1->val;
            int val2 = h2->val;

            if (val1 < val2) {
                L->val = val1;
                h1 = h1->next;
            }
            else {
                L->val = val2;
                h2 = h2->next;
            }
            newListNodeAndMoveForward(L);
        }

        // 添加 h2 剩余元素到 L
        if (h1 == NULL) {
            addRemaining(h2, L);
        }
        // 添加 h1 剩余元素到 L
        else {      // 即 h2 == NULL
            addRemaining(h1, L);
        }

        return head;
    }

private:
    int INIT_VAL = -1;

    void newListNodeAndMoveForward(ListNode*& L) {
        ListNode* nextNode = new ListNode(INIT_VAL);
        L->next = nextNode;
        L = L->next;
    }

    void addRemaining(ListNode*& h, ListNode*& L) {
        while (h != NULL) {
            L->val = h->val;
            h = h->next;
            if (h != NULL) {   // 下一个节点不为 NULL 时才 new ListNode
                newListNodeAndMoveForward(L);
            }
        }
    }
};

void printList(ListNode* h) {
    while (h != NULL) {
        cout << h->val << ' ';
        h = h->next;
    }
    cout << endl;
}

int main() {
    // h1
    ListNode n1(1);
    ListNode n2(2);
    ListNode n4(4);
    ListNode n6(6);
    ListNode n8(8);

    n1.next = &n2;
    n2.next = &n4;
    n4.next = &n6;
    n6.next = &n8;

    printList(&n1);

    // h2
    ListNode n0(0);
    ListNode n3(3);
    ListNode n5(5);
    ListNode n7(7);
    ListNode n9(9);

    n0.next = &n3;
    n3.next = &n5;
    n5.next = &n7;
    n7.next = &n9;

    printList(&n0);

    // merge h1, h2
    Solution sol;
    ListNode* L = sol.mergeTwoLists(&n1, &n0);
    printList(L);
}