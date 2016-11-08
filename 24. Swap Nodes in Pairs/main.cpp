#include <frequently-used-code-snippets.h>
using namespace std;

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

int main() {
    // ����һ
    Solution sol;
    int arr1[] = { 1 };
    ListNode* list1 = convertArrayToList(arr1, ARRAY_LENGTH(arr1));
    printList(sol.swapPairs(list1));

    // ���Զ�
    int arr2[] = { 1, 2, 3, 4 };
    ListNode* list2 = convertArrayToList(arr2, ARRAY_LENGTH(arr2));
    printList(sol.swapPairs(list2));

    // ������
    int arr3[] = { 1, 2, 3, 4, 5 };
    ListNode* list3 = convertArrayToList(arr3, ARRAY_LENGTH(arr3));
    printList(sol.swapPairs(list3));
}