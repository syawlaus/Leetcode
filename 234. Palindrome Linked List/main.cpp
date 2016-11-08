#include <frequently-used-code-snippets.h>

class Solution {
public:
    // O(n)-time, O(n)-space
    bool isPalindrome(ListNode *head) {
        // 保存链表元素值到 vector
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }

        // 判断 vector 是否回文
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

        // 计算中间节点
        ListNode *mid = findMiddleNode(head);

        // 反转后半段链表
        ListNode *reverseHead = reverseList(mid->next);

        // 连接前后两半段链表
        mid->next = reverseHead;

        // 比较前后两个半段链表
        // 注意：后半段链表节点个数 <= 前半段链表节点个数
        bool isPal = true;
        while (reverseHead != NULL) {
            if (head->val != reverseHead->val) {
                isPal = false;
            }
            head = head->next;
            reverseHead = reverseHead->next;
        }

        // 恢复原链表
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