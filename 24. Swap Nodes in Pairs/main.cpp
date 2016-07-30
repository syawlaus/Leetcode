#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        // �� head ǰ���һ�� traverseHead������ѭ��ʱ���� head ��ǰһ���ڵ�
        ListNode tempNode(INIT_VAL);
        ListNode* traverseHead = &tempNode;
        traverseHead->next = head;

        // �����������ս���������Ԫ��
        ListNode* retHead = traverseHead;

        while (head != NULL) {
            ListNode* first = head;
            ListNode* second = head->next;
            ListNode* third = NULL;
            if (second != NULL) {
                third = second->next;

                // ԭ����traverseHead -> first -> second -> third
                // ���� ��traverseHead -> second -> first -> third
                traverseHead->next = second;
                second->next = first;
                first->next = third;

                // second -> first (= traverseHead)
                traverseHead = first;

                // head ����һλ����Ϊ first = head������ first ������һλ������ head ֻ��Ҫ�ٺ���һλ���ɣ�
                head = head->next;
            }
            else {      // ����ĩ�ڵ�
                break;
            }
        }

        // ���� head
        return retHead->next;
    }

private:
    const int INIT_VAL = -1;
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

ListNode* convertArrayToList() {
    // �� arr תΪ list���������
    int arr[] = { 1, 2, 3, 4, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "arr len = " << len << endl;

    // �� vector ��������ָ��
    vector<ListNode*> nodes;
    for (int i = 0; i < len; i++) {
        ListNode* node = new ListNode(arr[i]);      // �½� ListNode*
        nodes.push_back(node);
    }

    // �� vector ����ָ�뽨�� ->next ��ϵ
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    return nodes[0];
}

int main() {
    Solution sol;
    ListNode* head = convertArrayToList();
    printList(sol.swapPairs(head));
}