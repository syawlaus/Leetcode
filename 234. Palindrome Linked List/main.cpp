#include <frequently-used-code-snippets.h>

class Solution {
public:
    // O(n)-time, O(n)-space
    bool isPalindrome(ListNode *head) {
        // ��������Ԫ��ֵ�� vector
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }

        // �ж� vector �Ƿ����
        for (int start = 0, end = v.size() - 1; start < end; start++, end--) {
            if (v[start] != v[end]) {
                return false;
            }
        }
        return true;
    }

    // O(n)-time, O(1)-space
    bool isPalindrome2(ListNode *head) {
        if (head == NULL) {
            return true;
        }

        // �����м�ڵ�
        ListNode *mid = findMiddleNode(head);

        // ��ת��������
        ListNode *reverseHead = reverseList(mid->next);

        // ����ǰ�����������
        mid->next = reverseHead;

        // �Ƚ�ǰ�������������
        // ע�⣺��������ڵ���� <= ǰ�������ڵ����
        bool isPal = true;
        while (reverseHead != NULL) {
            if (head->val != reverseHead->val) {
                isPal = false;
            }
            head = head->next;
            reverseHead = reverseHead->next;
        }

        // �ָ�ԭ����
        reverseHead = reverseList(mid->next);
        mid->next = reverseHead;

        return isPal;
    }
};

int main() {
    ListNode A(1);
    ListNode B(2);
    ListNode C(3);
    ListNode D(4);
    ListNode E(4);
    ListNode F(3);
    ListNode G(2);
    ListNode H(1);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;
    E.next = &F;
    F.next = &G;
    G.next = &H;

    Solution sol;
    cout << sol.isPalindrome2(&A) << endl;
}